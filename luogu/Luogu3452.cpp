// luogu/Luogu3452.cpp
// https://www.luogu.com.cn/problem/P3452
// Created by learntocode1024 on 12/01/20.
// 

#include <cstdio>
#include <memory.h>
#include <algorithm>
#include <queue>
#include <iostream>
#define MX 200005
using std::cin;
using std::cout;
using std::endl;

int n, m;
int head[MX], nxt[MX * 10], to[MX * 10], tot;

void add_edge(int a, int b) {
  to[++tot] = b;
  nxt[tot] = head[a];
  head[a] = tot;
}

int num[MX], t;
bool vis[MX] = {0};
bool tag[MX];
std::queue<int> q;

int bfs(int init) {
  memset(tag, 0, n * sizeof(bool));
  int cnt = 0;
  while (!q.empty()) q.pop();
  q.push(init);
  while (!q.empty()) {
    int curr = q.front();
    q.pop();
    vis[curr] = true;
    for (int it = head[curr]; it != 0; it = nxt[it]) {
      if (vis[to[it]] || tag[to[it]]) continue;
      tag[to[it]] = true;
    }
    for (int i = 1; i <= n; ++i) {
      if (!vis[i] && !tag[i]) {
        ++cnt;
        q.push(i);
        vis[i] = true;
      }
    }
  }
  return cnt;
}

void solve() {
  cin >> n >> m;
  for (int i = 0, a, b; i < m; ++i) {
    cin >> a >> b;
    add_edge(a, b);
    add_edge(b, a);
  }
  for (int i = 1; i <= n; ++i) {
    if (!vis[i]) num[t++] = bfs(i);
  }
  std::sort(num, num + t);
  cout << t << endl;
  for (int i = 0; i < t; ++i) {
    cout << num[i] << " ";
  }
  cout << endl;
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
