// CodeForces/CF1454/B.cpp
// https://codeforces.com/contest/1454/problem/A/problem/B
// Created by learntocode1024 on 11/24/20.
// 

#include <cstdio>
#include <iostream>
#include <memory.h>
using std::cin;
using std::cout;
using std::endl;

int vis[200005];

void solve() {
  memset(vis, 0, sizeof(vis));
  int n;
  cin >> n;
  for (int kI = 1, a; kI <= n; ++kI) {
    cin >> a;
    if (vis[a] == -1) continue;
    if (vis[a]) vis[a] = -1;
    else vis[a] = kI;
  }
  for (int kI = 1; kI <= n; ++kI) {
    if (vis[kI] > 0) {
      cout << vis[kI] << '\n';
      break;
    }
    if (kI == n && vis[n] <= 0) cout << "-1\n";
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
