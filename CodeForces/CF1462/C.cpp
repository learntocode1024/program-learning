// CodeForces/CF1462/C.cpp
// Author: learntocode1024
// Date: 12-15-20
// URL: https://codeforces.com/contest/1462/problem/C
// tag: easy
// AC

#include <cstdio>
#include <cstring>
#include <iostream>
#define MX
using std::cin;
using std::cout;
using std::endl;

void solve() {
  int n;
  cin >> n;
  if (n < 10) cout << n << endl;
  else if (n > 45) cout << "-1" << endl;
  else {
    int cnt = 0;
    while (cnt < 9 && n > 9 - cnt) {
      n -= 9 - cnt; cnt++;
    }
    if (n != 0) cout << n;
    while (cnt--) {
      cout << 9 - cnt;
    }
  }
  cout << endl;
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
