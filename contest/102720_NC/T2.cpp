// nowcoder_contest/102720_NC/T1.cpp
// https://ac.nowcoder.com/acm/contest/7613/A
// Created by learntocode1024 on 10/27/20.
// AC on 10/27/20

#include <cstdio>
#define MX 10000005
int n, k;
char s[MX], t[MX];
int lps[MX];
long long f[MX], tot;

void calc_lps(char* pat, int* lps, int n) {
  int len = 0, curr = 1;
  lps[0] = 0;
  while (curr < n) {
    if (pat[curr] == pat[len]) {
      ++len;
      lps[curr] = len;
      ++curr;
    } else {
      if (len) {
        len = lps[len - 1];
      } else {
        lps[curr] = 0;
        ++curr;
      }
    }
  }
}

int main() {
  scanf("%d%d\n", &n, &k);
  scanf("%s\n", s);
  scanf("%s", t);
  calc_lps(t, lps, k);
  // compare
  int kI = 0, kJ = 0;
  while (kI < n) {
    if (s[kI] == t[kJ]) {
      ++kI;
      ++kJ;
      if (kJ == k) {
        f[tot++] = kI - kJ;
        kJ = lps[kJ - 1];
      }
    } else {
      if (kJ) kJ = lps[kJ - 1];
      else ++kI;
    }
  }
  // calc
  long long ans = 0;
  f[tot] = n - k + 1;
  for (int i = 0; i < tot; ++i) {
    ans += (f[i] + 1)*(f[i + 1] - f[i]);
  }
  printf("%lld", ans);
  return 0;
}