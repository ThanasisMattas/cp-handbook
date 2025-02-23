
# diag1[x + y]
# –––––
# y 3 | 3 4 5 6
#   2 | 2 3 4 5
#   1 | 1 2 3 4
#   0 | 0 1 2 3
#       – – – –
#       0 1 2 3
#             x

# diag2[n - 1 - x + y]
# –––––
# y 3 | 6 5 4 3
#   2 | 5 4 3 2
#   1 | 4 3 2 1
#   0 | 3 2 1 0
#       – – – –
#       0 1 2 3
#             x

n = 4
counter = 0
col = [0] * n
diag1 = [0] * (2 * n - 1)
diag2 = [0] * (2 * n - 1)


def solve(y=0):
  if y == n:
    global counter
    counter += 1
    return

  for x in range(n):
    if col[x] or diag1[x + y] or diag2[n - 1 - x + y]:
      continue
    col[x] = diag1[x + y] = diag2[n - 1 - x + y] = 1
    solve(y + 1)
    col[x] = diag1[x + y] = diag2[n - 1 - x + y] = 0

if __name__ == '__main__':
  solve()
  print(counter)
  assert counter == 2

  n = 8
  counter = 0
  col = [0] * n
  diag1 = [0] * (2 * n - 1)
  diag2 = [0] * (2 * n - 1)

  solve()
  print(counter)
  assert counter == 92
