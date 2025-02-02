v = [2, 4, 5, 9]


def solve():
  n = len(v)
  # 1 << n = 15 ({1111} – the complete set)
  for b in range(1 << n):
    sub = set()
    for i in range(n):
      if b & (1 << i):
        sub.add(v[i])
    print(sub)


if __name__ == '__main__':
  solve()
