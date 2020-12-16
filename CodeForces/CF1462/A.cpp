// CodeForces/CF1462/A.cpp
// Author: learntocode1024
// Date: 12-15-20
// URL: https://codeforces.com/contest/1462/problem/A
// tag: easy
// AC

#include <cstdio>
#include <iostream>
#define MX
using std::cin;
using std::cout;
using std::endl;

int a[305];

void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  int l = 0, r = n - 1;
  while (l < r) {
    cout << a[l] << " " << a[r] << " ";
    r--, l++;
  }
  if (l == r) cout << a[l];
  cout << endl;
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
