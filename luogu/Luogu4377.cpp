// luogu/P4377.cpp
// https://www.luogu.com.cn/problem/P4377
// Created by learntocode1024 on 9/21/20.
// frac-programming Example
// AC

#include <cstdio>
#include <algorithm>
using std::max;
using std::min;
#define MX_N 255
#define MX_W 1000
#define MX_RATE 250
const float EPS = 1e-6;

int n, W;
int w[MX_N];
int t[MX_N];
double dp[MX_W]; // dp to ensure W meets the restriction

bool check(double var) { // dp check function
  for (int i = 1; i < MX_W; ++i) dp[i] = -1e9;
  for (int kI = 0; kI < n; ++kI) {
    for (int kW = W; kW >= 0; --kW) {
      int curr = min(W, kW + w[kI]);
      dp[curr] = max(dp[curr], dp[kW] + (double)t[kI] - var * w[kI]);
    }
  }
  return dp[W] > 0;
}

int main() {
  scanf("%d%d", &n, &W);
  for (int kI = 0; kI < n;scanf("%d%d", w + kI, t + kI), ++kI);
  // binary check
  double L = 0, R = MX_RATE, mid;
  while (R - L > EPS) {
    mid = L + (R - L)/2;
    if (check(mid)) L = mid;
    else R = mid;
  }
  int ans = (int)(L * 1000);
  printf("%d", ans);
  return 0;
}