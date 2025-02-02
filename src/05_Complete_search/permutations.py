from itertools import permutations


n = 3


# * r = None (defaults to n)
#     O(n!)
# * r < n, as given from math.perm(n, r):
#     O(n! / (n - r)!)
def solve(r=None):
  for perm in permutations(range(n), r):
    print(perm)


chosen = [False] * n
perm = []


# O(n!)
def solve_recursively():
  if len(perm) == n:
    print(perm)
    return

  for i in range(n):
    if chosen[i]:
      continue
    chosen[i] = True
    perm.append(i)
    solve_recursively()
    chosen[i] = False
    perm.pop()


if __name__ == '__main__':
  solve()
  print()
  solve(2)
  print()
  solve_recursively()
