// CodeForces/CF1462/B.cpp
// Author: learntocode1024
// Date: 12-15-20
// URL: https://codeforces.com/contest/1462/problem/B
// tag: easy
// AC

#include <cstdio>
#include <string>
#include <iostream>
#define MX
using std::cin;
using std::cout;
using std::endl;

std::string str;

void solve() {
  int n;
  cin >> n >> str;
  int l = 0, r = 0;
  for (int i = 0; i < 4; ++i) {
    if (str[l] == "2020"[i]) ++l;
    else break;
  }
  for (int i = 3; i >= 0; --i) {
    if (str[n - r - 1] == "2020"[i])
      ++r;
    else
      break;
  }
  if (l + r >= 4)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
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
