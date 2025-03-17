from math import log2


price = [
  [6, 9, 5, 2, 8, 9, 1, 6],
  [8, 2, 6, 2, 7, 5, 7, 2],
  [5, 3, 9, 7, 3, 5, 1, 4]
]

# num products
k = len(price)
# num days
n = len(price[0])


# O(2^k * n * k)
# The function operates on a (s, d) state. s takes 1 << k = 2^k values and d
# takes n values. Each (s, d) state has at most k recursive calls.
def solve_rec(s, d):
  # emtpy set: 0 cost
  if s == 0:
    return 0
  if d == 0:
    # check if s is a power of 2, meaning it contains a single item
    # alternatives:
    #   * Python >= 3.10: s.bit_count() == 1
    #   * Python <  3.10: bin(s).count('1') == 1
    if (s & (s - 1)) == 0:
      return price[int(log2(s))][0]
    # else, if multiple items in the set, we can only buy 1
    best = 2e9
    for x in range(k):
      if (s & (1 << x)) and (price[x][0] < best):
        best = price[x][0]
    return best

  # either don't buy a product at day d
  best = solve_rec(s, d - 1)
  # or buy a product that belongs to s at day d
  for x in range(k):
    if s & (1 << x):
      best = min(best, solve_rec(s ^ (1 << x), d - 1) + price[x][d])

  return best


# total[s][d]: min price of buying subset s at day d
total = [[2e9] * n for _ in range(1 << k)]


# O(2^k * n * k)
# Same with recursive, but significantly faster due to memoization.
def solve_dp():
  # empty set costs nothing at any day
  for d in range(n):
    total[0][d] = 0

  # we can only pick one item at the 0th day
  for s in range(1, 1 << k):
    if (s & (s - 1)) == 0:
      # single-item sets
      total[s][0] = price[int(log2(s))][0]
    else:
      # pick the cheapest item from multi-item sets
      for x in range(k):
        if (s & (1 << x)) and (price[x][0] < total[s][0]):
          total[s][0] = price[x][0]

  for d in range(1, n):
    for s in range(1, 1 << k):
      best = total[s][d - 1]
      for x in range(k):
        if s & (1 << x):
          best = min(best, total[s ^ (1 << x)][d - 1] + price[x][d])
      total[s][d] = best
  return total[-1][-1]


if __name__ == '__main__':
  cost_rec = solve_rec((1 << k) - 1, n - 1)
  cost_dp = solve_dp()
  print("total cost:", cost_dp)
  assert cost_rec == cost_dp