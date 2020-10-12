// CodeForces/CF633F.cpp
// https://codeforces.com/problemset/problem/633/F
// Created by learntocode1024 on 10/10/20.
//

#include <iostream>
#include <algorithm>
#define MX 100001
#define root 1
using std::cin;
using std::cout;
using std::max;

struct edge {
  int to = 0;
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
long long max_path[MX][2];
long long d[MX];
long long d_chi[MX];

inline void update(int curr, long long val) {
  if (val > max_path[curr][0]) {
    max_path[curr][1] = max_path[curr][0];
    max_path[curr][0] = val;
  } else if (val > max_path[curr][1]) {
    max_path[curr][1] = val;
  }
}

void get_mx(const int &curr, const int& fa) {
  for (edge* iter = head[curr]; iter != nullptr; iter = iter->nxt) {
    int child = iter -> to;
    if (child == fa) continue;
    get_mx(child, curr);
    update(curr, max_path[child][0]);
  }
  max_path[curr][0] += val[curr];
  max_path[curr][1] += val[curr];
}

void get_d(const int &curr, const int& fa) {
  d[curr] = max_path[curr][0] - val[curr] + max_path[curr][1];
  for (edge* iter = head[curr]; iter != nullptr; iter = iter->nxt) {
    int child = iter -> to;
    if (child == fa) continue;
    get_d(child, curr);
    d_chi[curr] = max(d_chi[curr], d[child]);
  }
  d[curr] = max(d[curr], d_chi[curr]);
}

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
  get_mx(root, 0);
  get_d(root, 0);
  return 0;
}