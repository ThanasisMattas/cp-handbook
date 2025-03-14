#include <bits/stdc++.h>
using namespace std;


void solve()
{
  cout << "              INT_MAX : " << bitset<32>(INT_MAX) << '\n';
  cout << "              INT_MIN : " << bitset<32>(INT_MIN) << '\n';
  cout << "             UINT_MAX : " << bitset<32>(UINT_MAX) << '\n';
  cout << "             UINT_MIN : "
  << bitset<32>(numeric_limits<unsigned>::min())
  << '\n';
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Woverflow"
  cout << "          INT_MAX + 1 : " << bitset<32>(INT_MAX + 1) << '\n';
  cout << "         UINT_MAX + 1 : " << bitset<32>(UINT_MAX + 1) << '\n';
  #pragma GCC diagnostic pop

  cout << '\n';
  int x = 84;

  cout << "           int x = " << x << " : " << bitset<32>(x) << '\n';
  cout << "                   -x : " << bitset<32>(-x) << '\n';
  // cout << "                   -x : " << bitset<32>(-x) << '\n';
  cout << "             2^32 - x : "<< bitset<32>(UINT_MAX + 1 - x) << '\n';
  cout << "               x << 2 : " << bitset<32>(x << 2) << '\n';
  cout << "               x >> 3 : " << bitset<32>(x >> 3) << '\n';

  cout << '\n';

  cout << "           int x = " << x << " : " << bitset<32>(x) << '\n';
  cout << "force 1: x | (1 << 3) : " << bitset<32>(x | (1 << 3)) << '\n';
  cout << "force 0:x & ~(1 << 4) : " << bitset<32>(x & ~(1 << 4)) << '\n';
  cout << "   flip: x ^ (1 << 2) : " << bitset<32>(x ^ (1 << 2)) << '\n';

  cout << '\n';

  cout << "           int x = " << x << " : " << bitset<32>(x) << '\n';
  cout << "          x & (x - 1) : " << bitset<32>(x & (x - 1)) << '\n';
  cout << "          x | (x - 1) : " << bitset<32>(x | (x - 1)) << '\n';
  cout << "             x & (-x) : " << bitset<32>(x & (-x)) << '\n';

  cout << '\n';
  x = 4;

  // y & (x - 1) = y % x
  cout << "            int x = " << x << " : " << bitset<32>(x) << '\n';
  cout << "          x & (x - 1) : " << bitset<32>(x & (x - 1)) << '\n';
  cout << "          5 & (x - 1) : " << bitset<32>(5 & (x - 1)) << '\n';
  cout << "          6 & (x - 1) : " << bitset<32>(6 & (x - 1)) << '\n';
  cout << "          7 & (x - 1) : " << bitset<32>(7 & (x - 1)) << '\n';
  cout << "          8 & (x - 1) : " << bitset<32>(8 & (x - 1)) << '\n';

  cout << '\n';
  x = 84;

  cout << "           int x = " << x << " : " << bitset<32>(x) << '\n';
  cout << "     __builtin_clz(x) : " << __builtin_clz(x) << '\n';
  cout << "     __builtin_ctz(x) : " << __builtin_ctz(x) << '\n';
  cout << "__builtin_popcount(x) : " << __builtin_popcount(x) << '\n';
  cout << "  __builtin_parity(x) : " << __builtin_parity(x) << '\n';
}


int main() {solve();}
