// luogu/P3177.cpp
// https://www.luogu.com.cn/problem/P3177
// Created by learntocode1024 on 9/28/20.
//

#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#define MX 22
const int inf = 0x3fffffff;
using std::vector;
using std::max;
using std::min;
using std::memset;

struct edge {
  int to;
  int val;
};

vector<edge> adj[MX];
int n, k;
int size[MX];
int dp[MX][MX][2]; // 2 spaces for colors
bool vis[MX] = {false};

void dfs(int curr) {
  vis[curr] = true;
  size[curr] = 1;
  for (edge child : adj[curr]) {
    if (vis[child.to]) continue;
    dfs(child.to);
    size[curr] += size[child.to];
    // dp
    // black
    dp[curr][1][1] += dp[child.to][0][0];
    for (int bk = size[curr]; bk > 1; --bk) {
      for (int kI = bk - 1; kI >= 0 ; --kI) {
        if (kI > size[child.to]) continue;
        if (kI != 0)
          dp[curr][bk][1] = max(dp[curr][bk][1],
                                dp[curr][bk - kI][1] + dp[child.to][kI][1] + child.val);
        if (kI != size[child.to])
          dp[curr][bk][1] = max(dp[curr][bk][1],
                                dp[curr][bk - kI][1] + dp[child.to][kI][0]);
      }
    }
    // white
    for (int bk = size[curr] - 1; bk >= 0; --bk) {
      for (int kI = bk; kI >= 0; --kI) {
        if (kI > size[child.to]) continue;
        if (kI != 0)
          dp[curr][bk][0] = max(dp[curr][bk][0],
                                dp[curr][bk - kI][0] + dp[child.to][kI][1]);
        if (kI != size[child.to])
          dp[curr][bk][0] = max(dp[curr][bk][0],
                                dp[curr][bk - kI][0] + dp[child.to][kI][0] + child.val);
      }
    }
  }
}

int main() {
  scanf("%d%d", &n, &k);
  for (int kI = 1, a, b, c; kI < n; ++kI) {
    scanf("%d%d%d", &a, &b, &c);
    adj[a].push_back({b, c});
    adj[b].push_back({a, c});
  }
  for (auto & kI : dp) {
    kI[0][1] = -inf;
  }
  dfs(1);
  for (int kI = 1; kI <= n; ++kI) {
    printf("%d:\n", kI);
    for (int kJ = 0; kJ <= n; ++kJ)
      printf("(%d)%d ",kJ, dp[kI][kJ][0]);
    printf("\n");
    for (int kJ = 0; kJ <= n; ++kJ)
      printf("(%d)%d ",kJ, dp[kI][kJ][1]);
    printf("\n==========================\n");
  }
  printf("%d", max(dp[1][k][0], dp[1][k][1]));
  return 0;
}