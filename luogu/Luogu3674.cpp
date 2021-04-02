// luogu/Luogu3674.cpp
// Author: misaka18931
// Date: Mar 31, 2021
// tag: partition, offline-query, bitset, optimization-tecnique

#include <algorithm>
#include <bitset>
#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;
#define MX 100005
bitset<MX> u, v;

int a[MX], vis[MX];
int maxv = 0, blk = 0;

int tot = 0;

struct Q {
  int id;
  int opt;
  int l, r;
  int x;
  void init() {
    cin >> opt >> l >> r >> x;
    --l, --r;
    x = abs(x);
    id = tot++;
  }
  bool operator <(const Q &b) {
    int t1 = l / blk, t2 = b.l / blk;
    return (t1 < t2) + (t1 == t2) * (r < b.r);
  }
  bool solve() const {
    switch (opt) {
      case 1:
        return (!x) || (u & (u << x)).any();
      case 2:
        return ((~x & 1) && u[x >> 1]) || (u & (v >> (maxv - x))).any();
      case 3:
        for (int i = 1; i * i <= x; ++i) {
          if (!u[i] || (x % i)) continue;
          if (u[x / i]) return true;
        }
        return false;
      default:
        return false;
    }
  }
} qu[MX];

void move(int pos, int op) {
  int &val = a[pos];
  vis[val] += op;
  u[val] = vis[val];
  v[maxv - val] = vis[val];
}

bool ans[MX];

int main() {
  int n, q;
  cin >> n >> q;
  blk = sqrt(n) + 0.5;
  for (int i(0); i < n; ++i) {
    cin >> a[i];
    a[i] = abs(a[i]);
    maxv = max(maxv, a[i]);
  }
  for (int i(0); i < q; ++i)
    qu[i].init();
  sort(qu, qu + q);
  int l = 0, r = 0;
  move(0, 1);
  for (int i(0); i < q; ++i) {
    Q &q = qu[i];
    while (l > q.l) move(--l, 1);
    while (r < q.r) move(++r, 1);
    while (l < q.l) move(l++, -1);
    while (r > q.r) move(r--, -1);
    ans[q.id] = q.solve();
  }
  char out[2][5] = {"bi", "hana"};
  for (int i = 0; i < q; ++i) {
    cout << out[ans[i]] << endl;
  }
}
