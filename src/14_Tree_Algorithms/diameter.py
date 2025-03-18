import random

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

# len to farthest leaf
to_leaf = [0] * len(adj)
# max len of the paths with the i node as the highest point
max_len = [0] * len(adj)


# O(n)
def solve_highest_point(u, u_prev):
  # In order to be a leaf, the single neighbor has to be u_prev.
  if (len(adj[u]) == 1) and (adj[u][0] == u_prev):
    to_leaf[u_prev] = max(to_leaf[u_prev], 1)
    return

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


if __name__ == '__main__':
  solve_highest_point(random.randint(1, len(adj)), 0)
  print("diameter:", max(max_len))
