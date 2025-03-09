from bisect import bisect_left
import random

n = 8000
v = random.choices(range(n), k=n)

# uncomment these to debug
# v = [6, 2, 5, 1, 7, 4, 8, 3]
# n = len(v)


# O(n^2)
def solve1():
  length = [1] * n
  best = 1

  for k in range(n):
    for i in range(k):
      if (v[i] < v[k]) and (length[i] + 1 > length[k]):
        length[k] = length[i] + 1
    if length[k] > best:
      best = length[k]

  return best


# O(nlogn)
# (maybe too advanced for CP)
def solve2():
  # Holds the LIS, but it won’t necessarily store the exact sequence, just the
  # values that could form the LIS. The last part of this vector will be popu-
  # lated with the last items of the current LIS, whereas the first part will
  # start bulding a prospect LIS that will potentially overthrow the current
  seq = [0] * n
  seq[0] = v[0]

  # length of the populated part of the sequence
  seq_len = 1

  for k in range(1, n):
    i = bisect_left(seq, v[k], hi=seq_len)
    if i == seq_len:
      seq[seq_len] = v[k]
      seq_len += 1
    else:
      seq[i] = v[k]
    # print(seq)

  return seq_len


if __name__ == '__main__':
  print(solve1())
  print(solve2())