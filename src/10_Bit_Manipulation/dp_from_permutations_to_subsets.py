weight = [2, 3, 3, 5, 6]
n = len(weight)
x = 10

# [min_num_rides, min_last_sum]
best = [[n + 1, 0] for _ in range(1 << n)]


# O(n2^n)
def solve():
  # empty group: 1 ride, 0 last ride sum
  # Acts as a base case that ensures when we build up from smaller subsets, the
  # first person gets assigned to a ride without extra conditions. If best[0]
  # was [0, 0], adding the first person would require extra handling because
  # the transition assumes there is at least one ride available.
  best[0] = [1, 0]

  for s in range(1, 1 << n):
    for p in range(n):
      if s & (1 << p):
        option = best[s ^ (1 << p)].copy()
        if option[1] + weight[p] <= x:
          # if person p fits in the last ride of set s ^ (1 << p), s consists
          # of the same amound of rides, adding p's weight at the last ride sum
          option[1] += weight[p]
        else:
          # else, start a new ride with p as the single passenger
          option[0] += 1
          option[1] = weight[p]

        best[s] = min(best[s], option)

  return best[-1][0]


if __name__ == '__main__':
  print(solve())