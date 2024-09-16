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


// amortized O(n)
void solve()
{
  cout << v << '\n';
  stack<int> s;

  for (auto c : v) {
    while ((!s.empty()) && (s.top() >= c)) s.pop();
    if (!s.empty()) cout << s.top() << ' ';
    else cout << "- ";
    s.push(c);
  }
  cout << '\n';
}


int main() {solve();}