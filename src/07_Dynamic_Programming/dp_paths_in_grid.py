value = [
  [3, 7, 9, 2, 7],
  [9, 8, 3, 5, 5],
  [1, 7, 9, 8, 5],
  [3, 8, 6, 4, 10],
  [6, 3, 9, 7, 8]
]


# O(2^(x+y)) => O(2^n)
# @functools.lru_cache  # to make it O(n^2), but with the recursion overhead
def solve_rec(x, y):
  if (x == 0) or (y == 0):
    return 0

  # small optimization
  # if x == 1:
  #   return sum(value[row][0] for row in range(y))
  # if y == 1:
  #   return sum(value[0][:x])

  # value indexes need to be converted to 0-indexed
  return max(solve_rec(x - 1, y), solve_rec(x, y - 1)) + value[y - 1][x - 1]


max_path_value = [[0] * len(value[0]) for _ in range(len(value))]


# O(x*y) => O(n^2)
def solve_dp(x, y):

  for i in range(y):
    for j in range(x):
      s = value[i][j]

      if (i > 0) and (j > 0):
        s += max(max_path_value[i - 1][j], max_path_value[i][j - 1])
      elif i > 0:
        s += max_path_value[i - 1][j]
      elif j > 0:
        s += max_path_value[i][j - 1]

      max_path_value[i][j] = s

  return max_path_value[x - 1][y - 1]


if __name__ == '__main__':
  x, y = 5, 5
  ans1 = solve_rec(x, y)
  print(ans1)
  ans2 = solve_dp(x, y)
  print(ans2)
  assert ans1 == ans2 == 67
