import torch.nn as nn
import torch
import torch.nn.functional as F

class DummyLoss(nn.Module):
  def __init__(self, cam_num, occ_size, class_num):
    super(DummyLoss, self).__init__()
    self.cam_num = cam_num
    self.occ_size = occ_size
    self.class_num = class_num
    self.criterion = nn.CrossEntropyLoss()
  def forward(self, pred, label):
    loss = self.criterion(pred.view(-1,pred.shape[-1]),label.long().view(-1))
    return loss
    
    