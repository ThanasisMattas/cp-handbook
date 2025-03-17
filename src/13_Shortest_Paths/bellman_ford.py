import math

# general case of a directed graph with negative weights
adj = [
  [],
  [[2, 5], [6, 1], [10, 15]],           #  1
  [[1, 1], [3, -2], [5, 3]],            #  2
  [[2, 3], [4, 1], [6, 4]],             #  3
  [[3, 2], [5, 3], [6, 1]],             #  4
  [[2, 3], [4, 8]],                     #  5
  [[1, 1], [4, -1], [7, 8], [10, 16]],  #  6
  [[6, 5], [8, 12], [12, 3]],           #  7
  [[7, 9], [9, 7], [12, -2]],           #  8
  [[10, 3], [8, 1], [11, 11]],          #  9
  [[1, -1], [9, 2]],                    # 10
  [[9, 12]],                            # 11
  [[7, 1], [8, 20]]                     # 12
]
source = 1
n = len(adj) - 1
dist = [math.inf] * (n + 1)
dist[source] = 0


# # O(n + m)
def has_negative_cycle():
  for u in range(1, n + 1):
    for v, w in adj[u]:
      if dist[v] > dist[u] + w:
        return True
  return False


# O(nm)
# This is the SPFA (Shortest Path Faster Algorithm) version, where the
# algorithm is not visiting all the edges at each epoch. Rather, it visits
# only those that their distance was relaxed from infinity, because a path
# to those nodes is not yet constructed, hence it cannot be extended.
def bellman_ford():
  # each shortest path can contain at most n − 1 edges
  for _ in range(n):
    halt = True
    for u in range(1, n + 1):
      if dist[u] != math.inf:
        for v, w in adj[u]:
          dist[v] = min(dist[v], dist[u] + w)
          halt = False
    if halt:
      # In case the graph contains a negative cycle, distances
      # will continue to get minimized until the end of the
      # process. Thus, if the process is halted, for sure there
      # are no negative cycles.
      return True
  return not has_negative_cycle()


def solve():
  if bellman_ford():
    for u in range(1, n + 1):
      print(source, "->", u, ':', dist[u])
  else:
    print("Negative cycle detected")


if __name__ == '__main__':
  solve()
  # introduce a negative cycle
  adj[3][1] = [2, 1]
  print()
  solve()
