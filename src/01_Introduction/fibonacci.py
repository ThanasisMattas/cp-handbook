from math import floor, sqrt


def fib_rec(n):
  if n < 2:
    return n
  return fib_rec(n - 2) + fib_rec(n - 1)


dp = [0, 1]


def fib_dp_rec(n):
  if n < 2:
    return n
  if len(dp) >= n + 1:
    return dp[n]

  # to get the (n-2)th item, dp must have at least n-1 items
  if len(dp) < n - 1:
    dp.append(fib_dp_rec(n - 2))
    dp.append(fib_dp_rec(n - 1))
  elif len(dp) == n - 1:
    dp.append(fib_dp_rec(n - 1))

  return dp[n - 1] + dp[n - 2]


def fib_dp_iter(n):
  if n < 2:
    return n

  dp = [0, 1]

  for i in range(2, n + 1):
    dp.append(dp[i - 2] + dp[i - 1])

  return dp[n]


# O(1)
def fib_binet(n):
  # For fib_binet(0) = 1, the exponent becomes n + 1.
  return floor((1.618034 ** n) / sqrt(5) + 0.5)
  # Binet's formula:
  # return ((1 + sqrt(5)) ** n) - (1 - sqrt(5)) ** n)) / ((2 ** n) * sqrt(5))


def main():
  # fib = fib_rec
  # fib = fib_dp_rec
  # fib = fib_dp_iter
  fib = fib_binet
  mock = [0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55]
  fibs = [fib(i) for i in range(len(mock))]
  print(mock)
  print(fibs)
  assert mock == fibs


if __name__ == '__main__':
  main()