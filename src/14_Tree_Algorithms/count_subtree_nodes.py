from tree_examples import adj

counter = [0] * len(adj)


def dfs(u, u_prev):
  counter[u] = 1
  for u_next in adj[u]:
    if u_next == u_prev:
      continue
    dfs(u_next, u)
    counter[u] += counter[u_next]


if __name__ == '__main__':
  dfs(1, 0)
  n_len = len(str(len(adj)))
  for u, c in enumerate(counter[1:]):
    print(f"{u:>{n_len}}", ':', f"{c:>{n_len}}")
