# fastest impl: rec + lru_cache

from functools import lru_cache

adj = [
  [],
  [2, 4],
  [3],
  [6],
  [5],
  [2, 3],
  []
]
n = len(adj) - 1
reverse_adj = [[] for _ in range(1 + n)]


def populate_reverse_adj():
  for u, adjlist in enumerate(adj):
    for v in adjlist:
      reverse_adj[v].append(u)


def solve_rec(v=n):
  if v == 1:
    return 1
  return sum(solve_rec(u) for u in reverse_adj[v])


paths = [0] * (n + 1)


def solve_dp_rec_2(v=n):
  for u in reverse_adj[v]:
    if paths[u] == 0:
      solve_dp_rec_2(u)
    paths[v] += paths[u]


################################ top sort #####################################
top_sort = []
state = [0] * (n + 1)


def dfs(u, u_prev=-1):
  if state[u] == 2:
    return False
  if state[u] == 1:
    return True

  state[u] = 1
  for u_next in adj[u]:
    if (u_next != u_prev) and (dfs(u_next, u)):
      return True

  state[u] = 2
  top_sort.append(u)
  return False


def populate_top_sort():
  for u in range(1, n + 1):
    if dfs(u):
      print("Cycle detected")
      break


def solve_top_sort():
  populate_top_sort()
  paths = [0] * (n + 1)
  paths[1] = 1

  for u in reversed(top_sort):
    for v in adj[u]:
      paths[v] += paths[u]

  print(paths[n])


if __name__ == '__main__':
  populate_reverse_adj()
  # recursive
  print(solve_rec())
  # recursive with lru_cache dp
  solve_dp_rec_1 = lru_cache(solve_rec)
  print(solve_dp_rec_1())
  # recursive with explicit dp
  paths[1] = 1
  solve_dp_rec_2()
  print(paths[n])
  # topological sort
  solve_top_sort()
