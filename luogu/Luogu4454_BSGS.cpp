// luogu/Luogu4454_BSGS.cpp
// Author: misaka18931
// Date: Apr  1, 2021
// tag: BSGS, number-theory

#include <cstdio>
#include <iostream>
#include <cmath>
#include <unordered_map>
typedef long long LL;
LL p, g;
LL T;
std::unordered_map<LL, LL> pmap;

LL Q_pow(LL a, LL x) {
  LL ans = 1;
  while (x) {
    if (x & 1) ans = ans * a % p;
    a = a * a % p;
    x >>= 1;
  }
  return ans;
}

LL powt = 1;

void init() {
  scanf("%lld%lld", &g, &p);
  T = ceil(sqrt(p));
  for (int i = 0; i < T; ++i) {
    pmap[powt] = i;
    powt = powt * g % p;
  }
}

LL bsgs(LL b) {
  LL curr = Q_pow(b, p - 2) * powt % p;
  LL q = 1, r = 0;
  while (q <= T) {
    if (pmap.find(curr) != pmap.end()) {
      r = pmap[curr];
      break;
    }
    ++q;
    curr = curr * powt % p;
  }
  return q * T - r;
}

void solve() {
  LL A, B;
  scanf("%lld%lld", &A, &B);
  LL a = bsgs(A);
  printf("%lld\n", Q_pow(B, a));
}

int main() {
  init();
  int tests = 1;
  scanf("%d", &tests);
  while (tests--)
    solve();
  return 0;
}
