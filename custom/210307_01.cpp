// $FILEDIR
// Author: $USERNAME
// Date: $DATE
// URL: $PROBLEMURL
// tag:
//

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#define MX 1000005
using namespace std;
typedef unsigned long long ULL;
const ULL mod = 998244353ull;
int lim;
ULL inv[MX], fac[MX], inv_fac[MX], pref_fac[MX];

void prework() {
  inv_fac[0] = fac[0] = inv[1] = inv_fac[1] = fac[1] = pref_fac[1] = 1;
  for (int i = 2; i <= lim; ++i) {
    inv[i] = (mod - mod / i) * inv[mod % i] % mod;
    fac[i] = fac[i - 1] * i % mod;
    inv_fac[i] = inv_fac[i - 1] * inv[i] % mod;
    pref_fac[i] = pref_fac[i - 1] * fac[i] % mod;
  }
}

ULL q_pow(ULL a, ULL x) {
  ULL ans = 1;
  while (x) {
    if (x & 1) ans = ans * a % mod;
    a = a * a % mod;
    x >>= 1;
  }
  return ans;

}

void solve(int n) {
  ULL ans = 0, curr = 1;
  ULL inv2 = inv[2];
  for (int i = 2; i <= n; ++i, curr = 1) {
    curr = fac[n] * inv_fac[n - i] % mod;
    curr = curr * pref_fac[i - 1] % mod;
    curr = curr * inv2 % mod;
    inv2 = inv2 * inv[2] % mod;
    ans = (ans + curr) % mod;
  }
  cout << ans << endl;
}

int cases[40];
int main() {
  cin.tie(NULL);
  std::ios::sync_with_stdio(false);
  int T = 1;
  cin >> T;
  for (int i = 0; i < T; ++i) {
    cin >> cases[i];
    lim = max(lim, cases[i]);
  }
  prework();
  for (int i = 0; i < T; ++i) {
    solve(cases[i]);
  }
  return 0;
}
