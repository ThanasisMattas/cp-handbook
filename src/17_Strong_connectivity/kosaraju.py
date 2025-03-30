adj = [
  [],
  [2, 4],
  [1, 5],
  [2, 7],
  [],
  [4],
  [3, 5],
  [6]
]


# O(V + E)
def dfs(start, visited):
  """Post-Order DFS

  It forces leaf -> root sorting, forming a flattened SCC (Strongly Connected
  Component) sequence.
  """
  stack = [start]
  postorder = []

  while stack:
    u = stack[-1]
    # u is popped after all of its neighbors are popped, forcing post-order.
    if visited[u]:
      stack.pop()
      postorder.append(u)
    else:
      visited[u] = True
      for v in adj[u]:
        if not visited[v]:
          stack.append(v)

  return postorder


# O(V + E)
def kosaraju():
  n = len(adj) - 1

  # 1st pass
  #   Since nodes are naturally ordered, each DFS run groups reachable nodes
  #   from each starting node. After flattening, we get the total post-order.
  visited = [False] * (n + 1)
  postorder = [dfs(u, visited) for u in range(1, n + 1) if not visited[u]]
  postorder = [u for reachable in postorder for u in reachable]

  # 2nd pass
  #   The post-order from the first pass already placed SCCs contiguously.
  #   Thus, the reachable groups now will essentially be the SCCs. This
  #   implementation avoids the reversal of the adjacency list from the
  #   original algorithm.
  visited = [False] * (n + 1)
  return [dfs(u, visited) for u in postorder if not visited[u]]


if __name__ == '__main__':
  print(kosaraju())
