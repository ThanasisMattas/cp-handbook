from bisect import bisect_left
from typing import Any, Callable, Sequence


def is_increasing(i: int,
                  v: Sequence[Any] = None,
                  f: Callable[[int], Any] = None) -> bool:
  if f:
    return f(i - 1) < f(i)
  return v[i - 1] < v[i]


# O(logn)
def argmin_with_binary_search(v: Sequence[Any]) -> int:
  """Finds the argmin of a unimodal distribution with binary search.

  NOTE:
    1. The sequence is converted to [0, ..., 0, 1, ..., 1], assigning with 0
      each i <= argmin, denoting decrease, and with 1 each i > argmin, denoting
      increase. Increase/decrease on index i is checked against i - 1.

      Example
      -------
      i:      0   1   2   3   4   5  6  7  8  9 10 11 12
      v:    [20, 18, 16, 14, 12, 10, 8, 6, 4, 2, 0, 2, 4]
      mask:   0   0   0                 0  0  0  0  1  1

    2. The algorithm checks if the current position (b + k) lies at the
      decreasing region (before argmin) or at the increasing region (after
      argmin). If it overshoots, it moves backwards logarithmically (b //= 2).
      If it undershoots, it moves foreward linearly (k += b). "The idea is to
      make jumps and slow the speed when we get closer to the target element."
  """
  n = len(v)
  b = n // 2
  k = -1

  while b >= 1:
    while (b + k < n) and (not is_increasing(b + k, v)):
      if (b + k == n - 1) or (is_increasing(b + k + 1, v)):
        return b + k
      k += b
    b //= 2


# O(logn)
def argmin_with_bisect(v: Sequence[Any],
                       f: Callable[[int], Any] = None) -> int:
  """Finds the global minimum with bisect.

  NOTE: The goal is to insert a 1 before the first 1 with bisect_left() (or a 0
    after the last 0, with bisect_right()). In both cases (bisect_left/right)
    the new item is inserted at the index of the first 1, which is argmin + 1.
    (see argmin_with_binary_search())

  Args:
    v (Sequence): a unimodal distribution
    f (Optional[Callable[[int], Any]]): A unimodal function to find its argmin.
      If not None, v should be the index list to binary search against.
      Therefore, this only works when there is a known range that include the
      argmin. Namely, low and high are known. If no such range is known, use
      argmin_func().

  Returns:
    int: argmin
  """

  def mask(i):
    return is_increasing(i, v, f)

  a = v if f else range(len(v))
  return bisect_left(a, True, key=mask) - 1


def argmin_func(f: Callable[[int], Any], b: int = 1024) -> int:
  """Finds the argmin of a unimodal, univariate function.

  NOTE: b can be initialized to an arbitrary value, ideally with the best
    estimate for argmin.

    Minor improvement/rant
    ----------------------
    This algorithm works best if it initially overshoots after the target, to
    move backwards logarithmically (b //= 2). If if initially undershoots, it
    will attempt to find the target linearly at increaments of b (k += b),
    which is slower, especially if the target is far. So, better first overshoot.
    (see argmin_with_binary_search())
  """
  k = -1
  while b >= 1:
    while not is_increasing(b + k, f=f):
      if is_increasing(b + k + 1, f=f):
        return b + k
      k += b
    b //= 2


def f(x: int) -> int:
  """A unimodal function"""
  if x < 10:
    return -2 * x + 20
  return 2 * x - 20


def test_binary_search():
  v = [-5, -3, -1, 2, 2, 4, 5]
  x = 4
  print(v)
  # O(logn)
  i = bisect_left(v, x)
  print(i)
  assert i == 5


def test_find_global_min():
  # find the global min of a unimodal function
  assert argmin_func(f) == 10
  assert argmin_with_bisect(list(range(1024)), f) == 10

  # find the global min of a unimodal distribution
  for argmin in [argmin_with_binary_search, argmin_with_bisect]:
    v = [20, 18, 16, 14, 12, 10, 8, 6, 4, 2, 0, 2, 4]
    print(v)
    i = argmin(v)
    print(i)
    assert i == 10

    print()

    v.reverse()
    print(v)
    i = argmin(v)
    print(i)
    assert i == 2

    print()

    # test the edges
    v = [20, 18, 16, 14, 12, 10, 8, 6, 4, 2, 0]
    print(v)
    i = argmin(v)
    print(i)
    assert i == len(v) - 1

    print()

    v.reverse()
    print(v)
    i = argmin(v)
    print(i)
    assert i == 0

    print()


if __name__ == '__main__':
  test_binary_search()
  print()
  print("-" * 20)
  print()
  test_find_global_min()
