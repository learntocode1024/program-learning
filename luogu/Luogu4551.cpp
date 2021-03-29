// luogu/Luogu4551.cpp
// Mar 29, 2021
// tag: 01-trie, xor

#include <cstdio>
#include <iostream>
#define MX 100005
using namespace std;

// BEGIN TRIE
namespace trie {
  int nxt[2][MX * 32], tot = 1;
  void insert(unsigned val) {
    int curr = 1;
    for (int i = 31; i >= 0; --i) {
      int v = (val >> i) & 1;
      if (nxt[v][curr]) curr = nxt[v][curr];
      else curr = nxt[v][curr] = ++tot;
    }
  }
  unsigned max_xor(unsigned val) {
    unsigned ans = 0;
    int curr = 1;
    for (int i = 31; i >= 0; --i) {
      int v = ~(val >> i) & 1;
      if (nxt[v][curr]) {
        curr = nxt[v][curr];
        ans += (1 << i);
      } else {
        curr = nxt[v ^ 1][curr];
      }
    }
    return ans;
  }
}
// END TIRE

#define add_edge(X, Y, Z)                                                      \
  to[++tot] = Y;                                                               \
  nxt[tot] = head[X];                                                          \
  ce[tot] = Z;                                                                 \
  head[X] = tot;
int head[MX], to[MX * 2], nxt[MX * 2], tot;
unsigned c[MX], ce[MX * 2];

void dfs(int u, int fa, unsigned val) {
  c[u] = val;
  trie::insert(val);
  for (int i = head[u]; i; i = nxt[i]) {
    int &v = to[i];
    if (v != fa) dfs(v, u, val ^ ce[i]);
  }
}

int main() { 
  int n;
  cin >> n;
  for (int i = 1; i < n; ++i) {
    int a, b;
    unsigned c;
    cin >> a >> b >> c;
    add_edge(a, b, c) add_edge(b, a, c)
  }
  dfs(1, 0, 0);
  unsigned ans = 0;
  for (int i = 1; i <= n; ++i) {
    ans = max(ans, trie::max_xor(c[i]));
  }
  cout << ans << endl;
  return 0;
}
