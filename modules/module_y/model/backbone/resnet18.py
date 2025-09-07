import torch
import torch.nn as nn

class DummyResnet18(nn.Module):
  def __init__(self, class_num=1000):
    super(DummyResnet18, self).__init__()
    # Same input: 3 channels, 224x224
    # Same output: 1000 classes (ImageNet)
    
    # Single convolutional layer (massively simplified)
    self.conv = nn.Conv2d(3, 64, kernel_size=7, stride=2, padding=3, bias=False)
    self.bn = nn.BatchNorm2d(64)
    self.relu = nn.ReLU(inplace=True)
    self.pool = nn.AdaptiveAvgPool2d((1, 1))
    
    # Final fully connected layer
    self.fc = nn.Linear(64, class_num)
    
  def forward(self, x):
    # Input: [batch, 3, 224, 224]
    x = self.conv(x)    # -> [batch, 64, 112, 112]
    x = self.bn(x)
    x = self.relu(x)
    x = self.pool(x)    # -> [batch, 64, 1, 1]
    x = x.view(x.size(0), -1)  # -> [batch, 64]
    x = self.fc(x)      # -> [batch, 1000]
    return x