// loj/139-hld.cpp
// https://loj.ac/p/139
// Description: HLD(heavy-light-decomposition) template
// tag: hld, tree
// AC

#include <algorithm>
#include <climits>
#include <cstdio>
#include <iostream>
typedef long long LL;
using namespace std;
#define MX 100005

int n;
LL c0[MX], c1[MX], c[MX], cx[MX];
#define lowbit(X) ((X) & (~X + 1))

template<typename T> void bit_add(T* buf, int x, T val) {
  while (x <= n) {
    buf[x] += val;
    x += lowbit(x);
  }
}

template<typename T> T bit_get(T* buf, int x) {
  T ans = 0;
  while (x) {
    ans += buf[x];
    x -= lowbit(x);
  }
  return ans;
}

void change(int l, int r, LL val) { // [l, r]
  ++r;
  bit_add(c, l, val);
  bit_add(c, r, -val);
  bit_add(cx, l, val * l);
  bit_add(cx, r, -val * r);
}

LL get(int l, int r) { // [l, r]
  LL ans = 0;
  --l;
  ans = (r + 1) * bit_get(c, r) - (l + 1) * bit_get(c, l);
  ans += bit_get(cx, l) - bit_get(cx, r);
  ans += c0[r] - c0[l];
  return ans;
}

#define add_edge(X, Y)                                                         \
  to[++tot] = Y;                                                               \
  nxt[tot] = head[X];                                                          \
  head[X] = tot;

int head[MX], to[MX * 2], nxt[MX * 2], tot, root;
int fa[MX], dep[MX], siz[MX], son[MX], top[MX], dfn[MX], rnk[MX];

void pre_hld(int u) {
  dep[u] = dep[fa[u]] + 1;
  siz[u] = 1;
  for (int i = head[u]; i; i = nxt[i]) {
    int &v = to[i];
    if (v == fa[u]) continue;
    pre_hld(v);
    siz[u] += siz[v];
    if (siz[v] > siz[son[u]]) son[u] = v;
  }
}

int cnt = 1;
void hld(int u, int t) {
  top[u] = t;
  rnk[cnt] = u;
  dfn[u] = cnt++;
  if (!son[u]) return;
  hld(son[u], t);
  for (int i = head[u]; i; i = nxt[i]) {
    int &v = to[i];
    if (v != son[u] && v != fa[u]) hld(v, v);
  }
}

void init() {
  root = 1;
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> c1[i];
  }
  for (int i = 2; i <= n; ++i) {
    cin >> fa[i];
    add_edge(i, fa[i])
    add_edge(fa[i], i)
  }
  pre_hld(1);
  hld(1, 1);
  for (int i = 1; i <= n; ++i) {
    c0[dfn[i]] = c1[i];
  }
  for (int i = 1; i <= n; ++i) {
    c0[i] += c0[i - 1];
  }
}

int lca_1;
int lca(int a, int b) {
  while (top[a] != top[b]) {
    if (dep[top[a]] < dep[top[b]])
      lca_1 = top[b], b = fa[top[b]];
    else
      lca_1 = top[a], a = fa[top[a]];
  }
  if (a == b) return a;
  if (dep[a] < dep[b]) swap(a, b);
  lca_1 = rnk[dfn[b] + 1];
  return b;
}

int findson(int x, int y) {
  while (top[x] != top[y]) {
    if (fa[top[y]] == x)
      return top[y];
    y = fa[top[y]];
  }
  return son[x];
}

void path_edit(int a, int b, LL val) {
  while (top[a] != top[b]) {
    if (dep[top[a]] < dep[top[b]]) swap(a, b);
    change(dfn[top[a]], dfn[a], val);
    a = fa[top[a]];
  }
  if (dep[a] < dep[b]) swap(a, b);
  change(dfn[b], dfn[a], val);
}

LL path_get(int a, int b) {
  LL ans = 0;
  while (top[a] != top[b]) {
    if (dep[top[a]] < dep[top[b]])
      swap(a, b);
    ans += get(dfn[top[a]], dfn[a]);
    a = fa[top[a]];
  }
  if (dep[a] < dep[b])
    swap(a, b);
  ans += get(dfn[b], dfn[a]);
  return ans;
}

void tree_edit(int u, LL val) {
  if (root == u)
    return change(1, n, val); // holy shit!
  else if (lca(root, u) == u) {
    change(1, n, val);
    lca_1 = findson(u, root);
    change(dfn[lca_1], dfn[lca_1] + siz[lca_1] - 1, -val);
  } else {
    change(dfn[u], dfn[u] + siz[u] - 1, val);
  }
}

LL tree_get(int u) {
  if (root == u) return get(1, n);
  else if (lca(root, u) == u) {
    lca_1 = findson(u, root);
    return get(1, n) - get(dfn[lca_1], dfn[lca_1] + siz[lca_1] - 1);
  } else {
    return get(dfn[u], dfn[u] + siz[u] - 1);
  }
}

int main() {
  init();
  int T;
  cin >> T;
  int t, u, v;
  LL k;
  while (T--) {
    cin >> t;
    if (t == 1) cin >> root;
    else if (t == 2) {
      cin >> u >> v >> k;
      path_edit(u, v, k);
    } else if (t == 3) {
      cin >> u >> k;
      tree_edit(u, k);
    } else if (t == 4) {
      cin >> u >> v;
      cout << path_get(u, v) << endl;
    } else {
      cin >> u;
      cout << tree_get(u) << endl;
    }
  }
}
