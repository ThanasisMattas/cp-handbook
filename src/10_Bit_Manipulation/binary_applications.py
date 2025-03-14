
def print_bitset(x: int):
  """Prints the binary representation of a base 10 integer."""
  size = x.bit_length() + 2
  bitset = ''
  for i in range(size, -1, -1):
    bitset += '1' if x & (1 << i) else '0'
  print(bitset)


if __name__ == '__main__':
  x = 31
  print(x)
  print_bitset(x)
  print()

  b = 3
  print(f"force 0 at position {b}")
  print(f"{x} &= ~(1 << {b})")
  x &= ~(1 << b)
  print_bitset(x)
  print()

  print(f"force 1 at position {b}")
  print(f"{x} |= (1 << {b})")
  x |= (1 << b)
  print_bitset(x)
  print()

  print(f"flip bit at position {b}")
  print(f"{x} ^= (1 << {b})")
  x ^= (1 << b)
  print_bitset(x)
  print()

  print(f"flip bit at position {b}")
  print(f"{x} ^= (1 << {b})")
  x ^= (1 << b)
  print_bitset(x)
  print()
  print()

  x = 12
  print(x)
  print_bitset(x)
  print()

  print("keep only the first 1 bit")
  print("x & -x")
  print_bitset(x & -x)
  print()

  print("fill all trailing zeros with 1")
  print("x | (x - 1)")
  print_bitset(x | (x - 1))
  print()

  print("flip first 1 bit")
  print("x & (x - 1)")
  print_bitset(x & (x - 1))
  print()
  print("also used to identify a power of 2")
  print(">> x & (x - 1) == 0")
  print(x & (x - 1) == 0)
  x = 1 << 3
  print("x = 1 << 3")
  print_bitset(x)
  print(">> x & (x - 1) == 0")
  print(x & (x - 1) == 0)
  print()
  print()

  x = 24
  print(x)
  print(f">> bin({x})")
  print(bin(x))
  print()

  print("count 1's")
  print(">> x.bit_count()")
  print(x.bit_count())
  print(">> bin(x).count('1')")
  print(bin(x).count('1'))
  print()

  print("count trailing zeros")
  print(">> (x & -x).bit_length() - 1 if x else 32")
  print((x & -x).bit_length() - 1 if x else 32)
  print()

  print("count leading zeros")
  print(">> 32 - x.bit_length() if x else 32")
  print(32 - x.bit_length() if x else 32)
  print()

  print("parity (1 if popcount is odd, 0 if even)")
  print(">> x.bit_count() % 2")
  print(x.bit_count() % 2)
  print()
  print()

  print("empty set")
  print("x = 0")
  print()

  x = 0
  print("create set {1, 3, 4, 8}:")
  print("x = (1 << 1) | (1 << 3) | (1 << 4) | (1 << 8)")
  x = (1 << 1) | (1 << 3) | (1 << 4) | (1 << 8)
  print(x)
  print(bin(x))
  print()

  print("x.bit_count()")
  print(x.bit_count())
  print()

  print("print subsets - 1")
  # O(bit_length * 2^bit_length)
  for b in range(1 << x.bit_length()):
    if b | x == x:
      sub = set()
      for i in range(x.bit_length()):
        if b & (1 << i):
          sub.add(i)
      print(sub)
  print()

  # alternative (best one) - especially if you have the original set
  # unpack the set
  s = []
  for i in range(x.bit_length()):
    if x & (1 << i):
      s.append(i)
  n = len(s)  # = x.bit_count()


  # O(bit_count * 2^bit_count)
  print("print subsets - 2")
  for b in range(1 << n):
    sub = set()
    for i in range(n):
      if b & (1 << i):
        sub.add(s[i])
    print(sub)
  print()

  # another alternative
  # O(bit_count * 2^bit_count)
  print("print subsets - 3")
  num_subs = (1 << n) - 1  # 2^bit_count
  b = 0
  while True:
    sub = set()
    for i in range(n):
      if b & (1 << i):
        sub.add(s[i])
    print(sub)

    # next subset
    b = (b - num_subs) & num_subs

    if not b:
      break

  print()
  size = 3
  print(f"print subsets of size {size}")
  for b in range(1 << x.bit_count()):
    if b.bit_count() == size:
      sub = set()
      for i in range(x.bit_count()):
        if b & (1 << i):
          sub.add(s[i])
      print(sub)
