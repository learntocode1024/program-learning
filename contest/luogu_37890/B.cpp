// contest/luogu_37890/B.cpp
// https://www.luogu.com.cn/contest/37890#problems
// Created by learntocode1024 on 12/03/20.
//

#include <memory.h>
#include <algorithm>
#include <cstdio>
#include <vector>
#define MX 1000006
typedef long long LL;
const LL mod = 998244353;

long long q_pow(long long a, long long index) {
  long long ans = 1;
  while (index) {
    if (index & 1) ans = ans * a % mod;
    a = a * a % mod;
    index >>= 1;
  }
  return ans;
}

inline int read() {
  char ch = getchar();
  int x = 0, f = 1;
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while ('0' <= ch && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}

int ch[MX][2], sz[MX];
LL tmp[MX];
LL ans = 0, n;

int get_sz(int curr) {
  if (curr == 0) return 0;
  sz[curr] = 1 + get_sz(ch[curr][0]) + get_sz(ch[curr][1]);
  return sz[curr];
}

LL dfs(int curr) {
  if (sz[curr] == 1) return 0;
  LL diff = 0;
  for (int i = 1; i < sz[ch[curr][0]]; ++i) {
      diff = (diff + tmp[i] * tmp[sz[curr] - 1 - i] % mod) % mod;
  }
  ans = (ans + diff + tmp[sz[curr] - 1]) % mod;
  if (ch[curr][0]) ans = (ans + dfs(ch[curr][0]) * tmp[sz[ch[curr][1]]]);
  if (ch[curr][1]) dfs(ch[curr][1]);
  return diff;
}

int main() {
  n = read();
  tmp[0] = tmp[1] = 1;
  for (int i = 1; i < n; ++i) {
    tmp[i + 1] = tmp[i] * (2 * i + 1) * (2 * i + 2) % mod * q_pow(i + 1, mod - 2) % mod * q_pow(i + 2, mod - 2) % mod;
  }
  for (int i = 1; i < n; ++i) {
    ans = (ans + tmp[i]) % mod;
  }
  for (int i = 1; i <= n; ++i) {
    ch[i][0] = read();
    ch[i][1] = read();
  }
  get_sz(1);
  dfs(1);
  printf("%lld\n", ans);
  return 0;
}
