// luogu/Luogu4342.cpp
// https://www.luogu.com.cn/problem/P4342
// Created by learntocode1024 on 10/16/20.
// AC on 10/16/20
#include <iostream>
#define MX 51
using std::cin;
using std::cout;
const int inf = 0x3f3f3f3f;
int n;
bool op[MX << 1] = {false};
int dp_max[MX << 1][MX];
int dp_min[MX << 1][MX];

inline void to_max(int &a, const int &b) {
  if (a < b) a = b;
}
inline void to_min(int &a, const int &b) {
  if (a > b) a = b;
}

int main() {
  // input
  cin >> n;
  for (int kI = 1; kI <= (n << 1); ++kI) {
    for (int kJ = 1; kJ <= n; ++kJ) {
      dp_max[kI][kJ] = -inf;
      dp_min[kI][kJ] = inf;
    }
  }
  {
    int tmp_num;
    char tmp_op;
    for (int kI = 1; kI <= n; ++kI) {
      cin >> tmp_op >> tmp_num;
      dp_max[kI][1] = tmp_num;
      dp_max[kI + n][1] = tmp_num;
      dp_min[kI][1] = tmp_num;
      dp_min[kI + n][1] = tmp_num;
      if (tmp_op == 't') {
        op[kI] = true;
        op[kI + n] = true;
      }
    }
  }
  // dp_max
  for (int step = 2; step <= n; ++step) {
    for (int beg = 1; beg + step <= (n << 1); ++beg) {
      for (int kI = 1; kI < step; ++kI) {
        if (op[beg + kI]) {
          to_max(dp_max[beg][step], dp_max[beg][kI] + dp_max[beg + kI][step - kI]);
          to_min(dp_min[beg][step], dp_min[beg][kI] + dp_min[beg + kI][step - kI]);
        } else {
          to_max(dp_max[beg][step], dp_max[beg][kI] * dp_max[beg + kI][step - kI]);
          to_max(dp_max[beg][step], dp_min[beg][kI] * dp_min[beg + kI][step - kI]);
          to_max(dp_max[beg][step], dp_max[beg][kI] * dp_min[beg + kI][step - kI]);
          to_max(dp_max[beg][step], dp_min[beg][kI] * dp_max[beg + kI][step - kI]);
          to_min(dp_min[beg][step], dp_min[beg][kI] * dp_min[beg + kI][step - kI]);
          to_min(dp_min[beg][step], dp_max[beg][kI] * dp_max[beg + kI][step - kI]);
          to_min(dp_min[beg][step], dp_min[beg][kI] * dp_max[beg + kI][step - kI]);
          to_min(dp_min[beg][step], dp_max[beg][kI] * dp_min[beg + kI][step - kI]);
        }
      }
    }
  }
  int max = 0;
  for (int kI = 1; kI <= n; ++kI) {
    if (dp_max[kI][n] > max) max = dp_max[kI][n];
  }
  printf("%d\n", max);
  for (int kI = 1; kI <= n; ++kI) {
    if (dp_max[kI][n] == max) printf("%d ", kI);
  }
  return 0;
}