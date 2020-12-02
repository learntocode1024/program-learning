// CodeForces/CF1444C.cpp
// https://codeforces.com/problemset/problem/1444/C
// Created by learntocode1024 on 12/02/20.
// 

#include <cstdio>
#include <utility>
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#define MX 500005

int n, m, k;
int head[MX], nxt[2 * MX], to[2 * MX], tot;
int grp[MX], vis[MX];
void add_edge(int a, int b) {
  to[++tot] = b;
  nxt[tot] = head[a];
  head[a] = tot;
}

void dfs(int root) {

}

void solve() {
  cin >> n >> m >> k;
  for (int i = 1; i <= n; ++i) {
    cin >> grp[i];
  }
  for (int i = 0, a, b; i < m; ++i) {
    cin >> a >> b;
    add_edge(a, b);
    add_edge(b, a);
  }
  for (int i = 1; i <= n; ++i) {
    if (!vis[i]) dfs(i);
  }
  
}

int main() {
  cin.tie(NULL);
  std::ios::sync_with_stdio(false);
  int T = 1;
  while (T--) {
    solve();
  }
  return 0;
}
