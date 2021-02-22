// luogu/Luogu2495.cpp
// Author: misaka18931
// Date: 02-22-21
// URL: https://www.luogu.com.cn/problem/P2495
// tag: Virtual-tree, dp
//

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <stack>
#include <vector>
#define MX 250005
#define add_edge(X, Y, Z)                                                      \
  to##Z[++tot##Z] = Y;                                                         \
  nxt##Z[tot##Z] = head[X];                                                    \
  head##Z[X] = tot##Z;
#define lowbit(X) (X & (~X + 1))
using namespace std;
typedef long long LL;

int n;
int st[MX][20], lg2[MX], depth[MX];
int head0[MX], nxt0[2 * MX], to0[2 * MX], tot0;
int head[MX], nxt[2 * MX], to[2 * MX], tot;

LL dp[MX], c[MX];
LL c0[2 * MX];
int id[MX];

void dfs0(int u) {
  static int cnt = 0;
  id[u] = ++cnt;
  for (int i = head[u]; i; i = nxt[i]) {
    int &v = to[i];
    if (id[v]) {
      depth[u] = depth[v] + 1;
      st[u][0] = v;
      c[u] = c0[i];
      continue;
    }
    dfs0(v);
  }
}

void getst() {
  for (int i = 1; i < n; ++i) {
    lg2[i] = lg2[i - 1] + (i == (1 << lg2[i - 1]));
  }
  for (int step = 1; step < 19; ++step) {
    for (int i = 1; i <= n; ++i) {
      st[i][step] = st[st[i][step - 1]][step - 1];
    }
  }
}

int lca(int a, int b) {
  if (depth[a] < depth[b]) swap(a, b);
  int d = depth[a] - depth[b];
  while (d) {
    a = st[a][lg2[lowbit(d)]];
    d -= lowbit(d);
  }
  if (a == b) return a;
  int step = 0;
  
}

stack<int> node;
vector<int> key;

void solve() {
  int k;
  cin >> k;
  for (int i = 0; i < k; ++i) {
    cin >> key[i];
    if (i + 1 != k) key.push_back(0);
  }
  // build Virtual tree
  sort(key.begin(), key.end(), [](int a, int b) { return id[a] < id[b]; });
  node.push(1);
  for (auto i : key) {
    
  }
}

int main() {
  cin.tie(NULL);
  std::ios::sync_with_stdio(false);
  cin >> n;
  for (int i = 1, a, b; i < n; ++i) {
    cin >> a >> b;
    add_edge(a, b, 0);
    cin >> c0[tot0];
    add_edge(b, a, 0) c0[tot0] = c0[tot0 - 1];
  }
  dfs0(1);
  getst();
  int T = 1;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
