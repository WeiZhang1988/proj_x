from dataset import OccupancyDataset
from model import DummyOccupancyDetector
from loss import DummyLoss
from torch.utils.data import Dataset, DataLoader
import torch.optim as optim
import torch
import torchvision.transforms as transforms

device = torch.device('cuda' if torch.cuda.is_available() else 'cpu')
device = 'cpu'

model = DummyOccupancyDetector(2, (200,200,16), 17)
model = model.to(device)
criterion = DummyLoss(2, (200,200,16), 17)

transform = transforms.Compose([transforms.Resize((224, 224)),
                                transforms.ToTensor(),
                                transforms.Normalize(mean=[0.485, 0.456, 0.406], std=[0.229, 0.224, 0.225])])

dataset = OccupancyDataset(img_dir_list=["data/set/nuscenes/samples/CAM_FRONT",
                                         #"data/set/nuscenes/samples/CAM_FRONT_RIGHT",
                                         #"data/set/nuscenes/samples/CAM_BACK_RIGHT",
                                         "data/set/nuscenes/samples/CAM_BACK",
                                         #"data/set/nuscenes/samples/CAM_BACK_LEFT",
                                         #"data/set/nuscenes/samples/CAM_FRONT_LEFT"
                                         ], 
                           gt_dir="data/set/nuscenes/occupancy_gt",
                           occ_size=(200,200,16),
                           transform = transform)

dataloader = DataLoader(dataset, batch_size=1, shuffle=True)

optimizer = optim.Adam(model.parameters(), lr=0.01)

# Training loop
num_epochs = 10
for epoch in range(num_epochs):
  model.train()
  criterion.eval()
  running_loss = 0.0
   
  for batch_idx, (images, labels) in enumerate(dataloader):
    images = images.to(device)
    labels = labels.to(device)
    
    # Forward pass
    outputs = model(images)
    loss = criterion(outputs, labels)
    
    # Backward and optimize
    optimizer.zero_grad()
    loss.backward()
    optimizer.step()
    
    running_loss += loss.item()
    
    if (batch_idx + 1) % 10 == 0:
        print(f'Epoch [{epoch+1}/{num_epochs}], Step [{batch_idx+1}], Loss: {loss.item():.4f}')

  print(f'Epoch [{epoch+1}/{num_epochs}], Average Loss: {running_loss/len(dataloader):.4f}')