// CodeForces/CF1444B.cpp
// https://codeforces.com/problemset/problem/1444/B
// Created by learntocode1024 on 12/02/20.
// AC

#include <cstdio>
#include <algorithm>
#include <iostream>
#define MX 300005
using std::cin;
using std::cout;
using std::endl;
const int mod = 998244353;

int a[MX];

long long q_pow(long long a, long long index) {
  long long ans = 1;
  while (index) {
    if (index & 1) ans = ans * a % mod;
    a = a * a % mod;
    index >>= 1;
  }
  return ans;
}

void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < (n << 1); ++i) {
    cin >> a[i];
  }
  std::sort(a, a + (n << 1));
  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    ans += a[n + i] - a[i];
    if (ans >= mod) ans %= mod;
  }
  long long div = 1;
  for (int i = 2; i <= n; ++i) {
    div = div * i % mod;
  }
  for (int i = (n << 1); i > n; --i) {
    ans = ans * i % mod;
  }
  ans = ans * q_pow(div, mod - 2) % mod;
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
