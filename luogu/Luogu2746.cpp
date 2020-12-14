// luogu/Luogu2746.cpp
// Author: learntocode1024
// Date: 12-14-20
// URL: https://www.luogu.com.cn/problem/P2746
// tag: tarjan-scc
// AC

#include <cstdio>
#include <cstring>
#include <stack>
#include <iostream>
#define MX 5000005
using std::cin;
using std::cout;
using std::endl;

int head[10005], to[MX], nxt[MX], clk = 1, tot, n;
int scc_cnt;
int dfn[10005], scc[10005];
bool degin[10005], degout[10005];
bool instack[10005];

int min(int a, int b) {
 if (a < b) return a;
 return b;
}

int max(int a, int b) {
 if (a > b) return a;
 return b;
}

void add_edge(int a, int b) {
  to[++tot] = b;
  nxt[tot] = head[a];
  head[a] = tot;
}

std::stack<int> s;

int tarjan(int curr) {
  int low = dfn[curr] = ++clk;
  s.push(curr);instack[curr] = true;
  for (int i = head[curr]; i != 0; i = nxt[i]) {
    const int& next = to[i];
    if (dfn[next] == 0) {
      low = min(low, tarjan(next));
    } else if (instack[next]) {
      low = min(low, dfn[next]);
    }
  }
  if (low == dfn[curr]) {
    ++scc_cnt;
    int tmp;
    do {
      tmp = s.top();
      scc[tmp] = scc_cnt;
      s.pop();
      instack[tmp] = false;
    } while (tmp != curr);
  }
  return low;
}

void solve() {
  cin >> n;
  for (int i = 1, j; i <= n; ++i) {
    while (cin >> j && j != 0) {
      add_edge(i, j);
    }
  }
  for (int i = 1; i <= n; ++i) {
    if (!dfn[i]) tarjan(i);
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = head[i]; j != 0; j = nxt[j]) {
      if (scc[i] != scc[to[j]]) {
        degin[scc[i]] = true;
        degout[scc[to[j]]] = true;
      }
    }
  }
  int A = 0, B = 0;
  for (int i = 1; i <= scc_cnt; ++i) {
    if (degin[i] == 0) A++;
    if (degout[i] == 0) B++;
  }
  if (scc_cnt == 1) cout << "1\n0" << endl;
  else cout << A << "\n" << max(A, B) << endl;
}

int main() {
  cin.tie(NULL);
  std::ios::sync_with_stdio(false);
  int T = 1;
  // cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
