// CodeForces/CF1457/A.cpp
// https://codeforces.com/contest/1457/problem/A
// Created by learntocode1024 on 11/29/20.
// 

#include <cstdio>
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int max(int a, int b) {
  if (a > b) return a;
  return b;
}

int min(int a, int b) {
  if (a < b) return a;
  return b;
}

void solve() {
  int n, m, r, c;
  cin >> n >> m >> r >> c;
  cout << max(r - 1, n - r) + max(c - 1, m - c) << endl;
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
