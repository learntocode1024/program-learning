// CodeForces/CF1461/C.cpp
// Author: learntocode1024
// Date: 12-11-20
// URL: https://codeforces.com/contest/1461/problem/C
// tag:
// AC

#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#define MX 100005
using std::cin;
using std::cout;
using std::endl;
using std::memset;
typedef long long LL;
typedef unsigned long long ULL;

struct op {
  double p;
  int prefix;
  bool operator< (const op& b) {
    return prefix < b.prefix;
  }
} ops[MX];
int ar[MX];

void solve() {
  for (int i = 0; i < MX; ++i) {
    ops[i].p = 0;
    ops[i].prefix = 0;
  }
  memset(ar, 0, sizeof(ar));
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> ar[i];
  }
  int mx = n + 1;
  for (int i = n; i > 0; --i) {
    if (ar[i] != i) {
      mx = i;
      break;
    }
  }
  for (int i = 0; i < m; ++i) {
    cin >> ops[i].prefix >> ops[i].p;
  }
  if (mx == n + 1) {
    printf("1.000000\n");
    return;
  }
  std::sort(ops, ops + m);
  double ans = 1;
  for (int i = 0; i < m; ++i) {
    if (ops[i].prefix < mx) continue;
    ans = ans * (1 - ops[i].p);
  }
  printf("%.6lf\n", 1 - ans);
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
