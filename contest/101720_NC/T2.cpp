// contest/101720_NC/T1.cpp
// https://ac.nowcoder.com/acm/contest/7605/B
// Created by learntocode1024 on 10/17/20.
// AC on 10/18/20

#include <cstdio>
#include <cstring>
#define MX 100005
#define log_2_MX 18
using std::memcpy;
typedef unsigned char pos_type;
const pos_type initial[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

void conv(pos_type* dest, const pos_type* state, const pos_type* jump) {
  pos_type tmp[10];
  memcpy(tmp, state, 10);
  for (int kI = 0; kI < 10; ++kI) dest[kI] = tmp[jump[kI]];
}

int m, n;
unsigned char st[MX][log_2_MX][10];
unsigned short log_2[MX];

int main() {
  scanf("%d%d", &n, &m);
  for (int kI = 1; kI <= n; ++kI) memcpy(st[kI][0], initial, 10);
  int fr, to;
  for (int kI = 1; kI <= n; ++kI) {
    scanf("%d %d", &fr, &to);
    st[kI][0][fr] = (unsigned char)to;
    st[kI][0][to] = (unsigned char)fr;
  }
  for (int kI = 1; kI <= n; ++kI) {
    log_2[kI] = log_2[kI - 1] + (kI == (1u << log_2[kI - 1]));
  }
  for (int step = 1; step <= log_2_MX; ++step) {
    for (int curr = 1; curr <= n - (1 << step) + 1; ++curr) {
      conv(st[curr][step], st[curr][step - 1], st[curr + (1 << (step - 1))][step - 1]);
    }
  }
  unsigned l, r, step, cnt = 0;
  pos_type ans[10];
  while (m--) {
    memcpy(ans, initial, 10);
    scanf("%d%d", &l, &r);
    step = r - l + 1;
    cnt = 0;
    while (step) {
      if (step & 1) {
        conv(ans, ans, st[l][cnt]);
        l += (1 << cnt);
      }
      ++cnt;
      step >>= 1;
    }
    for (unsigned char an : ans) {
      printf("%d ", an);
    }
    printf("\n");
  }
  return 0;
}