import torch
import torch.nn as nn
import torchvision.models as models
import torch.nn.functional as F
from model.backbone.resnet18 import DummyResnet18

class DummyOccupancyDetector(nn.Module):
  def __init__(self, cam_num, occ_size, class_num):
    super(DummyOccupancyDetector, self).__init__()
    self.cam_num = cam_num
    self.occ_size = occ_size
    self.class_num = class_num
    # Shared ResNet backbone for all cameras
    self.backbone = DummyResnet18()  
    for param in self.backbone.parameters():
      param.requires_grad = False
    # Fusion network to combine features from all cameras
    # self.fusion_net = nn.Sequential(
    #   nn.Linear(self.backbone.fc.out_features * cam_num, 512),
    #   nn.ReLU(),
    #   nn.Dropout(0.5),
    #   nn.Linear(512, 256),
    #   nn.ReLU(),
    #   nn.Dropout(0.3),
    #   nn.Linear(256, occ_size[0]*occ_size[1]*occ_size[2]*class_num),
    #   nn.Sigmoid()
    # )
    self.fusion_net = nn.Sequential(
      nn.Linear(self.backbone.fc.out_features * cam_num, 8),
      nn.Linear(8, occ_size[0]*occ_size[1]*occ_size[2]*class_num),
      nn.Sigmoid()
    )
    
  def forward(self, x):
    # x shape: (batch_size, 6, 3, 224, 224)
    batch_size, num_cameras = x.shape[0], x.shape[1]
    # Process each camera view through the shared backbone
    camera_features = []
    for cam_idx in range(num_cameras):
      # Get features for this camera
      cam_view = x[:, cam_idx]  # (batch_size, 3, 224, 224)
      features = self.backbone(cam_view)  # (batch_size, feature_dim, 1, 1)
      features = features.view(features.size(0), -1)  # (batch_size, feature_dim)
      # Process through camera-specific branch
      camera_features.append(features)
    # Concatenate features from all cameras
    fused_features = torch.cat(camera_features, dim=1)
    # Final classification
    output = self.fusion_net(fused_features).view(-1,self.class_num,*self.occ_size)
    
    return output