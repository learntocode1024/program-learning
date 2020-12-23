// CodeForces/CF1454/C.cpp
// https://codeforces.com/contest/1454/problem/C
// Created by learntocode1024 on 11/24/20.
// AC

#include <cstdio>
#include <algorithm>
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int cnt[200005];
bool vis[200005];

void solve() {
  int n;
  cin >> n;
  int prev = 0;
  for (int i = 0, curr; i < n; ++i) {
    cin >> curr;
    vis[curr] = true;
    if (curr == prev) continue;
    if (i != 0) cnt[curr]++;
    prev = curr;
  }
  cnt[prev]--;
  int ans = n + 1;
  for (int i = 1; i <= n; ++i) {
    if (vis[i]) ans = std::min(ans, cnt[i] + 1);
  }
  cout << ans << endl;
  for (int i = 1; i <= n; ++i) {
    cnt[i] = 0;
    vis[i] = false;
  }
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
