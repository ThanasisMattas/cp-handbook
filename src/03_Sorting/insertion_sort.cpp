#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;


template <typename T>
ostream& operator<<(ostream& out, const vector<T> v)
{
  if (!v.empty()) copy(v.begin(), v.end(), ostream_iterator<T>(out, " "));
  return out;
}


vector<int> v{6, 1, 6, 3, 8, 2, 1, 9, 5, 6};


// O(n^2)
int main()
{
  for (int i = 0; i < v.size(); ++i) {
    int j = i;
    while ((j) && (v[j] < v[j - 1])) {
      swap(v[j], v[j - 1]);
      --j;
    }
  }

  cout << v << '\n';
}
