// CodeForces/CF1455/B.cpp
// https://codeforces.com/contest/1455/problem/B
// Created by learntocode1024 on 11/30/20.
// AC

#include <cstdio>
#include <algorithm>
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int tri[5000];

void solve() {
  int des;
  cin >> des;
  int rk = std::lower_bound(tri, tri + 5000, des) - tri;
  if (des == tri[rk]) cout << rk << endl;
  else if (des == tri[rk] - 1) cout << rk + 1 << endl;
  else cout << rk << endl;
}

int main() {
  cin.tie(NULL);
  std::ios::sync_with_stdio(false);
  // prework
  for (int k = 1; k < 5000; ++k) {
    tri[k] = tri[k - 1] + k;
  }
  int T = 1;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
