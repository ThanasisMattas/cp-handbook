from itertools import combinations
import random

import os
import sys
sys.path.append(os.path.abspath(os.path.join(os.path.dirname(__file__), '..')))
from utils import time_this

seed = 999
random.seed(seed)

n = 600
N = 64
num_blocks = (n + N - 1) // N

color = [random.choices((0, 1), k=n) for _ in range(n)]
color_packed = [[0 for _ in range(num_blocks)] for _ in range(n)]


# O(n^2)
def compress_color_matrix():
  """Converts the binary grid into a compressed N-bit representation.

  Compressing optimization:
    * SIMD (Single Instruction, Multiple Data)
      Modern CPUs handle bitwise operations (&, |, ^) in parallel within vector
      registers, with a single instruction. These registers are wider than
      standard scalar registers and are optimized for handling arrays of
      numbers simultaneously. (N=64 aligns with AVX2 (Intel) or NEON (ARM))
    * better cache locality
    * leverage NumPy vectorized bitwise operations with np.uint64 (N=64):
      color_np = np.array(color, dtype=np.uint8)
      color_packed = np.packbits(
        color_np, axis=1, bitorder='little'
      ).astype(np.uint64)

  Example
  -------
  n = 6
  N = 4 bit
              pad
              - - | packed
  1 0 1 1 0 0 0 0 | 11  0
  0 1 1 0 1 1 0 0 |  6 12
  1 1 0 0 1 0 0 0 | 12  8
  1 1 0 1 1 0 0 0 | 13  8
  0 0 0 0 0 1 0 0 |  0  4
  1 0 0 0 1 1 0 0 |  8 12
  """
  for i in range(n):
    for j in range(n):
      block, bit = divmod(j, N)
      color_packed[i][block] |= color[i][j] << bit


# O(n^3/N)
@time_this
def solve_bit_optimization():
  square_count = 0
  for i, j in combinations(range(n), 2):
    pair_count = 0
    for k in range(num_blocks):
      pair_count += (color_packed[i][k] & color_packed[j][k]).bit_count()
    square_count += (pair_count * (pair_count - 1)) // 2
  return square_count


# O(n^3)
@time_this
def solve_brute_force():
  square_count = 0
  for i, j in combinations(range(n), 2):
    pair_count = 0
    for k in range(n):
      if color[i][k] == color[j][k] == 1:
        pair_count += 1
    square_count += (pair_count * (pair_count - 1)) // 2
  return square_count


if __name__ == '__main__':
  compress_color_matrix()
  count_bit_repr = solve_bit_optimization()
  count_brute_force = solve_brute_force()
  print(f"n={n}  N={N}  count={count_bit_repr}")
  if (seed == 999) and (n == 600):
    assert count_bit_repr == count_brute_force == 2040516310
  else:
    assert count_bit_repr == count_brute_force
