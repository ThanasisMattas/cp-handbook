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
n = len(adj) - 1


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
def kosaraju_pass(nodes=range(1, n + 1)):
  """Each DFS-run groups reachable nodes from each starting node (u)"""
  visited = [False] * (n + 1)
  return [dfs(u, visited) for u in nodes if not visited[u]]


# O(V + E)
def kosaraju():
  # 1st pass
  #   Get reachable groups from each unvisited node in post-order, and flatten.
  postorder = [u for reachable in kosaraju_pass() for u in reachable]

  # 2nd pass
  #   The post-order from the first pass have sorted the nodes from leaf to
  #   root, resulting in placing the SCCs contiguously. Using this sequence at
  #   the second pass, the reachable groups now will be the SCCs.
  #
  #   This implementation avoids the reversal of the adjacency list as with
  #   the original algorithm.
  return kosaraju_pass(postorder)


if __name__ == '__main__':
  print(kosaraju())
