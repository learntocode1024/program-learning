// luogu/Luogu6623.cpp
// Author: misaka18931
// Date: Mar 29, 2021
// tag: 01-trie, xor, trie-merge

#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
#define MX 525015

namespace trie {

struct digit {
  unsigned val;
  digit* ch[2];
  int w;
  digit() : val(0), ch{0, 0}, w(0) {};
};

void pushup(digit* u) {
  u->val = u->w = 0;
  if (u->ch[0]) {
    u->val ^= u->ch[0]->val << 1;
    u->w += u->ch[0]->w;
  }
  if (u->ch[1]) {
    u->val ^= (u->ch[1]->val << 1) | (u->ch[1]->w & 1);
    u->w += u->ch[1]->w;
  }
}

void insert(digit *&u, unsigned v, int dep) {
  if (!u) u = new digit();
  if (dep == 21) return (void) (u->w++);
  insert(u->ch[v & 1], v >> 1, dep + 1);
  pushup(u);
}

void addall(digit *u) {
  swap(u->ch[0], u->ch[1]);
  if (u->ch[0]) addall(u->ch[0]);
  pushup(u);
}

void merge(digit* src, digit *&dest) {
  if (!dest)
    return (void)(dest = src);
  dest->val ^= src->val;
  dest->w += src->w;
  if (src->ch[0])
    merge(src->ch[0], dest->ch[0]);
  if (src->ch[1])
    merge(src->ch[1], dest->ch[1]);
  if (src) delete src;
}

} // namespace trie

trie::digit * rt[MX];

// begin Graph
#define add_edge(X, Y)                                                         \
  to[++tot] = Y;                                                               \
  nxt[tot] = head[X];                                                          \
  head[X] = tot;
int head[MX], to[MX * 2], nxt[MX * 2], fa[MX], tot;
unsigned c[MX];

long long ans = 0;

void dfs(int u) {
  for (int i = head[u]; i; i = nxt[i]) {
    int &v = to[i];
    if (v == fa[u]) continue;
    dfs(v);
    trie::merge(rt[v], rt[u]);
  }
  if (rt[u]) trie::addall(rt[u]);
  trie::insert(rt[u], c[u], 0);
  ans += rt[u]->val;
}
// end Graph

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i)
    cin >> c[i + 1];
  for (int i = 2; i <= n; ++i) {
    cin >> fa[i];
    add_edge(i, fa[i])
    add_edge(fa[i], i)
  }
  dfs(1);
  cout << ans << endl;
  return 0;
}
