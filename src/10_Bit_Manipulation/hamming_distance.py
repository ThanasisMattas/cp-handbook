from itertools import combinations

bitstrings = [
  "01110001",
  "10100101",
  "11101001",
  "01001001",
  "10101111",
  "01100111",
  "10111101",
  "01010101",
  "10110001",
  "11111000"
]


# O(n^2) - combinations: C(n,2) = n(n-1)/2
def solve():
  ints = [int(bitstring, 2) for bitstring in bitstrings]
  return min((a ^ b).bit_count() for a, b in combinations(ints, 2))


if __name__ == '__main__':
  best = solve()
  print(best)
  assert best == 2
