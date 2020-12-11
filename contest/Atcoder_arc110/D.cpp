// contest/Atcoder_arc110/D.cpp
// https://atcoder.jp/contests/arc110/tasks
// Created by learntocode1024 on 12/05/20.
// AC 12-10-20

#include <cstdio>
#include <algorithm>
#include <iostream>
#define MX
using std::cin;
using std::cout;
using std::endl;
typedef long long LL;
typedef unsigned long long ULL;
const int mod = 1e9 + 7;

LL q_pow(LL base, LL index) {
  LL ans = 1;
  while (index) {
    if (index & 1) ans = ans * base % mod;
    base = base * base % mod;
    index >>= 1;
  }
  return ans;
}

void solve() {
  int n, m;
  cin >> n >> m;
  LL sum = 0;
  for (int i = 0, t; i < n; ++i) {
    cin >> t;
    sum += t;
  }
  LL ans = 1;
  int tmp = sum + n;
  for (LL i = m + n; i > m + n - tmp; --i) {
    ans = ans * i % mod;
  }
  for (int i = 2; i <= tmp; ++i) {
    ans = ans * q_pow(i, mod - 2) % mod;
  }
  cout << ans << endl;
}

int main() {
  cin.tie(NULL);
  std::ios::sync_with_stdio(false);
  int T = 1;
  // cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
