#include <bits/stdc++.h>
#include "../compete.hpp"
using namespace std;


vector<int> v{1, 3, 4, 8, 6, 1, 4, 2};
int q;
int a, b;


void solve()
{
  // cumulative vector
  vector<int> cumsum(v.size());
  partial_sum(v.begin(), v.end(), cumsum.begin());

  cout << "Give number of queries: ";
  cin >> q;

  cout << v << '\n';

  while (q--) {
    cout << "Give subset limits: ";
    cin >> a >> b;
    cout << "Subset sum: " << cumsum[b] - cumsum[a] + v[a] << '\n';
  }
}


int main() {solve();}
