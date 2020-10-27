// nowcoder_contest/102720_NC/T1.cpp
// https://ac.nowcoder.com/acm/contest/7613/A
// Created by learntocode1024 on 10/27/20.
// AC on 10/27/20

#include <cstdio>

int n, ans;

int main() {
  scanf("%d", &n);
  for (int a = 1; a <= n/4; ++a) {
    for (int b = 2*a; b <= n/2; b += a) {
      ans += n/b - 1;
    }
  }
  printf("%d", ans);
  return 0;
}
