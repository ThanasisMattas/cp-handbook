from collections import deque

adj = [
  [],
  [2],
  [3],
  [6],
  [1, 5],
  [2, 3],
  []
]
n = len(adj) - 1
state = [0] * (n + 1)
top_sort = deque()


# O(V+E)
def dfs(u) -> bool:
  """Returns True if a cycle is detected, False otherwise."""
  if state[u] == 1:
    # cycle detected
    return True
  if state[u] == 2:
    # already processed
    return False

  # under processing
  state[u] = 1
  for v in adj[u]:
    if dfs(v):
      return True

  # fully processed
  state[u] = 2
  top_sort.appendleft(u)
  return False


# O(V+E)
def solve():
  for u in range(1, n + 1):
    if dfs(u):
      print("Cycle detected")
      return
  print(top_sort)


if __name__ == '__main__':
  solve()

  # cleanup and introduce a cycle (reverse edge (5, 3))
  top_sort.clear()
  state = [0] * len(adj)
  adj[3] = [5, 6]
  adj[5] = [2]

  solve()
