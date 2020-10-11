// luogu/LuoguT150637.cpp
// https://www.luogu.com.cn/problem/T150637
// Created by learntocode1024 on 10/11/20.
//
#include <iostream>
#include <cstring>
#include <queue>
#define MX 305
using std::cin;
using std::cout;
using std::memset;
using std::queue;

struct edge {
  int to;
  edge* nxt = nullptr;
  void init(const int& num, edge* &ptr) {
     to = num;
     nxt = ptr;
  }
};

int n, m;
int val[MX];
edge pool[MX << 1]; int tot = -1;
edge* head[MX];

int gen[MX];

inline void add_edge(const int &fr, const int &to) {
  pool[++tot].init(to, head[fr]);
  head[fr] = pool + tot;
}

bool check(int node) {
  memset(gen, -1, sizeof(gen));
  gen[node] = 0;
  queue<int> q;
  q.push(node);
  int t;
  while (!q.empty()) {
    int curr = q.front(); q.pop(); t = 0;
    for (edge* iter = head[curr]; iter != nullptr; iter = iter->nxt) {
      int anc = iter->to;
      ++t;
      if (gen[anc] == -1) {
        gen[anc] = gen[curr] + 1;
        q.push(anc);
      } else if (gen[anc] <= 5) return false;
    }
    if (t != 0 && t != 2) return false;
  }
  return true;
}

int main() {
  std::cin >> n >> m;
  for (int kI = 0, a, b; kI < m; ++kI) {
    std::cin >> a >> b;
    add_edge(b, a);
  }
  for (int kI = 1; kI <= n; ++kI) {
    if (!check(kI)) {
      printf("%d", kI);
      return 0;
    }
  }
  printf("CORRECT");
  return 0;
}
