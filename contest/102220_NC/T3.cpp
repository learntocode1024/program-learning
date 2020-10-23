// nowcoder_contest/102220_NC/T2.cpp
// https://ac.nowcoder.com/acm/contest/7609/B
// Created by learntocode1024 on 10/22/20.
// AC on 10/22/20

#include <cstdio>
#include <cstring>
#include <queue>
#define MX 100005

struct G_edge {
  int to = 0;
  G_edge* nxt = nullptr;
} pool[MX << 1];
int tot;
G_edge* head[MX];

inline void add_edge(const int &fr, const int &to) {
  pool[tot].to = to;
  pool[tot].nxt = head[fr];
  head[fr] = pool + tot;
  ++tot;
}

int vis[MX], t_stamp = 1;
std::queue<int> q_node;
void spread() {
  if (!q_node.empty()) {
    int curr, next;
    while (!q_node.empty() && vis[q_node.front()] == t_stamp) {
      curr = q_node.front();
      q_node.pop();
      for (G_edge *iter = head[curr]; iter != nullptr; iter = iter->nxt) {
        next = iter->to;
        if (!vis[next]) {
          vis[next] = t_stamp + 1;
          q_node.push(next);
        }
      }
    }
  }
  ++t_stamp;
}

void start(int node) {
  spread();
  if (!vis[node]) {
    vis[node] = t_stamp;
    q_node.push(node);
  }
}

void reset() {
  t_stamp = 1;
  q_node = std::queue<int>();
  memset(vis, 0, sizeof(vis));
}

bool query(int node) {
  spread();
  return vis[node] > 0;
}

int m, n;

int main() {
  scanf("%d%d", &n, &m);
  { // input
    int a, b;
    for (int kI = 1; kI < n; ++kI) {
      scanf("%d%d", &a, &b);
      add_edge(a, b);
      add_edge(b, a);
    }
  }
  // solve
  int opt, x;
  while (m--) {
    scanf("%d%d", &opt, &x);
    switch (opt) {
      case 1:
        start(x);
        break;
      case 2:
        reset();
        break;
      case 3:
        if (query(x)) printf("wrxcsd\n");
        else printf("orzFsYo\n");
        break;
      default:
        break;
    }
  }
  return 0;
}