// CodeForces/CF1457/B.cpp
// https://codeforces.com/contest/1457/problem/B
// Created by learntocode1024 on 11/29/20.
// 

#include <cstdio>
#include <memory.h>
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int min(int a, int b) {
  if (a < b) return a;
  return b;
}

int c[100005], n, k;

void solve() {
  memset(c, 0, 100005 * sizeof(int));
  cin >> n >> k;
  for(int i = 0; i < n; ++i) {
    cin >> c[i];
  }
  int ans = 1e9, curr;
  for (int col = 1; col <= 100; ++col) {
    curr = 0;
    for (int i = 0; i < n;) {
      if (curr > ans) break;
      if (c[i] != col) ++curr, i += k;
      else i++;
    }
    ans = min(ans, curr);
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
