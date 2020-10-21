// nowcoder_contest/102020_NC/T2.cpp
// https://ac.nowcoder.com/acm/contest/
// Created by learntocode1024 on 10/20/20.
// AC on 10/20/20
#include <cstdio>
#define MX 1000001
bool isCont[MX];
int n, m;

void insert(int num) {
  if (!num || isCont[num]) return;
  isCont[num] = true;
  for (int kI = 0; kI < 20; ++kI) {
    if (num & (1 << kI)) {
      insert(num ^ (1 << kI));
    }
  }
}

int main() {
  scanf("%d%d", &n, &m);
  int tmp;
  while (n--) {
    scanf("%d", &tmp);
    insert(tmp);
  }
  while (m--) {
    scanf("%d", &tmp);
    if (isCont[tmp]) printf("yes\n");
    else printf("no\n");
  }
  return 0;
}