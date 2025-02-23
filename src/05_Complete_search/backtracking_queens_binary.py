
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


# O(n!)
# (For explanation see backtracking_queens.py)
def solve(n, y=0, col=0, diag1=0, diag2=0):
  if y == n:
    return 1

  count = 0
  for x in range(n):
    if (col & (1 << x)
          or diag1 & (1 << x + y)
          or diag2 & (1 << n - 1 - x + y)):
      continue
    # set bit to one
    count += solve(n,
                   y + 1,
                   col | 1 << x,
                   diag1 | 1 << (x + y),
                   diag2 | 1 << (n - 1 - x + y))
  return count

if __name__ == '__main__':
  for n, c in ((4, 2), (8, 92)):
    count = solve(n)
    print(count)
    assert count == c
