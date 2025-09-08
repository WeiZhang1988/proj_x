from dataset import OccupancyDataset
from model import DummyOccupancyDetector
from loss import DummyLoss
from torch.utils.data import Dataset, DataLoader
import os
import torch.optim as optim
import torch
import torchvision.transforms as transforms

device = torch.device('cuda' if torch.cuda.is_available() else 'cpu')
device = 'cpu'

def main(args, config, device):
  cam_num = len(config['cam_list'])
  occ_size = config['occ_size']
  class_num = config['class_num']
  model = DummyOccupancyDetector(cam_num, occ_size, class_num)
  model = model.to(device)
  criterion = DummyLoss(cam_num, occ_size, class_num)
  transform = transforms.Compose([transforms.Resize((224, 224)),
                                  transforms.ToTensor(),
                                  transforms.Normalize(mean=[0.485, 0.456, 0.406], std=[0.229, 0.224, 0.225])])
  dataset = OccupancyDataset(img_dir_list=[os.path.join(args.image_path, cam) for cam in config['cam_list']], 
                             gt_dir=args.gt_path,
                             occ_size=occ_size,
                             transform = transform)
  dataloader = DataLoader(dataset, batch_size=config['batch_size'], shuffle=True)
  optimizer = optim.Adam(model.parameters(), lr=config['learning_rate'])
  epoch_num = config['epoch_num']
  for epoch in range(epoch_num):
    model.train()
    criterion.eval()
    running_loss = 0.0
   
    for batch_idx, (images, labels) in enumerate(dataloader):
      images = images.to(device)
      labels = labels.to(device)
      outputs = model(images)
      loss = criterion(outputs, labels)
      optimizer.zero_grad()
      loss.backward()
      optimizer.step()
      running_loss += loss.item()
      if (batch_idx + 1) % 10 == 0:
        print(f'Epoch [{epoch+1}/{epoch_num}], Step [{batch_idx+1}], Loss: {loss.item():.4f}')
    print(f'Epoch [{epoch+1}/{epoch_num}], Average Loss: {running_loss/len(dataloader):.4f}')
    torch.save(model.state_dict(), os.path.join(args.checkpoint,'occupancy_detector.pth'))
    print("Model saved as 'occupancy_detector.pth'")


if __name__ == '__main__':
  import yaml
  from argparse import ArgumentParser
  parse = ArgumentParser()

  parse.add_argument('--config_path', type=str, default='config/config.yaml')
  parse.add_argument('--image_path', type=str, default='data/set/nuscenes/samples/')
  parse.add_argument('--gt_path', type=str, default='data/set/nuscenes/occupancy_gt/')
  parse.add_argument('--checkpoint', type=str, default='checkpoint/')
  args=parse.parse_args()

  # load config
  with open(args.config_path, 'r') as stream:
    config = yaml.safe_load(stream)

  main(args=args, config=config, device=device)