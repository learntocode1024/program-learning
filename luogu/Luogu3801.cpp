// luogu/Luogu3801.cpp
// https://www.luogu.com.cn/problem/P3801
// Created by learntocode1024 on 10/28/20.
//

#include <cstdio>
#define MX 100005

long long x[MX], y[MX];
bool pt_x[MX], pt_y[MX];
int n, m, q;

long long query(long long* ptr, int curr) {
  long long ans = 0;
  while (curr > 0) {
    ans += ptr[curr];
    curr -= (curr & -curr);
  }
  return ans;
}

void update(long long* ptr, int curr) {
  int delta = 1;
  if (query(ptr, curr) - query(ptr, curr - 1) == 1) curr = -1;
  while (curr <= (*ptr)) {
    ptr[curr] += delta;
    curr += (curr & -curr);
  }
}

int main() {
  scanf("%d%d%d", &n, &m, &q);
  x[0] = n, y[0] = m;
  int op, x1, y1, x2, y2;
  while (q--) {
    scanf("%d%d%d", &op, &x1, &y1);
    if (op == 1) {
      update(x, x1);
      update(y, y1);
    } else {
      scanf("%d%d", &y1, &y2);
      long long ans_x = query(x, x2) - query(x, x1 - 1);
      long long ans_y = query(y, y2) - query(y, y1 - 1);
      printf("%lld\n", ans_x*m + ans_y*n - ans_x*ans_y);
    }
  }
  return 0;
}
