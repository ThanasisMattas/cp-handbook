from collections import deque

v = [2, 1, 4, 5, 3, 4, 1, 2]
w = 4
q = deque(maxlen=w)


def print_min(i):
  window = '[' + ' '.join(map(str, v[i - w + 1: i + 1])) + ']'
  queue = '[' + ' '.join(map(str, q)) + ']'
  print(f"min of window {window} with queue {queue:<{2 * w + 1}} is {q[0]}")


# O(n)
def solve():
  n = len(v)

  if w >= n:
    m = 2e9
    for x in v:
      if x < m:
        m = x
    window = ' '.join(map(str, v))
    queue = ' '.join(map(str, v[v.index(m):]))
    print(f"min of window [{window}] with queue [{queue}] is {m}")
    return

  # first window
  for i in range(w):
    while (q) and (q[0] >= v[i]):
      q.popleft()
    q.append(v[i])

  print_min(w - 1)

  for i in range(w, n):
    if len(q) == w:
      q.popleft()
    while (q) and (q[0] >= v[i]):
      q.popleft()
    q.append(v[i])
    print_min(i)


if __name__ == '__main__':
  solve()
