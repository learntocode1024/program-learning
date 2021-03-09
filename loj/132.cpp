// Author: misaka18931
// Date: Feb 17, 2021
// https://loj.ac/p/132
// tag: data-structure, binary-indexed-tree
// AC

#include <cstdio>
#include <iostream>
using namespace std;
typedef long long LL;
#define MX 1000006

int n;
LL c[MX];
LL a[MX], b[MX];

void add(LL* const buf, int pos, LL val) {
  while (pos <= n) {
    buf[pos] += val;
    pos += pos & (~pos + 1);
  }
}

LL query(LL* const buf, LL pos) {
  LL ans = 0;
  while (pos) {
    ans += buf[pos];
    pos -= pos & (~pos + 1);
  }
  return ans;
}

void modify() {
  LL l, r, val;
  cin >> l >> r >> val;
  ++r;
  add(a, l, val);
  add(a, r, -val);
  add(b, l, val * l);
  add(b, r, -val * r);
}

void output() {
  int l, r;
  cin >> l >> r;
  --l;
  LL ans = (r + 1) * query(a, r) - (l + 1) * query(a, l);
  ans += query(b, l) - query(b, r);
  ans += c[r] - c[l];
  cout << ans << endl;
}

int main() {
  int q;
  cin >> n >> q;
  for (int i = 1; i < n + 1; ++i) {
    cin >> c[i];
    c[i] += c[i - 1];
  }
  int op;
  while (q--) {
    cin >> op;
    if (op == 1) modify();
    else output();
  }
  return 0;
}
