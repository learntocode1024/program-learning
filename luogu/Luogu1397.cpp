// luogu/Luogu1397.cpp
// Author: learntocode1024
// Date: 01-08-21
// URL: https://www.luogu.com.cn/problem/P1397
// tag:
// 

#include <cstdio>
#include <cctype>
#define SCANF(x) scanf("%lld", &x);
#define MX
typedef long long LL;
typedef unsigned long long ULL;
const int mod = 1e9 + 7;

void read(LL &out, LL &out1) {
  LL ans = 0, ans1 = 0;
  char ch;
  int ind = 0;
  ch = getchar();
  while (isdigit(ch)) {
    ++ind;
    ans = (ans << 3) + (ans << 1);
    ans1 = (ans1 << 3) + (ans1 << 1);
    ans += ch - '0';
    ans1 += ch - '0';
    if (ind >= 8) {
      ans = ans % (mod - 1);
      ans1 = ans1 % mod;
      ind = 0;
    }
    ch = getchar();
  }
  out = ans % (mod - 1);
  out1 = ans1 % mod;
}

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
  LL n, m, a, b, c, d;
  LL m1, n1;
  read(n, n1);
  read(m, m1);
  SCANF(a)
  SCANF(b)
  SCANF(c)
  SCANF(d)
  LL A, B;
  if (a == 1) {
    if (!m1)
      m1 = mod - 1;
    else
      --m1;
    A = 1;
    B = m1 * b % mod;
  } else {
    if (!m) m = mod - 1;
    else --m;
    A = q_pow(a, m);
    B = (A - 1) * q_pow(a - 1, mod - 2) % mod * b % mod;
  } // 1st
  LL a1 = A, b1 = B;
  a = A * c % mod;
  b = (c * B + d) % mod;
  if (a == 1) {
    if (!n1)
      n1 = mod - 1;
    else
      --n1;
    A = 1;
    B = n1 * b % mod;
  } else {
    if (!n)
      n = mod - 1;
    else
      --n;
    A = q_pow(a, n);
    B = (A - 1) * q_pow(a - 1, mod - 2) % mod * b % mod;
  } // 2nd
  LL ans = A + B;
  ans %= mod;
  ans = a1 * ans % mod + b1;
  printf("%lld\n", ans % mod);
}
int main() {
  int T = 1;
  while (T--) {
    solve();
  }
  return 0;
}
