v = [1, 3, 2, 5, 1, 1, 2, 3]


# amortized O(n)
def solve(x):
  n = len(v)
  left = 0
  right = 0
  s = v[0]

  while right < n:
    if s == x:
      print(f"{x}: {v[left: right + 1]}")
      return

    if s < x:
      if right == n - 1:
        break
      right += 1
      s += v[right]
    else:
      if left == right:
        if right == n - 1:
          break
        right += 1
        s += v[right]
      s -= v[left]
      left += 1

  print(f"{x}: IMPOSSIBLE")


if __name__ == '__main__':
  solve(8)
  solve(10)
  solve(16)
  solve(6)
  solve(12)
  solve(4)
  solve(24)
