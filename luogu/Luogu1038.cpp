// luogu/Luogu1038.cpp
// https://www.luogu.com.cn/problem/P1038
// Created by learntocode1024 on 11/04/20.
// AC on 11/4/20

#include <iostream>
#include <stack>
#define MX 105
using std::cin;
using std::cout;

int head[MX], nxt[MX], to[MX], w[MX], tot, stat[MX];
bool vis[MX]{0};

inline void add_edge(const int &a, const int &b, const int &c) {
  to[++tot] = b;
  w[tot] = c;
  nxt[tot] = head[a];
  head[a] = tot;
}


std::stack<int> order;
void topo_sort(int curr) {
  vis[curr] = true;
  for (int kI = head[curr]; kI != 0; kI = nxt[kI]) {
    if (!vis[to[kI]]) topo_sort(to[kI]);
  }
  order.push(curr);
}

int main() {
  int n, p;
  cin >> n >> p;
  for (int kI = 1, c, t; kI <= n; ++kI) {
    cin >> c >> t;
    if (c != 0) stat[kI] = c;
    else stat[kI] = -t;
  }
  int a, b, c;
  while (p--) {
    cin >> a >> b >> c;
    add_edge(a, b, c);
  }
  for (int kI = 1; kI <= n; ++kI) {
    if (!vis[kI]) topo_sort(kI);
  }
  int curr;
  while (!order.empty()) {
    curr = order.top();
    order.pop();
    if (stat[curr] <= 0) continue;
    for (int kI = head[curr]; kI != 0; kI = nxt[kI]) {
      stat[to[kI]] += w[kI] * stat[curr];
    }
  }
  int sum = 0;
  for (int kI = 1; kI <= n; ++kI) {
    if (head[kI] == 0) sum += stat[kI];
  }
  if (sum == 0) {
    cout << "NULL\n";
    return 0;
  }
  for (int kI = 1; kI <= n; ++kI) {
    if (head[kI] == 0 && stat[kI] > 0) cout << kI << ' ' << stat[kI] << '\n';
  }
  return 0;
}
