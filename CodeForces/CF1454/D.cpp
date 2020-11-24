// CodeForces/CF1454/D.cpp
// https://codeforces.com/contest/1454/problem/A/problem/B/problem/C/problem/D
// Created by learntocode1024 on 11/24/20.
// AC

#include <cstdio>
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

void solve() {
  long long n;
  cin >> n;
  long long out = n, ans = 1, tmp, prime = n;
  for (long long kI = 2; kI * kI <= n; ++kI) {
    if (n % kI == 0) {
      tmp = 0;
      while (n % kI == 0) {
        n /= kI;
        ++tmp;
      }
      if (tmp > ans) {
        ans = tmp;
        prime = kI;
      }
    }
  }
  cout << ans << '\n';
  for (int kI = 1; kI < ans; ++kI) {
    cout << prime << ' ';
    out /= prime;
  }
  cout << out << '\n';
}

int main() {
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
  cout << endl;
  return 0;
}
