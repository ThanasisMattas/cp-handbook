#              1
#        2           3
#    4       5   6       7
# 8     9                   12
#     10 11
adj = [
  [],
  [2, 3],       #  1
  [1, 4, 5],    #  2
  [1, 6, 7],    #  3
  [2, 8, 9],    #  4
  [2],          #  5
  [3],          #  6
  [3, 12],      #  7
  [4],          #  8
  [4, 10, 11],  #  9
  [9],          # 10
  [9],          # 11
  [7]           # 12
]
counter = [0] * len(adj)


def dfs(u, u_prev):
  counter[u] = 1
  for u_next in adj[u]:
    if u_next == u_prev:
      continue
    dfs(u_next, u)
    counter[u] += counter[u_next]


if __name__ == '__main__':
  dfs(1, 0)
  n_len = len(str(len(adj)))
  for u, c in enumerate(counter[1:]):
    print(f"{u:>{n_len}}", ':', f"{c:>{n_len}}")
