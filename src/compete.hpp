#ifndef COMPETE_HPP
#define COMPETE_HPP

#include <bits/stdc++.h>
using namespace std;


// Generic operator<< overload for iterable containers
template <
  typename Container,
  typename = typename enable_if<
    !is_same<Container, string>::value  // string has an overload already
        && is_convertible<
          typename Container::const_iterator,
          typename Container::const_iterator
        >::value // hack to check if Container has a valid const_iterator
  >::type // if false, SFINAE excludes the function from overload resolution
>
ostream& operator<<(ostream& out, const Container& container) {
    if (!container.empty()) {
        auto it = container.begin();
        out << *it;  // print first element
        for (++it; it != container.end(); ++it) {
            out << " " << *it;
        }
    }
    return out;
}


template <typename T>
ostream& operator<<(ostream& out, const vector<vector<T> >& v)
{
  if (!v.empty()) {
    auto it = v.begin();
    // print first line
    out << *it;
    for (++it; it != v.end(); ++it) {
      out << '\n' << *it;
    }
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
