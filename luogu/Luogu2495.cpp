// luogu/Luogu2495.cpp
// Author: misaka18931
// Date: 02-22-21
// URL: https://www.luogu.com.cn/problem/P2495
// tag: Virtual-tree, dp
// AC

#include <algorithm>
#include <climits>
#include <cstdio>
#include <iostream>
#include <stack>
#include <vector>
#define MX 250005
#define add_edge(X, Y, Z)                                                      \
  to##Z[++tot##Z] = Y;                                                         \
  nxt##Z[tot##Z] = head##Z[X];                                                 \
  head##Z[X] = tot##Z;
using namespace std;
typedef long long LL;

int n;
int st[MX][20], depth[MX];
LL c1[MX][20];
int head0[MX], nxt0[2 * MX], to0[2 * MX], tot0;
int head[MX], nxt[MX], to[MX], tot;

LL dp[MX], c[MX];
LL c0[2 * MX];
int id[MX];

int cnt = 0;
void dfs0(int u, int fa) {
  id[u] = ++cnt;
  depth[u] = depth[fa] + 1;
  st[u][0] = fa;
  for (int i = head0[u]; i; i = nxt0[i]) {
    int &v = to0[i];
    if (v == fa) { // v is father
      c1[u][0] = c0[i];
      continue;
    }
    dfs0(v, u);
  }
}

void getst() {
  for (int step = 1; step < 19; ++step) {
    for (int i = 1; i <= n; ++i) {
      st[i][step] = st[st[i][step - 1]][step - 1];
      c1[i][step] = min(c1[i][step - 1], c1[st[i][step - 1]][step - 1]);
    }
  }
}

int lca(int a, int b) {
  if (depth[a] < depth[b])
    swap(a, b);
  if (depth[a] > depth[b]) {
    for (int t = 19; t >= 0; --t) {
      if (depth[st[a][t]] > depth[b]) {
        a = st[a][t];
      }
    }
    a = st[a][0];
  }
  if (a == b)
    return a;
  for (int t = 19; t >= 0; --t) {
    if (st[a][t] != st[b][t]) {
      a = st[a][t];
      b = st[b][t];
    }
  }
  return st[a][0];
}

LL getdist(int a, int b) {
  LL dist = __INT64_MAX__;
  if (depth[a] < depth[b])
    swap(a, b);
  for (int t = 19; t >= 0; --t) {
    if (depth[st[a][t]] > depth[b]) {
      dist = min(dist, c1[a][t]);
      a = st[a][t];
    }
  }
  dist = min(dist, c1[a][0]);
  return dist;
}

stack<int> node;
vector<int> key;
int on_demand[MX];

void dfs(int u) {
  for (int i = head[u]; i; i = nxt[i]) {
    int &v = to[i];
    if (depth[v] < depth[u])
      continue;
    dfs(v);
    dp[u] += dp[v];
    // clear child data
    dp[v] = on_demand[v] = c[v] = head[v] = 0;
  }
  if (on_demand[u])
    dp[u] = c[u];
  else
    dp[u] = min(c[u], dp[u]);
}

void solve() {
  int k;
  cin >> k;
  key = vector<int>(k);
  for (int i = 0; i < k; ++i) {
    cin >> key[i];
    head[key[i]] = 0;
    on_demand[key[i]] = 1;
  }
  // build Virtual tree
  sort(key.begin(), key.end(), [](int a, int b) { return id[a] < id[b]; });
  node.push(1);
  for (auto i : key) {
    int p = lca(i, node.top());
    if (p == node.top())
      node.push(i);
    else {
      while (id[node.top()] > id[p]) {
        int u = node.top();
        node.pop();
        if (id[node.top()] < id[p])
          node.push(p);
        c[u] = getdist(u, node.top());
        add_edge(node.top(), u, )
      }
      node.push(i);
    }
  }
  while (!node.empty()) {
    int u = node.top();
    node.pop();
    if (node.empty())
      break;
    c[u] = getdist(u, node.top());
    add_edge(node.top(), u, )
  }
  // dp on virtual tree
  dfs(1);
  cout << dp[1] << endl;
}

inline void clear() {
  tot = 0;
  dp[1] = on_demand[1] = head[1] = 0;
  c[1] = INT64_MAX;
}

int main() {
  cin.tie(nullptr);
  std::ios::sync_with_stdio(false);
  cin >> n;
  for (int i = 1, a, b; i < n; ++i) {
    cin >> a >> b;
    add_edge(a, b, 0);
    cin >> c0[tot0];
    add_edge(b, a, 0) c0[tot0] = c0[tot0 - 1];
  }
  dfs0(1, 0);
  getst();
  int T = 1;
  cin >> T;
  while (T--) {
    clear();
    solve();
  }
  return 0;
}
