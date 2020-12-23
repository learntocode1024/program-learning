// CodeForces/CF1463/D.cpp
// Author: learntocode1024
// Date: 12-17-20
// URL: https://codeforces.com/contest/1463/problem/D
// tag:
// 

#include <cstdio>
#include <cstring>
#include <iostream>
#define MX 200005
using std::cin;
using std::cout;
using std::endl;
using std::memset;
typedef long long LL;
typedef unsigned long long ULL;
const int mod = 1e9 + 7;

int a[MX];

void solve() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  int l = 0, r = 0;
  for (int i = 1; i <= n; ++i) {
    if (a[i] > i) break;
    l++;
  }
  for (int i = n; i > 0; --i) {
    if (a[i] < i + n) break;
    r++;
  }
  if (l == n || r == n) cout << 1 << endl;
  else cout << n - l - r + 1 << endl;
  for (int i = 1; i <= n; ++i) {
    a[i] = 0;
  }
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
