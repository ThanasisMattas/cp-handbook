from bisect import bisect_left


def is_increasing(i, v=None, f=None):
  if f:
    return f(i - 1) < f(i)
  return v[i - 1] < v[i]


# O(logn)
def global_min_1(v):
  """Finds the global minimum.

  Args:
    v (list): precalculated values produced by a unimodal function

  NOTE:
    1. The function producing the given numbers is expected to be unimodal.
    2. If precalculated values are not available (list v), checking for index
      out-of-range should be removed. In that case, b can be initialized to an
      arbitrary value, ideally with the best estimate for the min. Minor
      improvement/ rant: This algorithm works best if it initially overshoots
      after the target, to move backwards logarithmically (b //= 2). If the
      first estimate of b lies before the target, it will attempt to find it
      linearly at increaments of b (k += b), which is slower, especially if the
      target is far. So, better first overshoot.
  """
  n = len(v)
  b = n
  k = -1
  while b >= 1:
    while (b + k < n) and (not is_increasing(b + k, v)):
      if (b + k == n - 1) or (is_increasing(b + k + 1, v)):
        return b + k
      k += b
    b //= 2


def global_min_2(v):
  """Finds the global minimum with bisect.

  NOTE:
    1. The function producing the given numbers is expected to be unimodal.
    2. The sequence is converted to [0, ..., 0, 1, ..., 1], assigning with 0
      each i <= argmin, denoting decrease, and with 1 each i > argmin, denoting
      increase. Increase/decrease on index i is checked against i - 1. The goal
      is to insert a 1 before the first 1 with bisect_left() (or a 0 after the
      last 0, with bisect_right()). In both cases (bisect_left/right) the new
      item is inserted at the index of the first 1, which is argmin + 1.

      i:      0   1   2   3   4   5  6  7  8  9 10 11 12
      f:    [20, 18, 16, 14, 12, 10, 8, 6, 4, 2, 0, 2, 4]
      mask:   0   0   0                 0  0  0  0  1  1
  """

  def mask(i):
    return is_increasing(i, v)

  return bisect_left(range(len(v)), True, key=mask) - 1


if __name__ == '__main__':
  # binary search
  v = [-5, -3, -1, 2, 2, 4, 5]
  x = 4
  print(v)
  # O(logn)
  i = bisect_left(v, x)
  print(i)
  assert i == 5

  print()

  # find global min
  for global_min in [global_min_1, global_min_2]:
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

    print()
