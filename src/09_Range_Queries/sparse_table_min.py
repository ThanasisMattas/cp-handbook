from math import log2

v = [1, 3, 4, 8, 6, 1, 4, 2]
table = []


# O(nlogn)
def populate_table():
  n = len(v)

  # number of rows of the sparse table
  # = number of distinct powers of 2
  m = int(log2(n) + 1)

  # 0th power of 2
  table.append(v)

  for p in range(1, m):
    window = 1 << p
    row_len = n - window + 1
    row = [min(table[-1][i], table[-1][i + window // 2])
           for i in range(row_len)]
    table.append(row)


# O(nlogn)
def print_table():
  for p, row in enumerate(table):
    for i, value in enumerate(row):
      window = 1 << p
      print(i, i + window - 1, value)
    print()


# O(1)
def solve(a, b):
  p = int(log2(b - a + 1))
  window = 1 << p
  return min(table[p][a], table[p][b - window + 1])


if __name__ == '__main__':
  populate_table()
  print_table()
  print(' ' + '  '.join(map(str, list(range(len(v))))))
  print(v)
  print()

  queries = (
    (0, len(v) - 1),
    (0, 0),
    (2, 4),
    (3, 6),
    (6, 7)
  )
  for a, b in queries:
    ans = solve(a, b)
    print(a, b, ':', ans)
    assert ans == min(v[a: b +1])
