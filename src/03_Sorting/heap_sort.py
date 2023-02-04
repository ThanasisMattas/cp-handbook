import heapq


v = [6, 1, 6, 3, 8, 2, 1, 9, 5, 6]
heapq.heapify(v)
while v:
  print(heapq.heappop(v), end=' ')
print()
