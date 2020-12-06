// CodeForces/CF1450/B.cpp
// https://codeforces.com/contest/1450/problem/B
// Created by learntocode1024 on 12/06/20.
// 

#include <cstdio>
#include <iostream>
#define MX
using std::cin;
using std::cout;
using std::endl;

struct pt {
  int x = 0, y = 0;
} pts[105];

int dist(int a, int b) {
  return abs(pts[a].x - pts[b].x) + abs(pts[a].y - pts[b].y);
}

int abs(int x) {
  if (x < 0) return -x;
  return x;
}

void solve() {
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; ++i) {
    cin >> pts[i].x >> pts[i].y;
  }
  bool flag = true;
  for (int i = 0; i < n && flag; ++i) {
    bool curr = true;
    for (int j = 0; j < n && curr; ++j) {
      if (dist(i, j) > k) curr = false;
    }
    if (curr) flag = false;
  }
  if (flag) cout << "-1\n";
  else cout << "1\n";
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
