// CodeForces/CF1454/C.cpp
// https://codeforces.com/contest/1454/problem/A/problem/B/problem/C
// Created by learntocode1024 on 11/24/20.
// 

#include <cstdio>
#include <iostream>
#include <memory.h>
using std::cin;
using std::cout;
using std::endl;

int cnt[200005];
bool vis[200005];

void solve() {
  memset(cnt, 0, sizeof(cnt));
  memset(vis, 0, sizeof(vis));
  int n;
  cin >> n;
  int curr, prev;
  cin >> prev;
  bool zero_flag = true;
  for (int kI = 1; kI < n; ++kI) {
    cin >> curr;
    vis[curr] = true;
    if (curr == prev) continue;
    zero_flag = false;
    ++cnt[curr];
    prev = curr;
  }
  if (zero_flag) {
    cout << "0\n";
    return;
  }
  --cnt[curr];
  int ans = n + 1;
  for (int kI = 1; kI <= n; ++kI) {
    if (vis[kI] && cnt[kI] + 1 < ans) ans = cnt[kI] + 1;
  }
  cout << ans << '\n';
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
