# Levenshtein edit distance

x = "love"
y = "movie"

#     m o v i e
#   0 1 2 3 4 5
# l 1 1 2 3
# o 2
# v 3
# e 4


def solve_rec(a, b):
  if a == 0:
    return b
  if b == 0:
    return a

  return min(
    [
      solve_rec(a - 1, b) + 1,
      solve_rec(a, b - 1) + 1,
      solve_rec(a - 1, b - 1) + int(x[a - 1] == y[b - 1])
    ]
  )


n = len(x)
m = len(y)
dist = [[0 for b in range(m + 1)]
        for a in range(n + 1)]
dist[0] = list(range(m + 1))
for i in range(1, n + 1):
  dist[i][0] = i


# O(nm)
def solve_dp(a, b):
  for i in range(1, a + 1):
    for j in range(1, b + 1):
      # example
      # -------
      # i = 1 ('l')
      # j = 2 ('o')
      # the goal is to get from x[:i] to y[:j]
      # - 1 + dist[i - 1][j] = 3
      #   x[:i] ('l') --> x[:i - 1] ('') --> y[:j] ('mo')
      #     * first we remove a char from x[:i] ('l') to get to x[:i - 1] ('')
      #       = 1 (remove a char)
      #     * then we add the dist from x[:i - 1] ('') to y[:j] ('mo')
      #       = 2 (add 2 chars)
      # - dist[i][j - 1] + 1 = 2
      #   x[:i] ('l') --> y[:j - 1] ('m') --> y[:j] ('mo')
      #     * first we add the dist from x[:i] ('l') to y[:j - 1] ('m')
      #       = 1 (change a char)
      #     * then we add y[j] ('o') to make it y[:j] ('mo')
      #       = 1 (add a char)
      # - dist[i - 1][j - 1] + int(x[i - 1] == y[j - 1]) = 2
      #   x[:i - 1] ('') --> y[:j - 1] ('m') --> y[:j] ('mo')
      #     * first add the dist from x[:i - 1] ('') to y[:j - 1] ('m'), namely
      #       we suppose we made x[:i - 1] ('') = y[:j - 1] ('m')
      #       = 1 (add a char)
      #     * then we consider the next char of both words, x[i] ('l') and
      #       y[j] ('o'); at the previous step we make x to 'm' and at this
      #       point x became 'ml', meaning we need to change the last char, to
      #       finally get y[:j] ('mo')
      #       = 1 (change a char)
      dist[i][j] = min(
        [
          dist[i - 1][j] + 1,
          dist[i][j - 1] + 1,
          dist[i - 1][j - 1] + int(x[i - 1] == y[j - 1])
        ]
      )
  return dist[a][b]


if __name__ == '__main__':
  print(solve_rec(n, m))
  print(solve_dp(n, m))
