#include <bits/stdc++.h>
#include "../compete.hpp"
using namespace std;


vector<int> v{2, 1, 4, 5, 3, 4, 1, 2};
const size_t n = 8;
const size_t w = 4;
queue<int> q;


void print_min(int i)
{
  cout << "min of window [";
  copy(v.begin() + i - w + 1,
       v.begin() + i + 1,
       ostream_iterator<int>(cout, " "));
  cout << '\b';
  cout << "] with queue " << q << string(2 * w - 2 * q.size(), ' ')
       << " is " << q.front() << '\n';
}


// O(n)
void solve()
{
  cout << v << '\n';
  // first window
  for (size_t i = 0; i < w; ++i) {
    while ((!q.empty()) && (q.front() >= v[i])) q.pop();
    q.push(v[i]);
  }
  print_min(w - 1);

  for (size_t i = w; i < n; ++i) {
    // pop front, if it fell out of the window
    if (q.size() == w) q.pop();

    while((!q.empty()) && (q.front() >= v[i])) q.pop();
    q.push(v[i]);
    print_min(i);
  }
}


int main() {solve();}
