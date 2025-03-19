
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
  """Attach the smaller set to the larger."""
  a = find(a)
  b = find(b)
  if size[a] < size[b]:
    a, b = b, a
  size[a] += size[b]
  link[b] = a


# O(nlog(n))
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
