import numpy as np 
from nuscenes.nuscenes import NuScenes
from nuscenes.utils import splits
from pyquaternion import Quaternion
import open3d as o3d 
from scipy.spatial import KDTree
import os
import json

class GTGenerator:
  def __init__(self, nusc):
    self.nusc = nusc
    self.voxel_size = 0.2
    self.grid_size = np.array([200,200,16])
    self.points_per_voxel = 5

  def get_lidar_data_for_sample(self, sample_token):
    sample = self.nusc.get('sample', sample_token)
    lidar_data = self.nusc.get('sample_data', sample['data']['LIDAR_TOP'])
    lidar_pc = self.nusc.get_sample_data_path(lidar_data['token'])
    points = np.fromfile(lidar_pc, dtype = np.float32).reshape(-1,5)[:,:3]

    ego_pose=self.nusc.get('ego_pose', lidar_data['ego_pose_token'])
    rotation=Quaternion(ego_pose['rotation']).rotation_matrix
    translation=np.array(ego_pose['translation'])

    points_global = np.dot(points, rotation.T) + translation

    return points_global, ego_pose

  def separate_dynamic_static_points(self, points_global, sample_token):
    sample = self.nusc.get('sample', sample_token)
    ann_tokens = sample['anns']
    dynamic_mask = np.zeros(len(points_global), dtype=bool)

    for ann_token in ann_tokens:
      ann = self.nusc.get('sample_annotation', ann_token)
      box_center = np.array(ann['translation'])
      box_wlh    = np.array(ann['size'])
      box_rotation = Quaternion(ann['rotation']).rotation_matrix

      trans = -box_center
      rot   = box_rotation.T

      points_local = np.dot(points_global + trans, rot)

      half_size = box_wlh / 2.0
      inside_box = np.all(np.abs(points_local) < half_size, axis=1)
      dynamic_mask |= inside_box

    dynamic_points = points_global[dynamic_mask]
    static_points  = points_global[~dynamic_mask]
    return dynamic_points, static_points

  def accumulate_pointclouds(self, scene_token, frame_num):
    scene = self.nusc.get('scene', scene_token)
    current_sample_token = scene['first_sample_token']
    all_dynamic_points = []
    all_static_points  = []
    sample_tokens      = []

    frame_count = 0
    while current_sample_token and frame_count < frame_num:
      points_global, _ = self.get_lidar_data_for_sample(current_sample_token)
      dynamic_points, static_points = self.separate_dynamic_static_points(points_global, current_sample_token)
      all_dynamic_points.append(dynamic_points)
      all_static_points.append(static_points)
      sample_tokens.append(current_sample_token)
      current_sample = self.nusc.get('sample', current_sample_token)
      current_sample_token = current_sample['next']
      frame_count += 1

    accumulate_dynamic = np.concatenate(all_dynamic_points, axis=0)
    accumulate_static  = np.concatenate(all_static_points, axis=0)

    return accumulate_dynamic, accumulate_static, sample_tokens

  def poisson_reconstruction(self, points):
    pcd = o3d.geometry.PointCloud()
    pcd.points = o3d.utility.Vector3dVector(points)

    pcd.estimate_normals(search_param=o3d.geometry.KDTreeSearchParamHybrid(radius=self.voxel_size*2, max_nn=30))
    mesh, _ = o3d.geometry.TriangleMesh.create_from_point_cloud_poisson(pcd, depth=9, width=0, scale=1.1, linear_fit=False, n_threads=1)
    return mesh

  def voxelize_mesh(self, mesh):
    bbox = mesh.get_axis_aligned_bounding_box()

    voxel_grid = o3d.geometry.VoxelGrid.create_from_triangle_mesh_within_bounds(mesh, voxel_size=self.voxel_size, min_bound=bbox.min_bound, max_bound=bbox.max_bound)
    occupancy_grid = np.zeros(self.grid_size, dtype=bool)

    for voxel in voxel_grid.get_voxels():
      grid_index = voxel.grid_index
      if np.all(grid_index >= 0) and np.all(grid_index < self.grid_size):
        occupancy_grid[grid_index[0], grid_index[1], grid_index[2]] = True

    return occupancy_grid

  def generate_gt_for_scene(self, scene_token):
    print(f"processing scene: {scene_token}")
    dynamic_pc, static_pc, sample_tokens = self.accumulate_pointclouds(scene_token, frame_num=10)
    combined_pc = np.concatenate([dynamic_pc, static_pc], axis=0)
    reconstructed_mesh = self.poisson_reconstruction(combined_pc)
    occupancy_gt = self.voxelize_mesh(reconstructed_mesh)
    return occupancy_gt, sample_tokens

  def generate_gt_and_save(self, output_dir, metadata_path):
    scene_tokens = [scene['token'] for scene in nusc.scene]
    meta_datas   = []
    for scene_token in scene_tokens:
      occupancy_gt, sample_tokens = self.generate_gt_for_scene(scene_token)
      os.makedirs(output_dir, exist_ok=True)
      occupancy_path = os.path.join(output_dir, f"{scene_token}_occupancy.npy")
      np.save(occupancy_path, occupancy_gt.astype(np.bool_))
      meta_data = {
        "scene_token" : scene_token,
        "sample_tokens" : sample_tokens,
        "occupancy" : f"{scene_token}_occupancy.npy",
      }
      meta_datas.append(meta_data)
    with open(metadata_path, 'w') as f:
      json.dump(meta_datas, f, indent=4)
      



if __name__ == "__main__":
  nusc = NuScenes(version="v1.0-mini",dataroot="data/set/nuscenes/v1.0-mini",verbose=True)
  gt_generator = GTGenerator(nusc)
  gt_generator.generate_gt_and_save("data/set/nuscenes/v1.0-mini/occ", "data/set/nuscenes/v1.0-mini/v1.0-mini/occ_meta.json")
  print("Done!")
