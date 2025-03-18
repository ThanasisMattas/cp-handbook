from datetime import timedelta
from functools import wraps
from timeit import default_timer as timer


def time_this(f):
    """function timer decorator

    - Uses wraps to preserve the metadata of the decorated function
      (__name__ and __doc__)
    - prints wall and CPU (user+sys) time

    usage:
      @time_this
      def a_func(): pass

    Args:
        f(funtion)      : the function to be decorated

    Returns:
        wrap (callable) : returns the result of the decorated function
    """
    assert callable(f)

    @wraps(f)
    def wrap(*args, **kwargs):
      start = timer()
      result = f(*args, **kwargs)
      end = timer()
      duration = timedelta(seconds=round(end - start, 3))
      print(f"{f.__name__:-<30}{duration}"[:45])
      return result
    return wrap


def print_table(table):
  max_dist = max(max(row for row in table))
  max_dist_len = len(str(max_dist))
  n = len(table)
  n_len = len(str(n))
  print(' ' * (n_len + 3), end='')
  print(' '.join(f"{x:>{max_dist_len}}" for x in range(1, n + 1)))
  print(' ' * (n_len + 3), end='')
  print('-' * (3 * n - 1))
  for r, row in enumerate(table):
    print(f"{r + 1:{n_len}}", '|', end=' ')
    print(' '.join(f"{x:>{max_dist_len}}" for x in row))
