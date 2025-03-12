from collections import deque  # deque(iterable, maxlen)                       # noqa: F401
# append, appendleft, popleft, pop, clear, count(x), reverse, rotate(n=1)
# remove(value) - first occurance, maxlen()
def delete_nth(deq, n):
  deq.rotate(-n)
  deq.popleft()
  deq.rotate(n)
from collections import OrderedDict  # popitem(last=True)                      # noqa: F401
import heapq                                                                   # noqa: F401

from itertools import combinations, starmap                                    # noqa: F401

import math                                                                    # noqa: F401
from math import factorial as fact

from operator import itemgetter  # sorted(alist, key=itemgetter(0, 1))         # noqa: F401

import random                                                                  # noqa: F401
from random import choices, seed, randrange                                    # noqa: F401
# choices(alist, k=<num_choices>)
# random.randrange(stop)
# random.randrange(start, stop[, step])
# Return a randomly selected element from range(start, stop, step). This is
# equivalent to choice(range(start, stop, step)), but doesn’t actually build a
# range object.
# random.randint(start, stop) (stop is true stop)
from timeit import default_timer as timer                                      # noqa: F401

DIVISOR = int(1e9 + 7)


def unique_combs(n, K):
  if n < K:
    return 0
  elif K == 1:
    return n
  else:
      # combs = fact(n) / (fact(K) * fact(n - K))
      # (A / B) % DIVISOR = (A * B ** (DIVISOR - 2)) % DIVISOR
      a = fact(n)
      b = fact(K) * fact(n - K)
      return (a * pow(b, DIVISOR - 2, DIVISOR)) % DIVISOR


def transpose(mat):
  # return list(map(list, zip(*mat)))
  # save as:
  return list(zip(*mat))


def solve():
  pass


def main():
  t = int(input().strip())
  for _ in range(t):
    solve()


if __name__ == '__main__':
  main()
