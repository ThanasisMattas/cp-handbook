coins = [2, 3, 4]
n = 100000
dp = [0] * n
ready = [False] * n


def solve_recursive(x):
  if x < 0:
    return 2e9
  if x == 0:
    return 0
  return min(
    solve_recursive(x - c) + 1 for c in coins
  )


# O(xn),  x: value, n: num_coins
def solve_memoization_recursive(x):
  if x < 0:
    return 2e9
  if x == 0:
    return 0
  if ready[x]:
    return dp[x]

  dp[x] = min(
    solve_memoization_recursive(x - c) + 1 for c in coins
  )
  ready[x] = True
  return dp[x]


# Same complexity with mem-rec, O(xn), but with smaller constants.
def solve_memoization_iterative(x):
  for i in range(1, x + 1):
    for c in coins:
      if (i - c >= 0) and (dp[i - c] + 1 < dp[i]):
        dp[i] = dp[i - c] + 1


first = [0] * n


def valid_solution(x):
  for i in range(1, x + 1):
    for c in coins:
      if (i - c >= 0) and (dp[i - c] + 1 < dp[i]):
        dp[i] = dp[i - c] + 1
        first[i] = c

  solution = []
  while x:
    solution.append(first[x])
    x -= first[x]
  return solution


def count_solutions(x):
  for i in range(1, x + 1):
    for c in coins:
      if i - c >= 0:
        dp[i] += dp[i - c]


if __name__ == '__main__':
  x = 10
  print(solve_recursive(x))
  solve_memoization_recursive(x)
  print(dp[x])

  dp = [2e9] * n
  dp[0] = 0
  solve_memoization_iterative(x)
  print(dp[x])

  dp = [2e9] * n
  dp[0] = 0
  print(valid_solution(x))

  dp = [0] * n
  dp[0] = 1
  count_solutions(x)
  print(dp[x])
  assert dp[x] == 17
