
succ = [0, 3, 5, 7, 6, 2, 2, 1, 6, 3]
n = len(succ) - 1
# max power of 2 which is less than the max number of steps (say u = 2n)
max_p = (2 * n).bit_length()
succ_px = [[0] * (n + 1) for _ in range(max_p)]


# O(nlogu), here O(nlog(2n)) = O(nlogn)
# This bottom-up approach is better than the recursive (top-down), since it is
# cleaner, more explicit and it avoids the redundant function calls and the
# function call stack memory overhead.
def populate_succ_px_iterative():
  succ_px[0] = succ.copy()

  for p in range(1, max_p):
    for x in range(1, n + 1):
      # 1. walk 2^(p-1) steps from x
      #        half_walk = succ_px[p - 1][x]
      # 2. then walk the other 2^(p-1) steps
      #        full_walk = succ_px[p - 1][half_walk]
      succ_px[p][x] = succ_px[p - 1][succ_px[p - 1][x]]


# O(logk)
def solve(x, k: int):
  for p in range(k.bit_length()):
    if k & (1 << p):
      x = succ_px[p][x]
  return x


if __name__ == '__main__':
  populate_succ_px_iterative()
  __import__('pprint').pprint(succ_px)

  for x, k, s in ((4, 11, 5), (4, 6, 2)):
    ans = solve(x, k)
    assert ans == s, (ans, s)
    print(ans)
