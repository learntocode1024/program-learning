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