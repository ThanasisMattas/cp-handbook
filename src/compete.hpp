#ifndef COMPETE_HPP
#define COMPETE_HPP

#include <bits/stdc++.h>
using namespace std;


template <typename T>
ostream& operator<<(ostream& out, const vector<T>& v)
{
  if (!v.empty()) {
    copy(v.begin(), v.end(), ostream_iterator<T>(out, " "));
    out << "\b";
  }
  return out;
}


template <typename T>
ostream& operator<<(ostream& out, const vector<vector<T> >& v)
{
  const size_t n = v.size();
  if (n > 0) {
    for (size_t i = 0; i < n - 1; ++i) out << v[i] << '\n';
    out << v[n - 1];
  }
  return out;
}


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


// usage: add this inside the scope to be timed
// Timer t(__func__);
struct Timer
{
  chrono::high_resolution_clock::time_point start;
  string name;

  Timer(string n="")
  : start(chrono::high_resolution_clock::now()), name(n) {}

  ~Timer()
  {
    chrono::duration<float> d = chrono::high_resolution_clock::now() - start;
    cout << name
         << string(int(!name.empty()), ' ')
         << "duration: "
         << fixed
         << setprecision(3)
         << (d.count() * 1000.0f)
         << "ms"
         << '\n';
  }
};


#endif
