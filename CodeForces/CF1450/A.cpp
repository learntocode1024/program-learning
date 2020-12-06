// CodeForces/CF1450/A.cpp
// https://codeforces.com/contest/1450/problem/A
// Created by learntocode1024 on 12/06/20.
// 

#include <cstdio>
#include <string>
#include <iostream>
#define MX
using std::cin;
using std::cout;
using std::endl;
std::string str;

void solve() {
  int t;
  std::string ans;
  cin >> t >> str;
  int cnt = 0;
  for (auto i : str) {
    if (i == 'b') ++cnt;
    else ans = ans + i;
  }
  while (cnt > 0) cout << 'b', cnt--;
  cout << ans << '\n';
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
