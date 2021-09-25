#include <bits/stdc++.h>

using namespace std;


ostream& operator<<(ostream& out, const vector<int>& v)
{
  out << '[';
  if (!v.empty()) {
    copy(v.begin(), v.end(), ostream_iterator<int>(out, ", "));
    out << "\b\b";
  }
  out << ']';
  return out;
}


vector<int> subset;
const int n = 4;

void solve(int k = 0)
{
  if (k == n) {
    cout << subset << endl;
  } else {
    solve(k + 1);
    subset.push_back(k);
    solve(k + 1);
    subset.pop_back();
  }
}


// Unpacking the recursion
// {
//   if (k == n) {
//     cout << subset << endl;
//   }
//   else {
//     solve(k + 1);        // k = 0
//       solve(k + 1);        // k = 1
//         solve(k + 1);        // k = 2
//           cout << subset << endl;          // cout << []
//         subset.push_back(k);             // [2]
//         solve(k + 1);
//           cout << subset << endl;          // cout << [2]
//         subset.pop_back();               // []
//       subset.push_back(k);             // [1]
//       solve(k + 1);        // k = 1
//         solve(k + 1);        // k = 2
//           cout << subset << endl;          // cout << [1]
//         subset.push_back(k);             // [1, 2]
//         solve(k + 1);
//           cout << subset << endl;          // cout << [1, 2]
//         subset.pop_back();               // [1]
//       subset.pop_back();               // []
//     subset.push_back(k);             // [0]

//     solve(k + 1);        // k = 0
//       solve(k + 1);        // k = 1
//         solve(k + 1);        // k = 2
//           cout << subset << endl;          // cout << [0]
//         subset.push_back(k);             // [0, 2]
//         solve(k + 1);
//           cout << subset << endl;          // cout << [0, 2]
//         subset.pop_back();               // [0]
//       subset.push_back(k);             // [0, 1]
//       solve(k + 1);        // k = 1
//         solve(k + 1);        // k = 2
//           cout << subset << endl;          // cout << [0, 1]
//         subset.push_back(k);             // [0, 1, 2]
//         solve(k + 1);
//           cout << subset << endl;          // cout << [0, 1, 2]
//         subset.pop_back();               // [0, 1]
//       subset.pop_back();               // [0]
//     subset.pop_back();               // []
//     ///////////////////////////////////////////////////////////////////////////
//     // n = 4
//     solve(k + 1);        // k = 0
//       solve(k + 1);        // k = 1
//         solve(k + 1);        // k = 2
//           solve(k + 1);        // k = 3
//             cout << subset << endl;          // cout << []
//           subset.push_back(k);             // [3]
//           solve(k + 1);
//             cout << subset << endl;          // cout << [3]
//           subset.pop_back();               // []
//         subset.push_back(k);             // [2]
//         solve(k + 1);        // k = 2
//           solve(k + 1);        // k = 3
//             cout << subset << endl;          // cout << [2]
//           subset.push_back(k);             // [2, 3]
//           solve(k + 1);
//             cout << subset << endl;          // cout << [2, 3]
//           subset.pop_back();               // [2]
//         subset.pop_back();               // []
//       subset.push_back(k);             // [1]
//       solve(k + 1);        // k = 1
//         solve(k + 1);        // k = 2
//           solve(k + 1);        // k = 3
//             cout << subset << endl;          // cout << [1]
//           subset.push_back(k);             // [1, 3]
//           solve(k + 1);        // k = 3
//             cout << subset << endl;          // cout << [1, 3]
//           subset.pop_back();               // [1]
//         subset.push_back(k);             // [1, 2]
//         solve(k + 1);        // k = 2
//           solve(k + 1);        // k = 3
//             cout << subset << endl;          // cout << [1, 2]
//           subset.push_back(k);             // [1, 2, 3]
//           solve(k + 1);
//             cout << subset << endl;          // cout << [1, 2, 3]
//           subset.pop_back();               // [1, 2]
//         subset.pop_back();               // [1]
//       subset.pop_back();               // []
//     subset.push_back(k);             // [0]

//     solve(k + 1);        // k = 0
//       solve(k + 1);        // k = 1
//         solve(k + 1);        // k = 2
//           solve(k + 1);        // k = 3
//             cout << subset << endl;          // cout << [0]
//           subset.push_back(k);             // [0, 3]
//           solve(k + 1);
//             cout << subset << endl;          // cout << [0, 3]
//           subset.pop_back();               // [0]
//         subset.push_back(k);             // [0, 2]
//         solve(k + 1);        // k = 2
//           solve(k + 1);        // k = 3
//             cout << subset << endl;          // cout << [0, 2]
//           subset.push_back(k);             // [2, 3]
//           solve(k + 1);
//             cout << subset << endl;          // cout << [0, 2, 3]
//           subset.pop_back();               // [0, 2]
//         subset.pop_back();               // [0]
//       subset.push_back(k);             // [0, 1]
//       solve(k + 1);        // k = 1
//         solve(k + 1);        // k = 2
//           solve(k + 1);        // k = 3
//             cout << subset << endl;          // cout << [0, 1]
//           subset.push_back(k);             // [0, 1, 3]
//           solve(k + 1);        // k = 3
//             cout << subset << endl;          // cout << [0, 1, 3]
//           subset.pop_back();               // [0, 1]
//         subset.push_back(k);             // [0, 1, 2]
//         solve(k + 1);        // k = 2
//           solve(k + 1);        // k = 3
//             cout << subset << endl;          // cout << [0, 1, 2]
//           subset.push_back(k);             // [0, 1, 2, 3]
//           solve(k + 1);
//             cout << subset << endl;          // cout << [0, 1, 2, 3]
//           subset.pop_back();               // [0, 1, 2]
//         subset.pop_back();               // [0, 1]
//       subset.pop_back();               // [0]
//     subset.pop_back();               // []
//   }
// }


int main()
{
  solve();
}
