#include <bits/stdc++.h>
using namespace std;


void print_set(int x)
{
  if (!x) cout << "\u2205";

  for (int i = 0; i < 32; ++i) {
    if (x & (1 << i)) cout << i << ' ';
  }

  cout << '\n';
}


void solve()
{
  cout << "Set representation\n";
  cout << "-------------------\n";
  int A = (1 << 1) | (1 << 3) | (1 << 4) | (1 << 8);
  int B = (1 << 3) | (1 << 6) | (1 << 8) | (1 << 9);

  cout << "int A = " << A << " :\n" << bitset<32>(A) << '\n';
  cout << "int B = " << B << " :\n" << bitset<32>(B) << '\n';
  cout << "A : ";
  print_set(A);
  cout << "B : ";
  print_set(B);

  cout << '\n';
  cout << "Set operations\n";
  cout << "--------------\n";

  cout << "A | B : ";
  print_set(A | B);

  cout << "A & B : ";
  print_set(A & B);

  cout << "A \\ B : ";
  print_set(A & ~B);

  cout << "   ~A : ";
  print_set(~A);

  int n = 4;

  cout << '\n';
  cout << "Iterating through subsets\n";
  cout << "-------------------------\n";
  cout << "Subsets of ";
  print_set((1 << n) - 1);
  for (int b = 0; b < (1 << n); ++b) print_set(b);

  cout << '\n';

  cout << "2-element subsets of ";
  print_set((1 << n) - 1);
  for (int b = 0; b < (1 << n); ++b)
    if (__builtin_popcount(b) == 2) print_set(b);

  cout << '\n';

  int x = 85;
  cout << "int x = " << x << " :\n" << bitset<32>(x) << '\n';
  cout << "Subsets of x: ";
  print_set(x);
  int b = 0;
  do {print_set(b);} while ((b = (b - x) & x));
}


int main() {solve();}
