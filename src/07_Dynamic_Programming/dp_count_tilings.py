from functools import lru_cache

import os
import sys
sys.path.append(os.path.abspath(os.path.join(os.path.dirname(__file__), '..')))
from utils import time_this

# Π Π [ ]
# U U Π Π
# Π Π U U
# U U [ ]
# Π [ ] Π
# U [ ] U
# [ ] [ ]


# O(n*2^(2m))
def solve(n, m, maxsize=None):
  # odd-sized grids cannot be filled with 2-sqare tiles
  if (m * n == 0) or ((m * n) % 2):
    return 0

  # the column should be the smallest dimension, because it dominates the
  # complexity - 2^(2m)
  if m > n:
    n, m = m, n

  def next_rows(row, col=0, next_row=0):
    """Generates all possible next_row's given the current row."

    Args:
      row (int): a bitmap representing the row, with 1 denoting a upper-square
        of a vertical tile, and 0 all the rest
      col (int): the column currently considering to populate with 1 or 0
      next_row (int): it is being built col-by-col

    Returns:
      next_row (int): when it is built, until the last col
    """
    # a next_row is complete and time to yield it
    if col == m:
      yield next_row
      return

    # row contains the upper part of the vertical tile at these columns. Thus,
    # next_row should get the lower part, meaning we leave it as it is (0).
    if row & (1 << col):
      yield from next_rows(row, col + 1, next_row)
      return

    # start a vertical tile (place the upper part of a vertical tile)
    yield from next_rows(row, col + 1, next_row | (1 << col))

    # place a horizontal tile if space allows
    if (col < m - 1) and (not (row & (1 << (col + 1)))):
      yield from next_rows(row, col + 2, next_row)

  @lru_cache(maxsize=maxsize)
  def dp(k, row):
    if k == n:
      return int(row == 0)
    return sum(dp(k + 1, next_row) for next_row in next_rows(row))

  return dp(0, 0)


def test_solve():
  zero_count_cases = (
    (0, 0),
    (0, 1),
    (1, 0),
    (1, 1),
    (3, 3),
    (7, 7),
    (15, 15)
  )
  for n, m in zero_count_cases:
    assert solve(n, m) == 0, (n, m)

  assert solve(4, 7) == 781


if __name__ == '__main__':
  test_solve()
  n, m = 6, 8
  timed_solve = time_this(solve)
  print("With DP:")
  count = timed_solve(n, m)
  print()
  print("Without DP:")
  count_dp = timed_solve(n, m, maxsize=1)
  assert count == count_dp
  print()
  print(f"n: {n}  m: {m}  count: {count}")
