from copy import deepcopy
import math

import os
import sys
sys.path.append(os.path.abspath(os.path.join(os.path.dirname(__file__), '..')))
from utils import print_table

f = math.inf
adj = [
  [0, 5, f, f, f, 1, f, f, 15, f, f, f],   #  1
  [1, 0, -2, f, 3, f, f, f, f, f, f, f],   #  2
  [f, 3, 0, 1, f, 4, f, f, f, f, f, f],    #  3
  [f, f, 2, 0, 3, 1, f, f, f, f, f, f],    #  4
  [f, 3, f, 8, 0, f, f, f, f, f, f, f],    #  5
  [1, f, f, -1, f, 0, 8, f, f, 12, f, f],  #  6
  [f, f, f, f, f, 5, 0, 12, f, f, f, 3],   #  7
  [f, f, f, f, f, f, 9, 0, 7, f, 5, -2],   #  8
  [f, f, 8, f, f, -1, f, f, 0, f, 4, f],   #  9
  [-1, f, 6, f, f, f, f, f, 2, 0, f, f],   # 10
  [f, f, f, f, f, f, 14, f, 12, f, 0, f],  # 11
  [f, 15, f, f, 1, 1, 2, f, -3, f, f, 0]   # 12
]
dist = deepcopy(adj)
n = len(adj)


# O(n^3)
def floyd_warshall():
  for k in range(n):
    for i in range(n):
      for j in range(n):
        if dist[i][j] > dist[i][k] + dist[k][j]:
          dist[i][j] = dist[i][k] + dist[k][j]


if __name__ == '__main__':
  floyd_warshall()
  print_table(dist)
