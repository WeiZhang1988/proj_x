from dataset import OccupancyDataset
from model import OccupancyDetector
from torch.utils.data import Dataset, DataLoader
import torch.optim as optim
import torch

device = torch.device('cuda' if torch.cuda.is_available() else 'cpu')

model = OccupancyDetector(6, (200,200,16), 16)
model = model.to(device)

dataset = OccupancyDataset(img_dir_list=["data/set/nuscenes/samples/CAM_FRONT",
                                         "data/set/nuscenes/samples/CAM_FRONT_RIGHT",
                                         "data/set/nuscenes/samples/CAM_BACK_RIGHT",
                                         "data/set/nuscenes/samples/CAM_BACK",
                                         "data/set/nuscenes/samples/CAM_BACK_LEFT",
                                         "data/set/nuscenes/samples/CAM_FRONT_LEFT"], 
                           gt_dir="data/set/nuscenes/occupancy_gt")
dataloader = DataLoader(dataset, batch_size=8, shuffle=True)

# # Loss and optimizer
# criterion = nn.CrossEntropyLoss()
# optimizer = optim.Adam(model.parameters(), lr=0.001)

# # Training loop
# num_epochs = 10
# for epoch in range(num_epochs):
#   model.train()
#   running_loss = 0.0
   
#   for batch_idx, (images, labels) in enumerate(dataloader):
#     images = images.to(device)
#     labels = labels.to(device)
    
#     # Forward pass
#     outputs = model(images)
#     loss = criterion(outputs, labels)
    
#     # Backward and optimize
#     optimizer.zero_grad()
#     loss.backward()
#     optimizer.step()
    
#     running_loss += loss.item()
    
#     if (batch_idx + 1) % 10 == 0:
#         print(f'Epoch [{epoch+1}/{num_epochs}], Step [{batch_idx+1}], Loss: {loss.item():.4f}')

#   print(f'Epoch [{epoch+1}/{num_epochs}], Average Loss: {running_loss/len(dataloader):.4f}')

# # Save model
# torch.save(model.state_dict(), 'multi_camera_occupancy_detector.pth')
# print("Model saved!")