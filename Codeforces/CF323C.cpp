// Codeforces/CF323C.cpp
// Author: misaka18931
// Date: 02-06-21
// URL: https://codeforces.com/problemset/problem/323/C
// tag: segment tree
// Accepted

#include <cstdio>
#include <cstring>
#include <iostream>
#define MX 2000005
using namespace std;

struct node {
  node *lc;
  node *rc;
  int cnt;
  node() : lc(0), rc(0), cnt(0){};
};

int n;
int a[MX];
int pos[MX];
node tree[MX * 20];
node *tot = tree;
node *root[MX];

node *build(int l, int r) {
  node *ret = ++tot;
  if (r == l + 1)
    return ret;
  int mid = l + (r - l) / 2;
  ret->lc = build(l, mid);
  ret->rc = build(mid, r);
  return ret;
}

node *insert(node *const p, int l, int r, int val) {
  node *ret = ++tot;
  ret->lc = p->lc;
  ret->rc = p->rc;
  if (r == l + 1) {
    ret->cnt = p->cnt + 1;
    return ret;
  }
  int mid = l + (r - l) / 2;
  if (val < mid)
    ret->lc = insert(ret->lc, l, mid, val);
  else
    ret->rc = insert(ret->rc, mid, r, val);
  ret->cnt = ret->lc->cnt + ret->rc->cnt;
  return ret;
}

int query(node *const curr, int l, int r, int s, int t) {
  if (l == s && r == t)
    return curr->cnt;
  int mid = l + (r - l) / 2;
  int ans = 0;
  if (s < mid)
    ans += query(curr->lc, l, mid, s, min(t, mid));
  if (t > mid)
    ans += query(curr->rc, mid, r, max(s, mid), t);
  return ans;
}

int x = -1;
#define f(X) ((X + x + n) % n + 1)

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i)
    scanf("%d", a + i);
  for (int i = 1, j; i <= n; ++i) {
    scanf("%d", &j);
    pos[j] = i;
  }
  root[0] = build(1, n + 1);
  for (int i = 1; i <= n; ++i) {
    root[i] = insert(root[i - 1], 1, n + 1, pos[a[i]]);
  }
  int T;
  scanf("%d", &T);
  int v1, v2, v3, v4, l1, r1, l2, r2;
  while (T--) {
    scanf("%d%d%d%d", &v1, &v2, &v3, &v4);
    v1 = f(v1), v2 = f(v2), v3 = f(v3), v4 = f(v4);
    l1 = min(v1, v2), l2 = min(v3, v4);
    r1 = max(v1, v2), r2 = max(v3, v4);
    x = query(root[r1], 1, n + 1, l2, r2 + 1) -
        query(root[l1 - 1], 1, n + 1, l2, r2 + 1);
    printf("%d\n", x);
  }
  return 0;
}
