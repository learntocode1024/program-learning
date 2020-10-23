// nowcoder_contest/102220_NC/T1.cpp
// https://ac.nowcoder.com/acm/contest/7609/A
// Created by learntocode1024 on 10/22/20.
// AC on 10/22/20

#include <cstdio>

int T, a, b, c, k, sum;

int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d%d%d", &a, &b, &c, &k);
    sum = a + b + c;
    long long tmp = 2;
    while (k) {
      if (k & 1) c = c*tmp %sum;
      tmp = tmp*tmp %sum;
      k >>= 1;
    }
    printf("%d\n", c);
  }
}