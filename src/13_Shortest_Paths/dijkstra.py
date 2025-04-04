import heapq
import math


adj = [
  [],
  [(2, 2), (6, 4), (10, 2)],
  [(1, 3), (3, 6), (5, 10)],
  [(2, 4), (4, 22)],
  [(3, 5), (5, 1), (6, 3)],
  [(2, 6), (4, 14)],
  [(1, 1), (4, 8), (7, 1)],
  [(6, 3), (8, 4), (12, 3)],
  [(7, 5), (9, 5), (12, 5)],
  [(10, 8), (8, 8), (11, 1)],
  [(1, 1), (9, 4)],
  [(9, 3)],
  [(7, 5), (8, 3)]
]
start = 1


# O((m + n)logn), n: number of nodes, m: number of edges
def dijkstra():
  visited = [False] * len(adj)
  dist = [math.inf] * len(adj)
  prev = [None] * len(adj)
  dist[start] = 0
  prev[start] = -1
  pq = [(0, start)]
  heapq.heapify(pq)  # min heap by default

  while pq:
    u = heapq.heappop(pq)[1]
    if visited[u]:
      continue
    visited[u] = True
    for v, w in adj[u]:
      if dist[u] + w < dist[v]:
        dist[v] = dist[u] + w
        prev[v] = u
        # The old value will be downstream in the priority queue. If its turn
        # to be popped out comes, it will be ignored, because v will be already
        # marked as visited.
        heapq.heappush(pq, (dist[v], v))
  return [[d, p] for d, p in zip(dist, prev)]


def dijkstra_heap():
  """ignore"""
  visited = [[0, None] for _ in adj]
  to_visit = [[math.inf, u, None] for u in range(len(adj))]
  # references to to_visit entries: used to locate and relax to_visit entries
  entry_finder = {u: entry for u, entry in enumerate(to_visit)}
  entry_finder[start][0] = 0
  entry_finder[start][2] = -1
  heapq.heapify(to_visit)

  while to_visit:
    while True:
      cost, u, u_prev = heapq.heappop(to_visit)
      # check if this entry is already visited
      if u != -1:
        break
    visited[u][0] = cost
    visited[u][1] = u_prev
    for v, uv_cost in adj[u]:
      if ((v in entry_finder)
              and (entry_finder[v][0] > cost + uv_cost)):
        entry = entry_finder.pop(v)
        # flag this entry as removed (to be replaced with the relaxed one)
        entry[1] = -1
        new_entry = [cost + uv_cost, v, u]
        entry_finder[v] = new_entry
        heapq.heappush(to_visit, new_entry)
  return visited


if __name__ == '__main__':
  result1 = dijkstra()
  result2 = dijkstra_heap()
  for u, [d, p] in enumerate(result1):
    if u > 1:
      print(f"{start} -> {u}  cost: {d}  previous node: {p}")

  expected = [
    [math.inf, None],
    [0, -1],
    [2, 1],
    [8, 2],
    [12, 6],
    [12, 2],
    [4, 1],
    [5, 6],
    [9, 7],
    [6, 10],
    [2, 1],
    [7, 9],
    [8, 7]
  ]
  assert result1 == result2 == expected
