import torch.nn as nn

class Loss(nn.Module):
  def __init__(self, cam_num, occ_size, class_num):
    super(Loss, self).__init__()
  def forward(self, x, label):
    