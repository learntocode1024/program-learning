// Codeforces/CF600E.cpp
// Author: misaka18931
// Date: Mar 21, 2021
// tag: segment-tree merge

#include <algorithm>
#include <cstdio>
#include <iostream>
#define MX 100005

struct node {
  node *lc;
  node *rc;
  long long ans;
  int cnt;
  node() : lc(0), rc(0), ans(0), cnt(0){};
};
node *root[MX];

inline void pushup(node *curr) {
  if (curr->lc == NULL) {
    curr->cnt = curr->rc->cnt;
    curr->ans = curr->rc->ans;
    return;
  }
  if (curr->rc == NULL) {
    curr->cnt = curr->lc->cnt;
    curr->ans = curr->lc->ans;
    return;
  }
  const int &lcnt = curr->lc->cnt;
  const int &rcnt = curr->rc->cnt;
  if (lcnt == rcnt)
    curr->cnt = lcnt, curr->ans = curr->lc->ans + curr->rc->ans;
  else if (lcnt > rcnt)
    curr->cnt = lcnt, curr->ans = curr->lc->ans;
  else
    curr->cnt = rcnt, curr->ans = curr->rc->ans;
}

void insert(node *&curr, int l, int r, int val) {
  if (curr == NULL)
    curr = new node();
  if (r - l == 1) {
    ++curr->cnt;
    curr->ans = l;
    return;
  }
  int mid = l + (r - l) / 2;
  if (val < mid)
    insert(curr->lc, l, mid, val);
  else
    insert(curr->rc, mid, r, val);
  pushup(curr);
}

void merge(node *&dest, node *src) {
  if (dest == NULL) {
    dest = src;
    return;
  }
  if (dest->lc == dest->rc) { // leaf
    dest->cnt += src->cnt;
    delete src;
    return;
  }
  if (src->lc != NULL)
    merge(dest->lc, src->lc);
  if (src->rc != NULL)
    merge(dest->rc, src->rc);
  pushup(dest);
  delete src;
}

inline long long getans(const node *root) { return root->ans; }

int n;
int c[MX];
long long print_val[MX];

int head[MX], to[MX << 1], nxt[MX << 1], tt;
bool vis[MX];
#define add_edge(X, Y)                                                         \
  to[++tt] = Y;                                                                \
  nxt[tt] = head[X];                                                           \
  head[X] = tt;

void dfs(int u) {
  vis[u] = 1;
  for (int i = head[u]; i; i = nxt[i]) {
    int &v = to[i];
    if (vis[v]) continue;
    dfs(v);
    merge(root[u], root[v]);
  }
  insert(root[u], 1, n + 1, c[u]);
  print_val[u] = getans(root[u]);
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i)
    scanf("%d", c + i);
  for (int i = 1; i < n; ++i) {
    int a, b;
    scanf("%d%d", &a, &b);
    add_edge(a, b) add_edge(b, a)
  }
  dfs(1);
  for (int i = 1; i <= n; ++i) {
    printf("%lld ", print_val[i]);
  }
  putchar('\n');
  return 0;
}