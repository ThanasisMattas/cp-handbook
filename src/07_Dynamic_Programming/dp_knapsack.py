weights = [1, 3, 3, 5]
n = len(weights)
max_w = sum(weights)


def print_possible(possible):
  print(' '.join(map(str, range(max_w + 1))))
  fmt = "{0:>{1}}"
  print(' '.join(fmt.format('X' if possible[x] else ' ', len(str(x)))
                 for x in range(max_w + 1)))


# O(nx) time, n: number of weights, x: max-sum
# O(nx) space
def solve_2d():
  # possible[x][k] is True if x can be constructed with the first k weights
  possible = [[False for k in range(n + 1)]
              for x in range(max_w + 1)]
  # 0 total weight is possible with 0 weights
  possible[0][0] = True

  for k in range(1, n + 1):
    for x in range(max_w + 1):
      if x - weights[k - 1] >= 0:
        # eigher weight k is used
        # (index is k in possible, k-1 in weights)
        possible[x][k] |= possible[x - weights[k - 1]][k - 1]
      # or not
      possible[x][k] |= possible[x][k - 1]

  return [p[n] for p in possible]


# O(nx) time, n: number of weights, x: max-sum
# O(x) space
def solve_1d():
  # possible[x] is True if x can be constructed
  possible = [False] * (max_w + 1)
  # 0 total weight is possible with 0 weights
  possible[0] = True

  for k in range(n):
    for x in range(max_w, -1, -1):
      if possible[x]:
        possible[x + weights[k]] = True

  return possible


if __name__ == '__main__':
  # 0 1 2 3 4 5 6 7 8 9 10 11 12
  # x x   x x x x x x x     x  x
  print_possible(solve_2d())
  print()
  print_possible(solve_1d())
