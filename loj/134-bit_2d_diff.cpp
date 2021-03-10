// Author: misaka18931
// Date: Feb 17, 2021
// https://loj.ac/p/134
// tag: data-structure, binary-indexed-tree(2D)
// AC

#include <cstdio>
#include <vector>
using namespace std;
typedef long long LL;
#define lowbit(X) ((X) & (~(X) + 1))

int n, m;
vector<vector<LL> > a;

void add(vector<vector<LL> > &buf, int x, int y, LL val) {
  if (x <= 0 || y <= 0 || x > n || y > m) return;
  int y1 = y;
  while (x <= n) {
    y = y1;
    while (y <= m) {
      buf[x][y] += val;
      y += lowbit(y);
    }
    x += lowbit(x);
  }
}

LL get(const vector<vector<LL> > &buf, int x, int y) {
  LL ans = 0;
  int y1 = y;
  while (x) {
    y = y1;
    while (y) {
      ans += buf[x][y];
      y -= lowbit(y);
    }
    x -= lowbit(x);
  }
  return ans;
}

int main() {
  scanf("%d%d", &n, &m);
  a = vector<vector<LL> >(n + 1, vector<LL>(m + 1));
  int op, x, y, x1, y1;
  LL val;
  while (scanf("%d%d%d", &op, &x, &y) != EOF) {
    if (op == 1) {
      scanf("%d%d%lld", &x1, &y1, &val);
      ++y1, ++x1;
      add(a, x, y, val);
      add(a, x, y1, -val);
      add(a, x1, y, -val);
      add(a, x1, y1, val);
    } else {
      LL ans = get(a, x, y);
      printf("%lld\n", ans);
    }
  }
  return 0;
}
