// loj/10091_popular_cows.cpp
// https://loj.ac/p/10091
// tag: tarjan-scc
// AC

#include <algorithm>
#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;

#define MX 10005
#define MAX_M 50005
#define add_edge(X, Y)                                                         \
  to[++tot] = Y;                                                               \
  nxt[tot] = head[X];                                                          \
  head[X] = tot;
int head[MX], to[MAX_M], nxt[MAX_M], tot;
int scc_id[MX], cnt;
int low[MX], dfn[MX], out[MX], siz[MX];
bool in_stack[MX];

stack<int> s;
int t;
void tarjan(int u) {
  dfn[u] = low[u] = ++t;
  in_stack[u] = true;
  s.push(u);
  for (int i = head[u]; i; i = nxt[i]) {
    int &v = to[i];
    if (!low[v]) {
      tarjan(v);
      low[u] = min(low[u], low[v]);
    } else if (in_stack[v]) low[u] = min(low[u], dfn[v]);
  }
  if (low[u] == dfn[u]) {
    ++cnt;
    int v;
    do {
      siz[cnt] ++;
      v = s.top();
      s.pop();
      scc_id[v] = cnt;
      in_stack[v] = false;
    } while (v != u);
  }
}

int n, m;

int main() { 
  cin >> n >> m;
  // for (int i = 0; i < n; ++i) {
  for (int i = 0; i < m; ++i) { // HOW ON EARTH I only read n of the edges!
    int a, b;
    cin >> a >> b;
    add_edge(a, b)
  }
  for (int i = 1; i <= n; ++i) {
    if (!dfn[i]) tarjan(i);
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = head[i]; j; j = nxt[j]) {
      if (scc_id[i] != scc_id[to[j]])
        ++out[scc_id[i]];
    }
  }
  int ans = 0;
  for (int i = 1; i <= cnt; ++i) {
    if (out[i] == 0) {
      if (!ans) ans = i;
      else {
        cout << 0 << endl;
        return 0;
      }
    }
  }
  cout << siz[ans] << endl;
  return 0;
}