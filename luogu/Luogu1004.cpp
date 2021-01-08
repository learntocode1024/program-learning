// luogu/P1004.cpp
// https://www.luogu.com.cn/problem/P1004
// Created by learntocode1024 on Sat Aug 22 2020.
// AC
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int map[10][10];
int dp[10][10][10];

int main() {
  int n;
  cin >> n;
  {
    int a, b, c;
    cin >> a >> b >> c;
    while (a) {
      map[a - 1][b - 1] = c;
      cin >> a >> b >> c;
    }
  } // input
  dp[0][0][0] = map[0][0];
  for (int step = 1; step < n * 2 - 1; ++step) {
    for (int i = 0; i <= min(step, n - 1); ++i) {
      for (int j = 0; j <= min(step, n - 1); ++j) {
        if (i) dp[i][j][step] = max(dp[i][j][step], dp[i - 1][j][step - 1]);
        if (j) dp[i][j][step] = max(dp[i][j][step], dp[i][j - 1][step - 1]);
        dp[i][j][step] = max(dp[i][j][step], dp[i][j][step - 1]);
        if (i & j) dp[i][j][step] = max(dp[i][j][step], dp[i - 1][j - 1][step - 1]);
        if (i != j) dp[i][j][step] += map[i][step - i] + map[j][step - j];
        else dp[i][j][step] += map[i][step - i];
      }
    }
  }
  cout << dp[n - 1][n - 1][2 * n - 2] << endl;
  return 0;
}
