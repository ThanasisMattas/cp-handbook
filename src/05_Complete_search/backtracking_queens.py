
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


# O(n!)
#
# Explanation
# -----------
# Choice at each row:
#   * y = 0: N choices (N columns)
#   * y = 1: at most N-1 choices (prunning the col we placed a queen previously
#     which attacks the corresponding square of the current row)
#   * y = 2: at most N-2 choices, and so on.
#
# This forms a branching factor that constructs a factorial:
#                   N * (N-1) * (N-2) * ... * 1 = N!
#
# However, the solution also considers diagonals to prune more invalid
# placements early, resulting to O(N! / N^c) for some constant c, but this does
# not change the factorial growth rate.
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
