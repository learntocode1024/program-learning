// CodeForces/CF1463/A.cpp
// Author: learntocode1024
// Date: 12-17-20
// URL: https://codeforces.com/contest/1463/problem/A
// tag: easy
// AC

#include <cstdio>
#include <algorithm>
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
void solve() {
  int a, b, c, min;
  cin >> a >> b >> c;
  min = std::min(a, std::min(b, c));
  if (a + b + c < 7 || (a + b + c) % 9 || (a + b + c) / 9 > min) {
    cout << "NO" << endl;
  } else
    cout << "YES" << endl;
}

int main() {
  cin.tie(NULL);
  std::ios::sync_with_stdio(false);
  int T = 1;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
