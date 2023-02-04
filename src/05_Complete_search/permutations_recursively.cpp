#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;


template <typename T>
ostream& operator<<(ostream& out, const vector<T>& v)
{
  if (!v.empty()) copy(v.begin(), v.end(), ostream_iterator<T>(out, " "));
  return out;
}


const int n = 5;
vector<int> perm;
vector<bool> chosen(n);


void solve()
{
  if (perm.size() == n) cout << perm << '\n';
  else {
    for (int i = 0; i < n; ++i) {
      if (chosen[i]) continue;
      chosen[i] = true;
      perm.push_back(i);
      solve();
      chosen[i] = false;
      perm.pop_back();
    }
  }
}


void solve2()
{
  vector<int> perm(n);
  iota(perm.begin(), perm.end(), 0);
  do {
    cout << perm << '\n';
  } while (next_permutation(perm.begin(), perm.end()));
}

// Unpacking the recursion
// void search2(int n, vector<int>& perm, vector<bool>& chosen)
// {
//   if (perm.size() == n) {
//     cout << perm << endl;
//   } else {
//     for (int i = 0; i < n; ++i) {
//       if (chosen[i]) continue;               // i = 0
//       chosen[i] = true;                      // [t, f, f]
//       perm.push_back(i);                     // [0]
//       search(n, perm, chosen);
//         for (int i = 0; i < n; ++i) {
//           if (chosen[i]) continue;             // i = 1
//           chosen[i] = true;                    // [t, t, f]
//           perm.push_back(i);                   // [0, 1]
//           search(n, perm, chosen);
//             for (int i = 0; i < n; ++i) {
//               if (chosen[i]) continue;           // i = 2
//               chosen[i] = true;                  // [t, t, t]
//               perm.push_back(i);                 // [0, 1, 2]
//               search(n, perm, chosen);
//                 cout << perm << endl;              // cout << [0, 1, 2]
//               chosen[i] = false;                 // [t, t, f]
//               perm.pop_back();                   // [0, 1]
//             }
//           chosen[i] = false;                   // [t, f, f]
//           perm.pop_back();                     // [0]
//           // i = 2
//           if (chosen[i]) continue;             // i = 2
//           chosen[i] = true;                           // [t, f, t]
//           perm.push_back(i);                   // [0, 2]
//           search(n, perm, chosen);
//             for (int i = 0; i < n; ++i) {
//               if (chosen[i]) continue;           // i = 1
//               chosen[i] = true;                  // [t, t, t]
//               perm.push_back(i);                 // [0, 2, 1]
//               search(n, perm, chosen);
//                 cout << perm << endl;              // cout << [0, 2, 1]
//               chosen[i] = false;                 // [t, f, t]
//               perm.pop_back();                   // [0, 2]
//             }
//           chosen[i] = false;                   // [t, f, f]
//           perm.pop_back();                     // [0]
//         }
//       chosen[i] = false;                     // [f, f, f]
//       perm.pop_back();                       // []

//       // i = 1
//       if (chosen[i]) continue;               // i = 1
//       chosen[i] = true;                      // [f, t, f]
//       perm.push_back(i);                     // [1]
//       search(n, perm, chosen);
//         for (int i = 0; i < n; ++i) {
//           if (chosen[i]) continue;             // i = 0
//           chosen[i] = true;                    // [t, t, f]
//           perm.push_back(i);                   // [1, 0]
//           search(n, perm, chosen);
//             for (int i = 0; i < n; ++i) {
//               if (chosen[i]) continue;           // i = 2
//               chosen[i] = true;                  // [t, t, t]
//               perm.push_back(i);                 // [1, 0, 2]
//               search(n, perm, chosen);
//                 cout << perm << endl;              // cout << [1, 0, 2]
//               chosen[i] = false;                 // [t, t, f]
//               perm.pop_back();                   // [1, 0]
//             }
//           chosen[i] = false;                   // [f, t, f]
//           perm.pop_back();                     // [1]
//           // i = 2
//           if (chosen[i]) continue;             // i = 2
//           chosen[i] = true;                    // [f, t, t]
//           perm.push_back(i);                   // [1, 2]
//           search(n, perm, chosen);
//             for (int i = 0; i < n; ++i) {
//               if (chosen[i]) continue;           // i = 0
//               chosen[i] = true;                  // [t, t, t]
//               perm.push_back(i);                 // [1, 2, 0]
//               search(n, perm, chosen);
//                 cout << perm << endl;              // cout << [1, 2, 0]
//               chosen[i] = false;                 // [f, t, t]
//               perm.pop_back();                   // [1, 2]
//             }
//           chosen[i] = false;                   // [f, t, f]
//           perm.pop_back();                     // [1]
//         }
//       chosen[i] = false;                     // [f, f, f]
//       perm.pop_back();                       // []

//       // i = 2
//       if (chosen[i]) continue;               // i = 2
//       chosen[i] = true;                      // [f, f, t]
//       perm.push_back(i);                     // [2]
//       search(n, perm, chosen);
//         for (int i = 0; i < n; ++i) {
//           if (chosen[i]) continue;             // i = 0
//           chosen[i] = true;                    // [t, f, t]
//           perm.push_back(i);                   // [2, 0]
//           search(n, perm, chosen);
//             for (int i = 0; i < n; ++i) {
//               if (chosen[i]) continue;           // i = 1
//               chosen[i] = true;                  // [t, t, t]
//               perm.push_back(i);                 // [2, 0, 1]
//               search(n, perm, chosen);
//                 cout << perm << endl;              // cout << [2, 0, 1]
//               chosen[i] = false;                 // [t, f, t]
//               perm.pop_back();                   // [2, 0]
//             }
//           chosen[i] = false;                   // [f, f, t]
//           perm.pop_back();                     // [2]
//           // i = 1
//           if (chosen[i]) continue;             // i = 1
//           chosen[i] = true;                    // [f, t, t]
//           perm.push_back(i);                   // [2, 1]
//           search(n, perm, chosen);
//             for (int i = 0; i < n; ++i) {
//               if (chosen[i]) continue;           // i = 0
//               chosen[i] = true;                  // [t, t, t]
//               perm.push_back(i);                 // [2, 1, 0]
//               search(n, perm, chosen);
//                 cout << perm << endl;              // cout << [2, 1, 0]
//               chosen[i] = false;                 // [f, t, t]
//               perm.pop_back();                   // [2, 1]
//             }
//           chosen[i] = false;                   // [f, f, t]
//           perm.pop_back();                     // [2]
//         }
//       chosen[i] = false;                     // [f, f, f]
//       perm.pop_back();                       // []
//     }
//   }
// }


int main() {solve();}
