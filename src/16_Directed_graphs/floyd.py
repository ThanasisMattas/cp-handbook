#          1  2  3  4  5  6
succ = [0, 2, 3, 4, 5, 6, 4]
#                a
#                         b
n = len(succ) - 1


def floyd(x=succ[1]):
  a = succ[x]
  b = succ[succ[x]]
  while a != b:
    a = succ[a]
    b = succ[succ[b]]

  # After placing pointer a back at x, why will it inevitably meet pointer b at
  # the first node of the cycle, f?
  #
  # If a walked z steps inside the cycle:
  #                           k = f + z =>
  #                           f = k - z
  # which are exactly the steps needed for pointer b to get to f: k is multiple
  # of c, cycling to the same node, -z to get to f.

  a = x
  while a != b:
    a = succ[a]
    b = succ[b]

  b = succ[a]
  length = 1
  while a != b:
    b = succ[b]
    length += 1

  print("first node of the cycle:", a)
  print("length of the cycle:", length)


if __name__ == '__main__':
  floyd()
