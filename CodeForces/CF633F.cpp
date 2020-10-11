// CodeForces/CF633F.cpp
// https://codeforces.com/problemset/problem/633/F
// Created by learntocode1024 on 10/10/20.
//

#include <iostream>
#define MX 100001
using std::cin;

struct edge {
  int to;
  edge* nxt = nullptr;
  void init(const int& num, edge* &ptr) {
    to = num;
    nxt = ptr;
  }
};

int n;
int val[MX];
edge pool[MX << 1]; int tot = -1;
edge* head[MX];

inline void add_edge(const int &fr, const int &to) {
  pool[++tot].init(to, head[fr]);
  head[fr] = pool + tot;
}

int main() {
  // iostream status set
  std::ios::sync_with_stdio(false);
  cin.tie(nullptr);
  // input
  cin >> n;
  for (int kI = 1; kI <= n; cin >> val[kI], ++kI);
  for (int kI = 1, a, b; kI < n; ++kI) {
    cin >> a >> b;
    add_edge(a, b);
    add_edge(b, a);
  }

  return 0;
}