// luogu/Luogu3384.cpp
// Author: misaka18931
// Date: 03-06-21
// URL: https://www.luogu.com.cn/problem/P3384
// tag:
//

#include <cstdio>
#include <cstring>
#include <iostream>
#define MX 100005
using std::cin;
using std::cout;
using std::endl;
using std::memset;
#define add_edge(X, Y)                                                         \
  to[++tot] = Y;                                                               \
  nxt[tot] = head[X];                                                          \
  head[X] = tot;
typedef long long LL;
typedef unsigned long long ULL;
LL mod = 1e9 + 7;
int n, q, root;

int head[MX], to[MX * 2], nxt[MX * 2], tot;
int fa[MX], siz[MX], h_ch[MX], dep[MX], top[MX], dfn[MX], rdfn[MX], s_end[MX];
LL c[MX];

void pre_hld(int u, int fa) {
  ::fa[u] = fa;
  siz[u] = 1;
  dep[u] = dep[fa] + 1;
  for (int i = head[u]; i; i = nxt[i]) {
    int &v = to[i];
    if (v == fa) continue;
    pre_hld(v, u);
    if (siz[v] > siz[h_ch[u]]) h_ch[u] = v;
    siz[u] += siz[v];
  }
}

int dfn_cnt;
void hld(int u, int fa) {
  dfn[u] = ++dfn_cnt;
  rdfn[dfn_cnt] = u;
  hld()
}

void init() {
  for (int i = 0; i < n; ++i) {
    cin >> c[i + 1];
  }
  for (int i = 1, a, b; i < n; ++i) {
    cin >> a >> b;
    add_edge(a, b)
    add_edge(b, a)
  }
  pre_hld(root, 0);
  hld(root, 0);
}

void solve() {
  int T, x, y;
  LL val;
  cin >> T;
}

int main() {
  cin.tie(NULL);
  std::ios::sync_with_stdio(false);
  cin >> n >> q >> root >> mod;
  init();
  while (q--)
    solve();
  return 0;
}
