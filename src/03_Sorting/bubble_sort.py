v = [-1, 2, 4, -3, 5, 2, -5, 2]


def buble_sort():
  swapped = True
  while swapped:
    swapped = False
    for j in range(len(v) - 1):
      if v[j] > v[j + 1]:
        v[j], v[j + 1] = v[j + 1], v[j]
        swapped = True


if __name__ == '__main__':
  print(v)
  buble_sort()
  print(v)
