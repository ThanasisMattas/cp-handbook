v = [9, 4, 6, 1, 9, 5, 10, 7]


def solve(x):
  n = len(v)

  if n == 0:
    if x == 0:
      print("0: []")
    else:
      print(f"{x}: IMPOSSIBLE")
    return
  if n == 2:
    if sum(v) == x:
      print(f"{x}: {v[0]} + {v[1]}")
    else:
      print(f"{x}: IMPOSSIBLE")
    return

  v.sort()
  left = 0
  right = n - 1
  s = v[left] + v[right]

  while (s != x) and (right - left > 1):
    if s < x:
      left += 1
    else:
      right -= 1
    s = v[left] + v[right]

  if s == x:
    print(f"{x}: {v[left]} + {v[right]}")
  else:
    print(f"{x}: IMPOSSIBLE")


if __name__ == '__main__':
  solve(12)
  solve(3)
