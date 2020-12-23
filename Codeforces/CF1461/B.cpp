// CodeForces/CF1461/B.cpp
// Author: learntocode1024
// Date: 12-11-20
// URL: https://codeforces.com/contest/1461/problem/B
// tag:
// AC

#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#define MX 505
using std::cin;
using std::cout;
using std::endl;
using std::memset;
typedef long long LL;
typedef unsigned long long ULL;
std::string str[MX];
int len[MX][MX];

void solve() {
  memset(len, 0, sizeof(len));
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    cin >> str[i];
  }
  for (int i = 0; i < n; ++i) {
    if (str[i][0] == '*') len[i][0] = 1;
    for (int j = 1; j < m; ++j) {
      if (str[i][j] == '*') len[i][j] = len[i][j - 1] + 1;
    }
  }
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (str[i][j] == '.') continue;
      int curr = 0;
      bool flag = true;
      while (flag && curr + i < n && j - curr >= 0 && j + curr < m) {
        ++curr;
        if (len[i + curr][j + curr] <= (curr << 1)) flag = false;
      }
      ans += curr;
    }
  }
  cout << ans << endl;
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
