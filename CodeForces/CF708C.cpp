// luogu/Luogu708C.cpp
// https://codeforces.com/problemset/problem/708/C
// Created by learntocode1024 on 10/04/20.
// 

#include <iostream>
#define MX 400001
using std::cin;
struct edge {
  int to;
  edge* nxt = nullptr;
};
edge* head[MX];

edge pool[MX << 1];
int it = -1;
void add_edge(const int &a, const int &b) {
  pool[++it].to = b;
  pool[it].nxt = head[a];
  head[a] = pool + it;
}
int n;
int size[MX];

void dfs(const int &curr) {
  size[curr] = 1;
  for (edge* iter = head[curr]; iter != nullptr; iter = iter->nxt) {
    int child = iter->to;
    if (size[child]) continue;
    dfs(child);
    size[curr] += size[child];
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (int kI = 1, a, b; kI < n; ++kI) {
    cin >> a >> b;
    add_edge(a, b);
    add_edge(b, a);
  }

  return 0;
}
