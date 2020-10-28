// luogu/P1272.cpp
// https://www.luogu.com.cn/problem/P1272
// Created by learntocode1024 on 9/26/20.
// AC on Sep 28 2020

#include <vector>
#include <cstring>
#include <cstdio>
#define MX 15
const int inf = 0x7FFF;
using std::memset;
using std::vector;
int n, p;
vector<int> adj[MX];
int size[MX];
bool vis[MX];
int dp[MX][MX];

int min(const int &a, const int &b) {
  if (a > b) return b;
  return a;
}

void init() {
  memset(vis, 0, sizeof(vis));
  memset(dp, 0x7F, sizeof(dp));
  dp[1][1] = adj[1].size();
  for (int i = 2; i <= n; ++i)
    dp[i][1] = adj[i].size() - 1;
}

void dfs(int curr) {
  vis[curr] = true;
  size[curr] = 1;
  for (int child : adj[curr]) {
    if (vis[child]) continue;
    dfs(child);
    size[curr] += size[child];
    // dp
    for (int num = size[curr]; num > 0; --num) {
      for (int kI = num - 1; kI > 0; --kI) {
        dp[curr][num] = min(dp[curr][num],
                            dp[curr][num - kI] + dp[child][kI] - 1);
      }
    }
  }
  dp[curr][size[curr]] = 0;
}

int main() {
  scanf("%d%d", &n, &p);
  for (int kI = 1, fr, to; kI < n; ++kI) {
    scanf("%d%d", &fr, &to);
    adj[fr].push_back(to);
    adj[to].push_back(fr);
  }
  init();
  dfs(1);
  int ans = dp[1][p];
  for (int kJ = 2; kJ <= n; ++kJ) {
    ans = min(ans, dp[kJ][p] + 1);
  }
  printf("%d", ans);
  return 0;
}
