// CodeForces/CF1465/A.cpp
// Author: learntocode1024
// Date: 12-20-20
// URL: https://codeforces.com/contest/1465/problem/A
// tag:
// AC

#include <cstdio>
#include <string>
#include <iostream>
#define MX
using std::cin;
using std::cout;
using std::endl;
std::string s;
void solve() {
  int n;
  cin >> n >> s;
  int i = n - 1;
  while (i >= 0) {
    if (s[i] == ')') i--;
    else break;
  }
  if (i + 1 < n - i - 1) cout << "YES" << endl;
  else cout << "NO" << endl;
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
