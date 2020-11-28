// CodeForces/CF1452/D.cpp
// https://codeforces.com/contest/1452/problem/D
// Created by learntocode1024 on 11/19/20.
// AC

#include <cstdio>
#include <memory.h>
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
const int mod = 998244353;
typedef long long LL;

LL map[2][2] = {
  {1, 1},
  
  {1, 2}
};

void mul(LL ans[][2], LL const a[][2], LL const b[][2]) {
  LL tmpa[2][2], tmpb[2][2];
  memcpy(tmpa, a, 4 * sizeof(LL));
  memcpy(tmpb, b, 4 * sizeof(LL));
  memset(ans, 0, 4 * sizeof(LL));
  for (int kI = 0; kI < 2; ++kI) {
    for (int kJ = 0; kJ < 2; ++kJ) {
      for (int k = 0; k < 2; ++k) {
        ans[kI][kJ] += tmpa[kI][k] * tmpb[k][kJ] % mod;
      }
    }
  }
}

int calc(int n) {
  n--;
  if (n < 2) return 1;
  int cnt = n >> 1;
  LL mp[2][2] = {
    {1, 0},
    {0, 1}
  };
  while (cnt) {
    if (cnt & 1) mul(mp, map, mp);
    mul(map, map, map);
    cnt >>= 1;
  }
  return (mp[0][n & 1] + mp[1][n & 1]) % mod;
}

int frac(int x) {
  x = mod - 1 - x;
  long long fac = 2, ans = 1;
  while (x) {
    if (x & 1) ans = ans * fac % mod;
    fac = fac * fac % mod;
    x >>= 1;
  }
  return (int)ans;
}

void solve(int x) {
  cout << 1LL * calc(x) * frac(x) % mod << endl;
}

int main() {
  int n;
  cin >> n;
  solve(n);
  return 0;
}
