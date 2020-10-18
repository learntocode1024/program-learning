// nowcoder_contest/101720/T1.cpp
// https://ac.nowcoder.com/acm/contest/7605/A
// Created by learntocode1024 on 10/17/20.
// AC on 10/18/20

#include <cstdio>
#define N 3
long long a[N], d, tmp;
int cnt, tot;

long long gcd(long long x, long long y) {
  if (y)
    while((x %= y) && (y %= x));
  return x + y;
}

int main() {
  scanf("%d", &cnt);
  while (cnt--) {
    tot = 0;
    for (int kI = 0; kI < N; ++kI) {
      scanf("%lld",&tmp);
      if (tmp) a[tot++] = tmp;
    }
    scanf("%lld",&d);
    if (tot == 0) {
      if (d) printf("NO\n");
      else printf("YES\n");
      continue;
    }
    long long mod = a[0];
    if (tot > 1) {
      for (int kI = 1; kI < tot; ++kI)
        mod = gcd(mod, a[kI]);
    }
    if (d % mod) {
      printf("NO\n");
    } else {
      printf("YES\n");
    }
  }
  return 0;
}