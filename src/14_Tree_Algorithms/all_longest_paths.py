# finds the longest path to leaf for all nodes

adj = [
  [],
  [2, 3, 4],
  [1, 5, 6],
  [1],
  [1],
  [2],
  [2]
]
len_1 = [0] * len(adj)
len_2 = [0] * len(adj)
max_len_through_this_child = [0] * len(adj)


# O(n)
# Finds the lengths of the 2 longest paths, that go though the children of
# each node.
def part_1(u, u_prev=0):
  # base case: u is a leaf
  if (len(adj[u]) == 1) and (adj[u][0] == u_prev):
    if len_1[u_prev] == 0:
      len_1[u_prev] = 1
    else:
      len_2[u_prev] = 1
    return

  for u_next in adj[u]:
    if u_next == u_prev:
      continue
    part_1(u_next, u)

    if len_1[u_next] + 1 > len_1[u]:
      len_2[u] = len_1[u]
      len_1[u] = len_1[u_next] + 1
      max_len_through_this_child[u] = u_next
    elif len_1[u_next] + 1 > len_2[u]:
      len_2[u] = len_1[u_next] + 1



# O(n)
# Finds the lengths of the 2 longest paths, that go through the children or
# the parent of each node.
def part_2(u, u_prev=0):
  if max_len_through_this_child[u_prev] == u:
    # then, max_len of u_prev goes through u, namely:
    # len_1[u_prev] = len_1[u] + 1
    if len_2[u_prev] + 1 > len_1[u]:
      len_2[u] = len_1[u]
      len_1[u] = len_2[u_prev] + 1
      max_len_through_this_child[u] = u_prev
  elif len_1[u_prev] + 1 > len_1[u]:
    len_2[u] = len_1[u]
    len_1[u] = len_1[u_prev] + 1
    max_len_through_this_child[u] = u_prev

  for u_next in adj[u]:
    if u_next != u_prev:
      part_2(u_next, u)


if __name__ == '__main__':
  part_1(1)
  part_2(1)
  for i, length in enumerate(len_1):
    if i:
      print(i, ':', length)