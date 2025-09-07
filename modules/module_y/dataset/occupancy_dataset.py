from torch.utils.data import Dataset
from PIL import Image
import torch
import numpy as np
import os

class OccupancyDataset(Dataset):
  def __init__(self, img_dir_list, gt_dir, occ_size, transform=None):
    self.img_dir_list = img_dir_list
    self.gt_dir = gt_dir
    self.occ_size = occ_size
    self.transform = transform
    self.img_names_list = [os.listdir(img_dir) for img_dir in self.img_dir_list]

  def __len__(self):
    return len(self.img_names_list[0])

  def __getitem__(self, idx):
    img_path_list = [os.path.join(img_dir, os.listdir(img_dir)[idx]) for img_dir in self.img_dir_list]
    image_list = [Image.open(img_path).convert('RGB') for img_path in img_path_list]
    gt = np.load(os.path.join(self.gt_dir, os.listdir(self.gt_dir)[idx]))
    if self.transform:
      image_list = [self.transform(img) for img in image_list]
    image_out = torch.stack(image_list, dim=0)
    gt = torch.tensor(gt)
    dense_gt = torch.zeros(self.occ_size, dtype=torch.float32)
    if len(gt) > 0:
      z_coords = gt[:, 0].long()
      y_coords = gt[:, 1].long()
      x_coords = gt[:, 2].long()
      dense_gt[z_coords, y_coords, x_coords] = gt[:, 3].float()

    return image_out, dense_gt