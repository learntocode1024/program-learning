// luogu/Luogu1726.cpp
// https://www.luogu.com.cn/problem/P1726
// Created by learntocode1024 on 10/29/20.
//
// tarjan-scc template

#include <cstdio>
#include <algorithm>
#include <cstring>
#include <stack>
#define MX 5005

inline int max(const int &a, const int &b) {
  if (a > b) return a;
  return b;
}

inline int min(const int &a, const int &b) {
  if (a < b) return a;
  return b;
}

// Graph
int head[MX], nxt[MX*2], edge[MX*2], tot, mx_node;

inline void add_edge(const int &fr, const int &to) {
  edge[++tot] = to;
  nxt[tot] = head[fr];
  head[fr] = tot;
}

// tarjan_scc
int id[MX], scc_id[MX];
int clock, cnt_scc, mx_size;
std::stack<int> S;

int tarjan_dfs(int curr) {
  id[curr] = ++clock;
  int low_link = clock;
  S.push(curr);
  for (int iter = head[curr]; iter != 0; iter = nxt[iter]) {
    const int &next = edge[iter];
    if (id[next] == 0) {
      low_link = min(low_link, tarjan_dfs(next));
    } else if (scc_id[next] == 0) {
      low_link = min(low_link, id[next]);
    }
  }
  if (low_link == id[curr]) { // extract scc
    ++cnt_scc; int tmp; int size = 0;
    do {
      ++size;
      tmp = S.top();
      S.pop();
      scc_id[tmp] = cnt_scc;
    } while (curr != tmp);
    mx_size = max(mx_size, size);
  }
  return low_link;
}

void find_scc() {
  for (int kI = 1; kI <= mx_node; ++kI) {
    if (id[kI] == 0) {
      tarjan_dfs(kI);
    }
  }
}

int m;

int main() {
  scanf("%d%d", &mx_node, &m);
  int state, a, b;
  while (m--) {
    scanf("%d%d%d", &a, &b, &state);
    add_edge(a, b);
    if (state == 2) add_edge(b, a);
  }
  find_scc();
  printf("%d\n", mx_size);

  for (int kI = 1; kI <= mx_node; ++kI) {
    printf("%d ", scc_id[kI]);
  }
  printf("\n");
  return 0;
}
