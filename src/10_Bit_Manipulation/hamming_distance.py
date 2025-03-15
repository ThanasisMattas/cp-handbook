from itertools import combinations
from timeit import timeit

bitstrs = [
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

# O(k), where k is the length of the bitstr
def hamming_dist_str(a: str, b:str) -> int:
  """Can be used with any pair of strings (not just bitstrigns)."""
  if len(a) != len(b):
    raise ValueError("Strings must be of the same length")
  return sum(c1 != c2 for c1, c2 in zip(a, b))


# O(n^2 * k), where k is the length of the bitstr
def solve_str():
  return min(hamming_dist_str(a, b) for a, b in combinations(bitstrs, 2))


# O(n^2) - combinations: C(n,2) = n(n-1)/2
def solve_int():
  ints = [int(bitstr, 2) for bitstr in bitstrs]
  return min((a ^ b).bit_count() for a, b in combinations(ints, 2))


if __name__ == '__main__':
  best_int = solve_int()
  best_str = solve_str()
  print(best_int)
  assert best_int == best_str == 2

  print("str-based time:", end=' ')
  print(round(timeit(solve_str, number=10000), 3))
  print("int-based time:", end=' ')
  print(round(timeit(solve_int, number=10000), 3))
