from tree_examples import adj, random_node

# longest path to leaf
to_leaf = [0] * len(adj)


def dfs(u, u_prev=None):
  # In order to be a leaf, the single neighbor has to be u_prev.
  if (len(adj[u]) == 1) and (adj[u][0] == u_prev):
    to_leaf[u_prev] = max(to_leaf[u_prev], 1)
    return

  for u_next in adj[u]:
    if u_next == u_prev:
      continue
    dfs(u_next, u)
    to_leaf[u] = max(to_leaf[u], to_leaf[u_next] + 1)


if __name__ == '__main__':
  node = random_node()
  dfs(node)
  print(f"{node}: {to_leaf[node]}")

