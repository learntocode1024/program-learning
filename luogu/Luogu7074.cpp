// luogu/Luogu7074.cpp
// https://www.luogu.com.cn/problem/P7074
// Created by learntocode1024 on 11/09/20.
// 

#include <iostream>
#define MX 1005
using std::cin;
using std::cout;

int max(int a, int b) {
  if (a > b) return a;
  return b;
}

int map[MX][MX];
int dp[MX][MX];

int dist(int k, int a, int b) {
  if (a >= b) return map[k][a] - map[k][b - 1];
  return map[k][b] - map[k][a - 1];
}

int n, m;

int main() {
  cin >> n >> m;
  for (int kI = 0; kI < n; ++kI) {
    for (int kJ = 0; kJ < m; ++kJ) {
      cin >> map[kJ][kI];
    }
  }
  for (int kI = 0; kI < m; ++kI) {
    for (int kJ = 1; kJ < n; ++kJ) {
      map[kI][kJ] += map[kI][kJ - 1];
    }
  }
  for (int kI = 0; kI < n; ++kI) {
    dp[0][kI] = map[0][kI];
  }
  for (int kI = 1; kI < m; ++kI) {
    for (int kJ = 0; kJ < n; ++kJ) {
      for (int kQ = 0; kQ < n; ++kQ) {
        dp[kI][kJ] = max(dp[kI][kJ], dp[kI - 1][kQ] + dist(kI, kJ, kQ));
      }
    }
  }
  cout << dp[m - 1][n - 1] << std::endl;
  return 0;
}
