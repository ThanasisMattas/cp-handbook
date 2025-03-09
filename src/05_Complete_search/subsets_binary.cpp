#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
#include "../compete.hpp"
using namespace std;


const vector<int> v{2, 4, 5, 9};


void solve()
{
  const int n = v.size();
  for (int b = 0; b < (1 << n); ++b){
    vector<int> sub;
    for (int j = 0; j < n; ++j)
      if (b & (1 << j)) sub.push_back(v[j]);
    cout << bitset<4>(b) << ' ' <<  sub << '\n';
  }
}


int main() {solve();}
