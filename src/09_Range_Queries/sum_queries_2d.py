from random import randint
from pprint import pprint

n = 5  # rows
m = 7  # cols
v = [[randint(0, 9)] * m for _ in range(n)]
psm = [[0] * m for _ in range(n)]


# O(nm)
def populate_psm():
  psm[0][0] = v[0][0]

  # 1st row
  for j in range(1, m):
    psm[0][j] = v[0][j] + psm[0][j - 1]

  # 1st col
  for i in range(1, n):
    psm[i][0] = v[i][0] + psm[i - 1][0]

  # rest
  for i in range(1, n):
    for j in range(1, m):
      psm[i][j] += psm[i - 1][j] + psm[i][j - 1] - psm[i - 1][j - 1] + v[i][j]


# O(1)
def solve(x_br, y_br, x_tl, y_tl):
  ans = psm[y_br][x_br]
  if x_tl:
    ans -= psm[y_br][x_tl - 1]
  if y_tl:
    ans -= psm[y_tl - 1][x_br]
  if x_tl and y_tl:
    ans += psm[y_tl - 1][x_tl - 1]
  return ans


if __name__ == '__main__':
  populate_psm()

  pprint(v)
  print()
  pprint(psm)
  print()
  assert psm[-1][-1] == sum(sum(b) for b in v)

  # (x_br, y_br), (x_tl, y_tl)
  queries = (
    ((5, 4), (1, 2)),
    ((4, 3), (2, 2)),
    ((0, 4), (0, 2)),
    ((0, 4), (0, 0)),
    ((4, 0), (1, 0)),
    ((4, 3), (1, 0)),
  )

  for br, tl in queries:
    print(br, tl, ':', solve(*br, *tl))
