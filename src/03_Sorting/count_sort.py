v = [6, 1, 6, 3, 8, 2, 1, 9, 5, 6]
c = 10
counter = [0] * c


# O(n)
def count_sort():
  for x in v:
    counter[x] += 1

  k = 0
  for i, x in enumerate(counter):
    for _ in range(x):
      v[k] = i
      k += 1


if __name__ == '__main__':
  print(v)
  count_sort()
  print(v)
