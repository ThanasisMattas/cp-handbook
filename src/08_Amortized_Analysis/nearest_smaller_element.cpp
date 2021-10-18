#include <bits/stdc++.h>
using namespace std;


template <typename T>
ostream& operator<<(ostream& out, const vector<T>& v)
{
  if (!v.empty()) {
    copy(v.begin(), v.end(), ostream_iterator<T>(out, " "));
    cout << "\b";
  }
  return out;
}


vector<int> v{1, 3, 4, 2, 5, 3, 4, 2, 0, 1};


void solve()
{
  cout << v << '\n';
  cout << "  ";

  stack<int> s;
  s.push(v[0]);

  for (size_t i = 1; i < v.size(); ++i) {
    while ((!s.empty()) && (s.top() >= v[i])) s.pop();
    if (!s.empty()) cout << s.top() << ' ';
    else cout << "- ";
    s.push(v[i]);
  }
  cout << '\n';
}


int main()
{
  solve();
}