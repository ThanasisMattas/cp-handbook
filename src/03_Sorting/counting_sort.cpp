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
const int c = 10;
vector<int> counter(c + 1);


int main()
{
  for (auto i : v) ++counter[i];
  cout << counter << '\n';
  for (int i = 0; i < counter.size(); ++i)
    for (int j = 0; j < counter[i]; ++j)
      cout << i << ' ';
  cout << '\n';
}
