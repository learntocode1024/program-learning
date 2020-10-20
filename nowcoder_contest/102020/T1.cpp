// nowcoder_contest/102020/T1.cpp
// https://ac.nowcoder.com/acm/contest/
// Created by learntocode1024 on 10/20/20.
// AC on 10/20/20
#include <cstdio>
#define MX 10000005
int factor[MX];
int prime[MX / 10];
int cnt_prime = -1;
int a, b;

void init() {
  for (int kI = 2; kI <= b; ++kI) {
    if (!factor[kI]) {
      prime[++cnt_prime] = kI;
      factor[kI] = kI;
    }
    for (int kJ = 0; kJ <= cnt_prime; ++kJ) {
      if (prime[kJ] > factor[kI] || 1ll * prime[kJ] * kI > b) break;
      factor[kI * prime[kJ]] = prime[kJ];
    }
  }
}

int main() {
  scanf("%d%d", &a, &b);
  init();
  long long ans = b - a + 1;
  long long tmp;
  for (int kI = 0; kI <= cnt_prime; ++kI) {
    tmp = prime[kI];
    if (prime[kI] >= a)
      ans += prime[kI] - 1;
    while (tmp <= b / prime[kI]) {
      tmp *= prime[kI];
      if (tmp >= a) ans += prime[kI] - 1;
    }
  }
  printf("%lld", ans);
  return 0;
}