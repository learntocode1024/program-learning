// luogu/P1642.cpp
// https://www.luogu.com.cn/problem/P1642
// Created by learntocode1024 on Sep 21 2020.
// AC on Sep 25 2020

#include <cstdio>
#include <vector>
#include <algorithm>
#include <memory.h>
#define MX 105
using std::vector;
using std::max;
using std::min;
const float EPS = 1e-3;

int n, m;
int a[MX];
int b[MX];
float dp[MX][MX];
vector<int> adj[MX];
bool vis[MX] = {0};
int size[MX];

void dfs(int curr) {
  vis[curr] = true;
  size[curr] = 1;
  for (int child : adj[curr]) {
    if (!vis[child]) {
      dfs(child);
      size[curr] += size[child];
       for (int k_num = min(n - m, size[curr]); k_num > 0; --k_num) {
         // Below Is WRONG! states greater than size[curr] may NOT be updated!
//      for (int select = 1; select < min(size[curr], k_num); ++select) {
        for (int select = 1; select < k_num; ++select) {
          dp[curr][k_num] = max(dp[curr][k_num],
                                dp[curr][k_num - select] + dp[child][select]);
        }
      }
    }
  }
}

bool check(float mid) {
  memset(vis, 0, sizeof(vis));
  for (int i = 1; i <= n; ++i) dp[i][1] = (float)a[i] - mid*b[i];
  // DON'T forget the -INF Initialization!!!
  for (int i = 1; i <= n; ++i)
    for (int j = 2; j <= n - m; ++ j)
      dp[i][j] = -1e9;
  dfs(1);
  for (int i = 1; i <= n; ++i)
    if (dp[i][n - m] > 0) return true;
  return false;
}

int main() {
  // int
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", a + i);
  }
  for (int i = 1; i <= n; ++i) {
    scanf("%d", b + i);
  }
  for (int i = 1, beg, end; i < n; ++i) {
    scanf("%d%d", &beg, &end);
    adj[beg].push_back(end);
    adj[end].push_back(beg);
  }
  // frac-programming
  float l = 0, r = 1e6, mid;
  while (r - l > EPS) {
    mid = l + (r - l)/2;
    if (check(mid))
      l = mid;
    else
      r = mid;
  }
  printf("%.1f", mid);
  return 0;
}