// luogu/Luogu3801.cpp
// https://www.luogu.com.cn/problem/P3801
// Created by learntocode1024 on 10/28/20.
// AC on 10/29/20

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

void update(long long* ptr, bool* point, int curr) {
  int delta = 1;
  if (point[curr]) {
    point[curr] = false;
    delta = -1;
  } else point[curr] = true;
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
      update(x, pt_x, x1);
      update(y, pt_y, y1);
    } else {
      scanf("%d%d", &x2, &y2);
      --x1, --y1;
      long long ans_x = query(x, x2) - query(x, x1);
      long long ans_y = query(y, y2) - query(y, y1);
      printf("%lld\n", ans_x*(y2 - y1) + ans_y*(x2 - x1) - 2*ans_x*ans_y);
    }
  }
  return 0;
}
