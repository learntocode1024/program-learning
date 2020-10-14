// luogu/Luogu3205.cpp
// https://www.luogu.com.cn/problem/P3205
// Created by learntocode1024 on 10/14/20.
// AC on 10/14/20
#include <iostream>
#define MX 1001
using std::cin;
using std::cout;
const int mod = 19650827;
int n;
int height[MX];
int dp[MX][MX][2];
int main() {
  cin >> n;
  for (int kI = 1, t; kI <= n; ++kI) {
    cin >> t;
    height[kI] = t;
  }
  for (int kI = 1; kI <= n; ++kI) {
    dp[kI][kI][0] = 1;
    dp[kI][kI][1] = 0;
  }
  for (int step = 1; step < n; ++step) {
    for (int beg = 1; beg <= n - step; ++beg) {
      int end = beg + step;
      if (height[beg] < height[beg + 1]) dp[beg][end][0] += dp[beg + 1][end][0];
      if (height[beg] < height[end])     dp[beg][end][0] += dp[beg + 1][end][1];
      if (height[end] > height[end - 1]) dp[beg][end][1] += dp[beg][end - 1][1];
      if (height[end] > height[beg])     dp[beg][end][1] += dp[beg][end - 1][0];
      dp[beg][end][0] %= mod;
      dp[beg][end][1] %= mod;
    }
  }
  cout << (dp[1][n][0] + dp[1][n][1])%mod << std::endl;
  return 0;
}