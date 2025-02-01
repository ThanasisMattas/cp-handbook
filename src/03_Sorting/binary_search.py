from bisect import bisect_left

v = [-5, -3, -1, 2, 2, 4, 5]
x = 4

def binary_search():
  return bisect_left(v, x)


if __name__ == '__main__':
  # v.sort()
  print(v)
  print(binary_search())
