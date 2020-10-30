// luogu/Luogu3599.cpp
// https://www.luogu.com.cn/problem/P3599
// Created by learntocode1024 on 10/30/20.
// 

#include <cstdio>

char table[5][11] = {
  {},
  "2 1\n",
  "2 1 2\n",
  "2 1 2 3\n",
  "2 1 3 2 4\n"
};

long long f_pow(int x, int y, int mod) {
  long long ans = 1;
  while (y) {
    if (y & 1) ans = ans * x % mod;
    x = x * x % mod;
    y >>= 1;
  }
  return ans;
}

bool isprime(int x) {
  if (f_pow(2, x - 1, x) == 1 && f_pow(3, x - 1, x) == 1) return true;
  return false;
}

int op, T;

int main() {
  scanf("%d%d", &op, &T);
  int x;
  if (op == 1) { // task 1
    while (T--) {
      scanf("%d", &x);
      if (x & 1) {
        printf("0\n");
      } else {
        printf("2 ");
        for (int kI = 1; kI <= x; kI++) {
          printf("%d ",(kI&1)?x+1-kI:kI-1);
        }
        printf("\n");
      }
    }
  } else { // task 2
    while (T--) {
      scanf("%d", &x);
      if (x < 5) {
        printf("%s", table[x]);
      } else if (isprime(x)) {
        printf("2 1 "); // INVERSE!!!
        for (int kI = 2; kI < x; kI++) {
          printf("%lld ", kI * f_pow(kI - 1, x - 2, x) % x);
        }
        printf("%d\n", x);
      } else {
        printf("0\n");
      }
    }
  }
  return 0;
}
