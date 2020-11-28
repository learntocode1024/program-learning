// CodeForces/CF1454/F.cpp
// https://codeforces.com/contest/1454/problem/F
// Created by learntocode1024 on 11/24/20.
// 

#include <cstdio>
#include <iostream>
#include <memory.h>
using std::cin;
using std::cout;
using std::endl;

int min(int& a, int& b) {
  if (a < b) return a;
  return b;
}

int max(int& a, int& b) {
  if (a > b) return a;
  return b;
}

int a[200005];

void solve() {
  int n, l = 1e9 + 1, r = 0, mid;
  cin >> n;
  for (int kI = 0; kI < n; ++kI) {
    cin >> a[kI];
    l = min(l, a[kI]);
    r = max(r, a[kI]);
  }
  int l1 = 0, l2, l3;
  while (r - l) {
    mid = l + (r - l) / 2;
    while (l1 < n && a[l1] <= mid) ++l1;
  }
  memset(a, 0, n * sizeof(int));
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
