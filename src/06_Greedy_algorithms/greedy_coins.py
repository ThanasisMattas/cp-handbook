euro_coins = [1, 2, 5, 10, 20, 50, 100, 200]
rand_coins = [1, 3 ,4]


def solve(n, coins):
  counter = 0

  for coin in reversed(coins):
    while n - coin >= 0:
      n -= coin
      counter += 1

  return counter

if __name__ == '__main__':
  counter = solve(520, euro_coins)
  print(counter)
  assert counter == 4

  counter = solve(6, rand_coins)
  print(counter)
  assert counter == 2, "should be 3 + 3"
