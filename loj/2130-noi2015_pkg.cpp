// loj/2130-noi2015_pkg.cpp
// https://loj.ac/p/2130
// tag: segment-tree, hld
// AC

#include <algorithm>
#include <climits>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
#define MX 100005

int n;
int sum[MX * 4];
int tag[MX * 4];

void push_down(int curr, int l, int r) {
  int left = curr * 2 + 1, right = left + 1;
  int mid = l + ((r - l) >> 1);
  sum[left] = sum[left] * (tag[curr] == 0) + (tag[curr] > 0) * (mid - l);
  sum[right] = sum[right] * (tag[curr] == 0) + (tag[curr] > 0) * (r - mid);
  if (tag[curr]) tag[left] = tag[right] = tag[curr];
  tag[curr] = 0;
}

void assign(int curr, int beg, int end, int l, int r, int val) {
  if (beg == l && end == r) {
    sum[curr] = val * (r - l);
    tag[curr] = (val - (val == 0));
    return;
  }
  int left = curr * 2 + 1, right = left + 1;
  int mid = beg + ((end - beg) >> 1);
  push_down(curr, beg, end);
  if (l < mid)
    assign(left, beg, mid, l, min(mid, r), val);
  if (r > mid)
    assign(right, mid, end, max(l, mid), r, val);
  sum[curr] = sum[left] + sum[right];
}

int get(int curr, int beg, int end, int l, int r) {
  if (beg == l && end == r) {
    return sum[curr];
  }
  int left = curr * 2 + 1, right = left + 1;
  int mid = beg + ((end - beg) >> 1);
  push_down(curr, beg, end);
  int ans = 0;
  if (l < mid)
    ans += get(left, beg, mid, l, min(mid, r));
  if (r > mid)
    ans += get(right, mid, end, max(l, mid), r);
  return ans;
}

inline int get(int l, int r) {
  return get(0, 1, n + 1, l, r);
}

inline void change(int l, int r, int val) {
  return assign(0, 1, n + 1, l, r, val);
}

#define add_edge(X, Y)                                                         \
  to[++tot] = Y;                                                               \
  nxt[tot] = head[X];                                                          \
  head[X] = tot;

bool vis[MX] = {0};
int head[MX], to[MX * 2], nxt[MX * 2], tot;
int fa[MX], dep[MX], siz[MX], son[MX], dfn[MX], top[MX], rnk[MX];

void pre_hld(int u) {
  dep[u] = dep[fa[u]] + 1;
  siz[u] = 1;
  for (int i = head[u]; i; i = nxt[i]) {
    int &v = to[i];
    if (v == fa[u]) continue;
    pre_hld(v);
    siz[u] += siz[v];
    if (son[u] == -1 || siz[son[u]] < siz[son[v]])
      son[u] = v;
  }
}

int cnt = 0;
void hld(int u, int t) {
  top[u] = t;
  dfn[u] = ++ cnt;
  rnk[cnt] = u;
  if (son[u] > -1) hld(son[u], t);
  for (int i = head[u]; i; i = nxt[i]) {
    int &v = to[i];
    if (v != fa[u] && v != son[u]) hld(v, v);
  }
}

int get(int u) {
  int ans = 0;
  while (top[u] != 0) {
    ans += get(dfn[top[u]], dfn[u] + 1);
    u = fa[top[u]];
  }
  ans += get(1, dfn[u] + 1);
  return ans;
}

void set(int u) {
  while (top[u] != 0) {
    change(dfn[top[u]], dfn[u] + 1, 1);
    u = fa[top[u]];
  }
  change(1, dfn[u] + 1, 1);
}

int install(int u) {
  int ret = get(u);
  if (ret == dep[u]) return 0;
  set(u);
  return dep[u] - ret;
}

int uninstall(int u) {
  int ret = get(dfn[u], dfn[u] + siz[u]);
  if (ret == 0) return 0;
  change(dfn[u], dfn[u] + siz[u], 0);
  return ret;
}

void init() {
  cin >> n;
  fill(son, son + n, -1);
  for (int i = 1; i < n; ++i) {
    cin >> fa[i];
    add_edge(i, fa[i])
    add_edge(fa[i], i)
  }
  pre_hld(0);
  hld(0, 0);
}

int main() {
  init();
  int T;
  cin >> T;
  string s;
  int u;
  while (T--) {
    cin >> s >> u;
    if (s[0] == 'u') cout << uninstall(u) << endl;
    else cout << install(u) << endl;
  }
  return 0;
}
