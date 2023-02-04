#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;


template <typename T>
ostream& operator<<(ostream& out, const vector<T>& v)
{
  if (!v.empty()) copy(v.begin(), v.end(), ostream_iterator<T>(out, " "));
  return out;
}


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
