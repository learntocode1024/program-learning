// contest/032621/T1.cpp
// Author: misaka18931
// Date: Mar 26, 2021

#include <cstdio>
typedef long long LL;
#define MX 10 //  500005

inline int gcd(int a, int b) {
  while ((a %= b) && (b %= a));
  return a + b;
}

int Q_pow(int a, LL x, int mod) {
  int ans = 1;
  while (x) {
    if (x & 1) ans = ans * a % mod;
    a = a * a % mod;
    x >>= 1;
  }
  return ans;
}

unsigned val[MX];
unsigned remap[MX];
unsigned ans[MX];

int main() {
  int n, k;
  LL T;
  scanf("%d%d%lld", &n, &k, &T);
  for (int i = 0; i < n; ++i)
    scanf("%u", val + i);
  int index_shift = Q_pow(2, T - 1, n);
  if (!index_shift) {
    for (int i = 0; i < n; ++i)
      printf("%d ", val[i] * (k & 1));
    printf("\n");
    return 0;
  }
  int cnt = gcd(index_shift, n);
  int offset = n / cnt;
  for (int beg = 0; beg < cnt; ++beg) {
    int curr = beg;
    remap[beg * offset] = val[curr];
    for (int i = 1 + beg * offset; i < offset * (beg + 1); ++i) {
      curr = (curr + index_shift) % n;
      remap[i] = remap[i - 1] ^ val[curr];
    }
  } // remapped prefix xor sum
  for (int grp = 0; grp < cnt; ++grp) {   
  } // calculate answer
  for (int i = 0; i < n; ++i)
    printf("%u ", ans[i]);
  printf("\n");
  return 0;
}
