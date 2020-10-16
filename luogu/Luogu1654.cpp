// luogu/Luogu1654.cpp
// https://www.luogu.com.cn/problem/P1654
// Created by learntocode1024 on 10/14/20.
// AC on 10/16/20
#include <cstdio>

int n;
double e_triple, e_double, e_linear, pr;

int main() {
  std::scanf("%d", &n);
  for (int kI = 0; kI < n; ++kI) {
    std::scanf("%lf", &pr);
    e_triple += pr * (3 * (e_double + e_linear) + 1);
    e_double = pr * (e_double + 2 * e_linear + 1);
    e_linear = pr * (e_linear + 1);
  }
  std::printf("%.1lf", e_triple);
  return 0;
}