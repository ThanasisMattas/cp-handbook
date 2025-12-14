
# diag1[y + x]
# –––––
# y 3 | 3 4 5 6
#   2 | 2 3 4 5
#   1 | 1 2 3 4
#   0 | 0 1 2 3
#       – – – –
#       0 1 2 3
#             x

# diag2[y - x + n - 1]
# –––––
# y 3 | 6 5 4 3
#   2 | 5 4 3 2
#   1 | 4 3 2 1
#   0 | 3 2 1 0
#       – – – –
#       0 1 2 3
#             x

n = None
counter = None
col = None
diag1 = None
diag2 = None


def _set_vars(n_new):
  global n
  global counter
  global col
  global diag1
  global diag2
  n = n_new
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
    if col[x] or diag1[y + x] or diag2[y - x + n - 1]:
      continue
    col[x] = diag1[y + x] = diag2[y - x + n - 1] = 1
    solve(y + 1)
    col[x] = diag1[y + x] = diag2[y - x + n - 1] = 0


if __name__ == '__main__':
  _set_vars(4)
  solve()
  print(counter)
  assert counter == 2

  _set_vars(8)
  solve()
  print(counter)
  assert counter == 92
