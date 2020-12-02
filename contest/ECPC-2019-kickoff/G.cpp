// contest/ECPC-2019-kickoff/G.cpp
// https://codeforces.com/gym/102881
// Created by learntocode1024 on 12/02/20.
// AC

#include <cstdio>

long long n;

long long gcd(long long a, long long b) {
  while ((a %= b) && (b %= a));
  return a + b;
}

void solve() {
  long long l, r;
  scanf("%lld%lld", &l, &r);
  if (l != r) n = 1;
  else {
    if (n == 0) n = l;
    else n = gcd(n, l);
  }
  printf("%lld\n", n);
}

int main() {
  freopen("gcd.in", "r", stdin);
  int T = 10000000;
  scanf("%d", &T);
  while (T--) {
    solve();
  }
  return 0;
}
