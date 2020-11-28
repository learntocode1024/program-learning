// contest/noip_simulate/A.cpp
// NOIP simulate contest on 11/28/20
// Created by learntocode1024 on 11/28/20.
// 

#include <memory.h>
#include <cstdio>
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
typedef long long LL;
const int mod = 998244353;
LL map[3][3] = {
  {0, 0, 1},
  {1, 0, 1},
  {0, 1, 0}
};

void mt_mul(LL (*dest)[3], const LL (*a)[3], const LL (*b)[3]) {
  LL temp1[3][3], temp2[3][3];
  memcpy(temp1, a, 9 * sizeof(LL));
  memcpy(temp2, b, 9 * sizeof(LL));
  memset(dest, 0, 9 * sizeof(LL));
  for (int kI = 0; kI < 3; ++kI) {
    for (int kJ = 0; kJ < 3; ++kJ) {
      for (int K = 0; K < 3; ++K) {
        dest[kI][kJ] = (dest[kI][kJ] + temp1[kI][K] * temp2[K][kJ]) % mod;
      }
    }
  }
}

int Q_mtpow(int n) {
  LL val[3][3] = {
    {1, 0, 0},
    {0, 1, 0},
    {0, 0, 1}
  };
  LL mp[3][3];
  memcpy(mp, map, 9 * sizeof(LL));
  while (n) {
    if (n & 1) mt_mul(val, val, mp);
    mt_mul(mp, mp, mp);
    n >>= 1;
  }
  return (val[0][2] + val[1][2] + val[2][2]) % mod;
}

void solve() {
  int n;
  cin >> n;
  if (n < 3) {
    cout << 1 << endl;
    return;
  }
  cout << Q_mtpow(n - 2) << endl;
}

int main() {
  int T = 1;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
