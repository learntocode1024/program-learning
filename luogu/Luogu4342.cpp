// luogu/Luogu4342.cpp
// https://www.luogu.com.cn/problem/P4342
// Created by learntocode1024 on 10/16/20.
// 
#include <iostream>
#define MX 51
#define DEBUG
using std::cin;
using std::cout;
const int inf = 0x3f3f3f3f;
int n;
bool op[MX << 1] = {false};
int dp[MX << 1][MX];

int main() {
  // input
  cin >> n;
  for (int kI = 1; kI <= (n << 1); ++kI) {
    for (int kJ = 1; kJ <= n; ++kJ) {
      dp[kI][kJ] = -inf;
    }
  }
  {
    int tmp_num;
    char tmp_op;
    for (int kI = 1; kI <= n; ++kI) {
      cin >> tmp_op >> tmp_num;
      dp[kI][1] = tmp_num;
      dp[kI + n][1] = tmp_num;
      if (tmp_op == 't') {
        op[kI] = true;
        op[kI + n] = true;
      }
    }
  }
  // dp
  for (int step = 2; step <= n; ++step) {
    for (int beg = 1; beg + step <= (n << 1); ++beg) {
      for (int kI = 1; kI < step; ++kI) {
        int curr = dp[beg][kI];
        if (op[beg + kI]) curr += dp[beg + kI][step - kI];
        else curr *= dp[beg + kI][step - kI];
        if (curr > dp[beg][step]) dp[beg][step] = curr;
      }
    }
  }
#ifdef DEBUG
  for (int kI = 1; kI <= 2 * n; ++kI) {
    for (int kJ = 1; kJ <= n; ++kJ) {
      printf("%d ", dp[kI][kJ]);
    }
    printf("\n");
  }
#endif
  int max = 0;
  for (int kI = 1; kI <= n; ++kI) {
    if (dp[kI][n] > max) max = dp[kI][n];
  }
  printf("%d\n", max);
  for (int kI = 1; kI <= n; ++kI) {
    if (dp[kI][n] == max) printf("%d ", kI);
  }
  return 0;
}