# tip: focus on brute force and dp

n = 3
value = [3, 1, 4, 5, 5, 1, 3, 3]

# subsets:
# 0: /     000
# 1: 0     001
# 2: 1     010
# 3: 0 1   011
# 4: 2     100
# 5: 0 2   101
# 6: 1 2   110
# 7: 0 1 2 111


# O(2^(2n))
def solve_brute_force():
  # subsets of g are <= g
  # (s & g) == s: check if s is subset of g
  for g in range(1 << n):
    yield sum(value[s] for s in range(g + 1) if (s & g) == s)


# O(2^n)
# We can only construct subsets of s by removing elements 0...k from s.
# total[s] = partial(s, n - 1)
# partial(s, -1) = value[s]
def partial(s, k):
  """
  k                             s
                 /                               \
  k-1           s                                s-{k}
          /            \                   /               \
  k-2    s             s-{k-1}           s-{k}             s-{k,k-1}
        / \             / \               / \                 / \
  k-3  s  s-{k-2} s-{k-1} s-{k-1,k-2} s-{k} s-{k,k-2} s-{k,k-1} s-{k,k-1,k-2}
  """
  if k == -1:
    return value[s]
  if s & (1 << k):
    return partial(s, k - 1) + partial(s ^ (1 << k), k - 1)
  return partial(s, k - 1)


# O(2^(2n))
def solve_rec():
  for s in range(1 << n):
    yield partial(s, n - 1)


total = value.copy()


# O(n2^n)
def solve_dp():
  for k in range(n):
    for s in range(1 << n):
      if s & (1 << k):
        total[s] += total[s ^ (1 << k)]


if __name__ == '__main__':
  ans_brute_force = ' '.join(map(str, solve_brute_force()))
  ans_recersive = ' '.join(map(str, solve_rec()))
  solve_dp()
  ans_dp = ' '.join(map(str, total))

  assert ans_brute_force == ans_recersive == ans_dp
  print("brute force:", ans_brute_force)
  print("recursive  :", ans_recersive)
  print("dp         :", ans_dp)
