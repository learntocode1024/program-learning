// loj/2124-haoi2015_die_on_tree.cpp
// Date: Mar 10, 2021
// tag: dp-on-tree
//

#include <climits>
#include <cstdio>
#include <iostream>
#define MX 2005
using namespace std;
typedef long long LL;

#define add_edge(X, Y, Z)                                                      \
  to[++tot] = Y;                                                               \
  nxt[tot] = head[X];                                                          \
  c[tot] = Z;                                                                  \
  head[X] = tot;

int n, k;
int head[MX], to[MX * 2], nxt[MX * 2], tot;
LL dp[MX][MX], c[MX * 2];
// dp[u][k] is the contribution of edges belongs to subtree(u), with k black nodes inside
int siz[MX];

void dfs(int u) {
  siz[u] = 1;
  for (int i = head[u]; i; i = nxt[i]) {
    int &v = to[i];
    if (siz[v]) continue;
    dfs(v);
    siz[u] += siz[v];
    for (int p = min(k, siz[u]); p >= max(0, k - n + siz[u]); --p) {
      for (int q = max(k - n + siz[v], max(p - siz[u] + siz[v], 0)); q <= min(siz[v], p); ++q) {
        LL val = c[i] * (q * (k - q) + (siz[v] - q) * (n - k - siz[v] + q));
        dp[u][p] = max(dp[u][p], dp[u][p - q] + dp[v][q] + val);
      }
    }
  }
}

int main() {
  cin >> n >> k;
  int u, v;
  LL t;
  for (int i = 1; i < n; ++i) {
    cin >> u >> v >> t;
    add_edge(u, v, t)
    add_edge(v, u, t)
  }
  dfs(1);
  cout << dp[1][k] << endl;
  return 0;
}
