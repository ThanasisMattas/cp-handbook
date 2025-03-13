from itertools import accumulate


v = [1, 3, 4, 8, 6, 1, 4, 2]
cumsum = list(accumulate(v))


def solve(a, b):
  return cumsum[b] - cumsum[a] + v[a]


if __name__ == '__main__':
  queries = (
    ((1, 3), 15),
    ((0, len(v) - 1), sum(v)),
    ((0, 3), 16),
    ((4, 7), 13),
    ((5, 6), 5)
  )

  for q, expected in queries:
    ans = solve(*q)
    print(ans)
    assert ans == expected
