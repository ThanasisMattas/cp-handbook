v = [-1, 2, 4, -3, 5, 2, -5, 2]


# O(n^2)
def solve_1():
  if not v:
    return 0
  if len(v) == 1:
    return max(0, v[0])

  best = 0
  for i in range(len(v)):
    s = 0
    for j in range(i, len(v)):
      s += v[j]
      if s > best:
        best = s
  return best


# O(n)
# Kadane's alg
def solve_2():
  if not v:
    return 0
  if len(v) == 1:
    return max(0, v[0])

  best = 0
  s = 0

  for x in v:
    s += x
    if x > s:
      s = x
    if s > best:
      best = s

  return best


def max_sum_subarray():
  if not v:
    return []
  if len(v) == 1:
    if v[0] < 0:
      return []
    return v

  best = 0
  s = 0
  best_sub = []
  sub = []

  for x in v:
    s += x
    if x > s:
      s = x
      sub = [x]
    else:
      sub.append(x)
    if s > best:
      best = s
      best_sub = sub.copy()

  return best_sub


if __name__ == '__main__':
  print(v)
  print("max subarray sum:", solve_2())
  print("max sum subarray:", max_sum_subarray())
