// luogu/Luogu5658.cpp
// https://www.luogu.com.cn/problem/P5658
// Created by learntocode1024 on 11/04/20.
// 

#include <cstdio>
#include <stack>
#include <cstring>
#define MX 500005
int head[MX], nxt[MX], to[MX], tot;
int fa[MX];
char str[MX];

inline void add_edge(const int &a, const int &b) {
  to[++tot] = b;
  nxt[tot] = head[a];
  head[a] = tot;
}

unsigned long long ans, num[MX];

int cnt[MX];
std::stack<int> S;
void dfs(int curr) {
  int pre = 0;
  if (str[curr] == '(') S.push(curr);
  else {
    if (!S.empty()) {
      pre = S.top();
      S.pop();
      cnt[curr] = cnt[fa[pre]] + 1;
      num[curr] = num[fa[curr]] + cnt[curr];
    }
  }
  for (int kI = head[curr]; kI != 0; kI = nxt[kI]) {
    int &next = to[kI];
    dfs(next);
  }
  if (str[curr] == '(') S.pop();
  if (pre != 0) {
    S.push(pre);
  }
}

int main() {
  int n;
  scanf("%d", &n);
  scanf("%s", str + 1);
  for (int kI = 2, tmp; kI <= n; ++kI) {
    scanf("%d", &tmp);
    add_edge(tmp, kI);
    fa[kI] = tmp;
  }
  dfs(1);
  for (int kI = 1, tmp; kI <= n; ++kI) {
    ans ^= num[kI] * kI;
  }
  printf("%lld\n", ans);
  return 0;
}
