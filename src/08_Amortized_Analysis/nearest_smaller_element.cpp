#include <bits/stdc++.h>
#include "../compete.hpp"
using namespace std;


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