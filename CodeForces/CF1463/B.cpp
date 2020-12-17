// CodeForces/CF1463/B.cpp
// Author: learntocode1024
// Date: 12-17-20
// URL: https://codeforces.com/contest/1463/problem/B
// tag:
// 

#include <cstdio>
#include <cstring>
#include <iostream>
#define MX
using std::cin;
using std::cout;
using std::endl;
using std::memset;
typedef long long LL;
typedef unsigned long long ULL;
const int mod = 1e9 + 7;

int a[55];

void solve() {
  memset(a, 0, sizeof(a));
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  for (int i = 0; i < n - 1; ++i) {
    if (a[i] % a[i + 1] && a[i + 1] % a[i]) {
      if (a[i + 1] > a[i]) a[i + 1] = a[i + 1] / a[i] * a[i];
      else a[i + 1] = a[i] / (a[i] / a[i + 1]);
    }
  }
  for (int i = 0; i < n; ++i) {
    cout << a[i] << " ";
  }
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
