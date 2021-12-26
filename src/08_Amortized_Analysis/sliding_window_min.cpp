#include <bits/stdc++.h>
using namespace std;


template <typename T>
ostream& operator<<(ostream& out, queue<T>& q)
{
  out << '[';
  if (!q.empty()) {
    size_t sz = q.size();
    while (sz--) {
      T x = q.front(); q.pop();
      out << x << ' ';
      q.push(x);
    }
    out << '\b';
  }
  out << ']';
  return out;
}


vector<int> v{2, 1, 4, 5, 3, 4, 1, 2};
const size_t w = 4;


void solve()
{
  queue<int> q;
  q.push(v[0]);

  // first window
  for (size_t i = 1; i < w; ++i) {
    while ((!q.empty()) && (q.front() >= v[i])) q.pop();
    q.push(v[i]);
  }

  // Optional print block
  cout << "min of window [ ";
  copy(v.begin(), v.begin() + w, ostream_iterator<int>(cout, " "));
  cout << "] with queue " << q << string(2 * w - 2 * q.size(), ' ')
       << " is " << q.front() << '\n';

  for (size_t i = w; i < v.size(); ++i) {
    // pop front, if it fell out of the window
    if (q.front() == v[i - w]) q.pop();

    while((!q.empty()) && (q.front() >= v[i])) q.pop();
    q.push(v[i]);

    // Optional print block
    cout << "min of window [ ";
    copy(v.begin() + i - w + 1,
         v.begin() + i + 1,
         ostream_iterator<int>(cout, " "));
    cout << "] with queue " << q << string(2 * w - 2 * q.size(), ' ')
         << " is " << q.front() << '\n';
  }
}


int main()
{
  solve();
}