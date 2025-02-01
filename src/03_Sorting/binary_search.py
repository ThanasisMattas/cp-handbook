from bisect import bisect_left


v = [-5, -3, -1, 2, 2, 4, 5]
x = 4


def binary_search():
  return bisect_left(v, x)


def global_min(v):
  """Finds the global minimum.

  NOTE: The function producing the given numbers is expected to be monotonic
    and injective.
  """
  n = len(v)
  b = n
  k = -1
  while b >= 1:
    while (b + k < n) and (v[b + k] < v[b + k - 1]):
      if (b + k == n - 1) or (v[b + k] < v[b + k + 1]):
        return b + k
      k += b
    b //= 2


if __name__ == '__main__':
  i = binary_search()
  print(v)
  print(i)
  assert i == 5

  print()

  # find global min
  v = [20, 18, 16, 14, 12, 10, 8, 6, 4, 2, 0]
  v = [20, 18, 16, 14, 12, 10, 8, 6, 4, 2, 0, 2, 4]
  print(v)
  i = global_min(v)
  print(i)
  assert i == 10

  print()

  v.reverse()
  print(v)
  i = global_min(v)
  print(i)
  assert i == 2

  print()

  # test the edges
  v = [20, 18, 16, 14, 12, 10, 8, 6, 4, 2, 0]
  print(v)
  i = global_min(v)
  print(i)
  assert i == len(v) - 1

  print()

  v.reverse()
  print(v)
  i = global_min(v)
  print(i)
  assert i == 0
