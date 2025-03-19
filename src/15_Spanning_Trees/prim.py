import math
import heapq

edge_list = [
  [1, 2, 3],
  [1, 5, 5],
  [2, 5, 6],
  [2, 3, 5],
  [5, 6, 2],
  [3, 6, 3],
  [3, 4, 9],
  [6, 4, 7]
]
m = len(edge_list)
adj = []


def populate_adj():
  for a, b, w in edge_list:
    max_limit = max(a, b)
    if len(adj) - 1 < max_limit:
      for _ in range(max_limit + 1 - len(adj)):
        adj.append([])
    adj[a].append([b, w])
    adj[b].append([a, w])


# O(n + mlog(n))
def prim(start):
  visited = [False] * len(adj)
  dist = [math.inf] * len(adj)
  prev = [None] * len(adj)
  dist[start] = 0
  prev[start] = -1
  # The priority queue at Dijkstra's alg keeps the min distance from start to
  # the node. At Prim's alg, it keeps the min edge length from the node to a
  # neighbor.
  pq = [(0, start)]
  heapq.heapify(pq)
  cost = 0

  while pq:
    w, u = heapq.heappop(pq)
    if visited[u]:
      continue
    visited[u] = True
    cost += w
    if u != start:
      print(prev[u], '-', u)
    for v, w in adj[u]:
      if w < dist[v]:
        dist[v] = w
        prev[v] = u
        heapq.heappush(pq, (w, v))

  print("cost:", cost)

if __name__ == '__main__':
  populate_adj()
  prim(1)
