
import os
import numpy as np
import matplotlib.pyplot as plt 

def main(args):
  path = args.gt_path
  for item in os.listdir(path):
    file = os.path.join(path, item)
    pc = np.load(file)
    print("gt shape: ", pc.shape)
    fig = plt.figure(figsize=(10,8))
    ax = fig.add_subplot(111,projection='3d')
    ax.view_init(elev=90,azim=0)
    x = pc[:,0]
    y = pc[:,1]
    z = pc[:,2]
    l = pc[:,3]
    scatter = ax.scatter(x,y,z,c=l,cmap='tab10',s=1,alpha=0.6)
    plt.show()

if __name__ == "__main__":
  from argparse import ArgumentParser
  parse = ArgumentParser()
  parse.add_argument('--gt_path', type=str, default='data/set/nuscenes/occupancy_gt')
  args=parse.parse_args()
  main(args)
  