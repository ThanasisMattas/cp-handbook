v = [1, 3, 4, 2, 5, 3, 4, 2, 0, 1]


# amortized O(n)
def solve():
  stack = []
  ans = []

  for x in v:
    while (stack) and (stack[-1] >= x):
      stack.pop()
    if stack:
      ans.append(stack[-1])
    else:
      ans.append('-')
    stack.append(x)

  print(' '.join(map(str, v)))
  print(' '.join(map(str, ans)))


if __name__ == '__main__':
  solve()
