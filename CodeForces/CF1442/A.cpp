// CodeForces/CF1442/A.cpp
// https://codeforces.com/contest/1442/problem/A
// Created by learntocode1024 on 11/03/20.
// AC

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

int a[30005];

void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  int l = 0, r = a[n - 1];
  for (int i = n - 1; i >= 0; --i) {
    if (l > a[i]) {
      cout << "NO" << endl;
      return;
    }
    r = min(a[i] - l, r);
    if (a[i] - l > r) {
      l = a[i] - r;
    }
  }
  cout << "YES" << endl;
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
