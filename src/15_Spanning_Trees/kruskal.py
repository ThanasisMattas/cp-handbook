
from operator import itemgetter

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

# Union-Find or Disjoint Set Union (DSU)
# m should be >= n - 1, so it can be used as length, if n is unknown
link = list(range(m + 1))
size = [1] * (m + 1)


# log(n)
def find(x):
  """Finds the representative of x."""
  while x != link[x]:
    x = link[x]
  return x


# log(n)
def same(a, b):
  """Checks if a, b belong to the same set."""
  return find(a) == find(b)


# log(n)
def unite(a, b):
  """Attach the smaller set to the larger (union by size).

  The depth of most nodes (larger set) stays the same.

  Why log2(n)?
  ------------
  Initially, each element starts as a single-node tree with rank 0. When two
  trees of the same rank r get merged, the resulting rank is r + 1 and the size
  is roughly doubled. Namely, the size of a tree with rank r is roughly 2^r.
  Since the nodes in the set can be at most n, n = 2^r => r = log2(n), which is
  the number of hops to get to the represenative. In practice, all operations
  of Union-Find are much faster, closer to O(1).
  """
  a = find(a)
  b = find(b)
  if size[a] < size[b]:
    a, b = b, a
  size[a] += size[b]
  link[b] = a


# O(mlog(n)) if edge_list is sorted else O(mlog(m))
def kruskal():
  edge_list.sort(key=itemgetter(2))
  cost = 0
  print("MST:")
  for a, b, c in edge_list:
    if not same(a, b):
      # then, this is an MST edge
      cost += c
      unite(a, b)
      print(a, '-', b)
  print("total cost:", cost)


if __name__ == '__main__':
  kruskal()
