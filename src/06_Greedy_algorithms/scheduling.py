from operator import itemgetter


events = [
    (1, 3),
    (2, 5),
    (3, 9),
    (6, 8)
]


# O(nlogn)
def solve():
  # events should be sorted by end time
  events.sort(key=itemgetter(1))
  scheduled = []
  last_end_time = -1

  for event in events:
    if event[0] >= last_end_time:
      scheduled.append(event)
      last_end_time = event[1]

  return scheduled


if __name__ == '__main__':
  scheduled = solve()
  print(scheduled)
  assert scheduled == [(1, 3), (6, 8)]
