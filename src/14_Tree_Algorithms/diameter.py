# tip: focus on the 2 dfs' (farthest leaf to farthest leaf)

from tree_examples import adj, random_node

# len to farthest leaf
to_leaf = [0] * len(adj)
# max len of the paths with the i node as the highest point
max_len = [0] * len(adj)


def _init_dp():
  global leaf
  global to_leaf
  to_leaf = [0] * len(adj)
  leaf = [0] * len(adj)


# O(n)
# Calculates the longest path, whose highest point is u. In the book it is
# refered as dp; however both methods here use DP, DFS and recursion.
def solve_highest_point(u, u_prev=None):
  if len(adj[u]) == 1:
    # In order to be a leaf, the single neighbor has to be u_prev.
    if u_prev == adj[u][0]:
      to_leaf[u_prev] = max(to_leaf[u_prev], 1)
      return
    if u_prev is None:
      # then the execution started from a leaf
      to_leaf[adj[u][0]] = 1
      u = adj[u][0]
      u_prev = u

  # 2 longest to_leaf distances of 2 children of u
  first_max = 0
  second_max = 0

  for u_next in adj[u]:
    if u_next == u_prev:
      continue
    solve_highest_point(u_next, u)

    if to_leaf[u_next] > first_max:
      second_max = first_max
      first_max = to_leaf[u_next]
    elif to_leaf[u_next] > second_max:
      second_max = to_leaf[u_next]

  to_leaf[u] = first_max + 1
  max_len[u] = first_max + second_max + 2


# the farthest leaf
leaf = [0] * len(adj)


# O(n)
def dfs(u, u_prev=None):
  # In order to be a leaf, the single neighbor has to be u_prev.
  if (len(adj[u]) == 1) and (adj[u][0] == u_prev):
    if to_leaf[u_prev] == 0:
      to_leaf[u_prev] = 1
      leaf[u_prev] = u
    return

  for u_next in adj[u]:
    if u_next == u_prev:
      continue
    dfs(u_next, u)
    if to_leaf[u_next] + 1 > to_leaf[u]:
      to_leaf[u] = to_leaf[u_next] + 1
      leaf[u] = leaf[u_next]


# O(n)
# Calculates the longest path, by finding the farthest leaf from a random
# node and then the farthest leaf of that leaf. In the book it is refered as
# DFS; however, both methods here use DP, DFS and recursion.
def solve_farthest_leaf_to_farthest_leaf():
  # Step 1: Go to the farthest leaf, starting from a random node.
  start = random_node()
  dfs(start)
  farthest_leaf = leaf[start]

  # Step 2: Go to the farthest leaf, starthing from that leaf.
  _init_dp()
  dfs(farthest_leaf)

  return to_leaf[farthest_leaf]


if __name__ == '__main__':
  solve_highest_point(random_node())
  diameter1 = max(max_len)
  _init_dp()
  diameter2 = solve_farthest_leaf_to_farthest_leaf()
  print("diameter:", diameter1)

  # test starting from a leaf
  _init_dp()
  solve_highest_point(12)
  diameter3 = max(max_len)

  assert diameter1 == diameter2 == diameter3, (diameter1, diameter2, diameter3)
