from collections import deque
import math


def adjList(n, edges):
  adj = [set() for _ in range(n + 1)]
  for edge in edges:
    adj[edge[0]].add(edge[1])
    adj[edge[1]].add(edge[0])
  return adj


# O(V+E), V: num vertices  E: num edges
def bfs(adj, start):
  n = len(adj)
  visited = [False] * n
  visited[start] = True
  q = deque([start])
  seq = []

  while q:
    u = q.popleft()
    seq.append(u)
    for v in adj[u]:
      if visited[v]:
        continue
      visited[v] = True
      q.append(v)

  return seq


# O(V+E), V: num vertices  E: num edges
def dfs(adj, start):
  n = len(adj)
  visited = [False] * n
  visited[start] = True
  stack = [start]
  seq = []

  while stack:
    u = stack.pop()
    seq.append(u)
    for v in adj[u]:
      if visited[v]:
        continue
      visited[v] = True
      stack.append(v)

  return seq


def bfs_rec(adj, visited=None, cost=None, queue=None, start=None):
  """call: bfs_rec(adj, start=start)"""
  if visited is None:
    n = len(adj)
    cost = [math.inf] * (n + 1)
    cost[start] = 0
    visited = [False for _ in range(n + 1)]
    visited[start] = True
    queue = deque([start])
  if queue:
    u = queue.popleft()
    for v in adj[u]:
      if not visited[v]:
        visited[v] = True
        queue.append(v)
        cost[v] = cost[u] + 1
    return bfs_rec(adj, visited, cost, queue)
  return cost


def dfs_rec(u, adj, visited):
  # process u
  visited[u] = True
  for v in adj[u]:
    if not visited[v]:
      dfs_rec(v, adj, visited)


# No need for visited flag. Just do not go back to the parent node.
def dfs_rec_tree(adj, u, u_prev):
  # process u
  for u_next in adj[u]:
    if u_next != u_prev:
      dfs_rec_tree(adj, u_next, u)


def main():
  adj_1 = [
    [],
    [2, 6, 10],
    [1, 3, 5],
    [2, 4],
    [3, 5, 6],
    [2, 4],
    [1, 4, 7],
    [6, 8, 12],
    [7, 9, 12],
    [10, 8, 11],
    [1, 9],
    [9],
    [7, 8]
  ]

  adj_2 = [
    [],
    [2, 3, 4],
    [1, 5, 6],
    [1, 7, 8],
    [1, 9],
    [2, 7],
    [2, 7],
    [5, 6, 3],
    [3, 10, 11],
    [4, 11, 12],
    [8, 11],
    [8, 9, 10],
    [9]
  ]
  seq1 = dfs(adj_1, 1)
  print(seq1)
  assert seq1 == [1, 10, 9, 11, 8, 12, 7, 6, 4, 5, 3, 2]
  seq2 = dfs(adj_2, 1)
  print(seq2)
  assert seq2 == [1, 4, 9, 12, 11, 10, 8, 3, 7, 6, 5, 2]


  seq3 = bfs(adj_1, 1)
  print(seq3)
  assert seq3 == [1, 2, 6, 10, 3, 5, 4, 7, 9, 8, 12, 11]

  seq4 = bfs(adj_2, 1)
  print(seq4)
  assert seq4 == [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12]

if __name__ == "__main__":
  main()
