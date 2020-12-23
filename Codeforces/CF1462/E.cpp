// CodeForces/CF1462/E.cpp
// Author: learntocode1024
// Date: 12-15-20
// URL: https://codeforces.com/contest/1462/problem/E
// tag: combination, bruteforce
// AC

#include <cstdio>
#include <iostream>
#define MX 200005
using std::cin;
using std::cout;
using std::endl;
typedef long long LL;
typedef unsigned long long ULL;
const int mod = 1e9 + 7;

LL calc[MX], lim;
LL icalc[MX];

LL q_pow(LL b, LL index) {
  LL ans = 1;
  while (index) {
    if (index & 1) ans = ans * b % mod;
    b = b * b % mod;
    index >>= 1;
  }
  return ans;
}

LL comb(LL n, LL k) {
  if (k > n) return 0;
  if (k == n) return 1;
  LL ans = calc[n] * icalc[n - k] % mod * icalc[k] % mod;
  return ans;
}

int cnt[MX];

void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  if (n > lim) {
    for (int i = lim + 1; i <= n; ++i) {
      calc[i] = calc[i - 1] * i % mod;
      icalc[i] = icalc[i - 1] * q_pow(i, mod - 2) % mod;
    }
    lim = n;
  }
  for (int i = 0, tmp; i < n; ++i) {
    cin >> tmp;
    cnt[tmp]++;
  }
  LL ans = 0, curr = 0;
  for (int i = 1; i <= k + 1; ++i) {
    curr += cnt[i];
  }
  ans += comb(curr, m);
  for (int i = 1; i + k <= n; ++i) {
    curr = curr - cnt[i] + cnt[i + k + 1];
    ans = (ans + comb(curr, m)) % mod;
    LL del = comb(curr - cnt[i + k + 1], m);
    if (ans > del) ans -= del;
    else ans = (ans + mod - del) % mod;
  }
  cout << ans << endl;
  // HINT: when dealing with multiple test cases, we don't use memset
  for (int i = 0; i <= n; ++i) {
    cnt[i] = 0;
  }
}

int main() {
  calc[1] = icalc[1] = lim = 1;
  cin.tie(NULL);
  std::ios::sync_with_stdio(false);
  int T = 1;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
