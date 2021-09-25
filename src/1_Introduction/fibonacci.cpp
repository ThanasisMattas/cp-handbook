#include <bits/stdc++.h>
using namespace std;


// O(1)
int fib(int n)
{
  // For fib(0) = 1, the exponent becomes n + 1.
  return floor(pow(1.618034, n) / sqrt(5) + 0.5);
  // Binet's formula:
  // return (pow(1 + sqrt(5), n) - pow(1 - sqrt(5), n)) / (pow(2, n) * sqrt(5));
}


int main()
{
  for (int i = 0; i < 10; ++i)
    cout << fib(i) << '\n';
}
