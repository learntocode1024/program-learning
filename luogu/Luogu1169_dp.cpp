// luogu/P1169_dp.cpp
// https://www.luogu.com.cn/problem/P1169
// Created by learntocode1024 on Sep 18 2020.
// AC on Sep 20 2020
// Mind that this dynamic programming algorithm has bugs!!!
// It cannot pass data below
/*************ERROR DATA****************
5 5
1 1 1 1 0
1 0 1 0 1
1 0 1 1 0
1 0 0 1 0
0 1 0 1 0
----------------------
10 10
1 0 1 1 0 1 1 0 1 0
1 0 1 0 1 0 1 0 1 0
1 0 0 1 0 1 0 1 0 1
0 1 0 1 0 1 0 1 0 1
0 1 0 1 0 0 1 0 1 1
0 1 1 0 1 0 1 0 1 0
1 0 1 0 1 1 0 0 1 0
1 0 0 1 0 1 1 0 1 0
0 1 0 1 0 1 0 1 0 1
0 1 0 1 0 1 0 1 0 1
----------------------
20 20
1 0 1 0 1 0 1 0 1 1 0 1 0 0 1 0 1 0 1 0
1 0 1 0 1 0 1 1 1 0 1 0 1 0 1 0 1 0 1 0
1 0 1 1 0 1 1 0 1 0 1 0 1 0 1 1 0 1 0 1
0 1 1 0 0 1 0 1 0 0 1 1 0 1 0 0 1 0 1 0
1 0 1 0 1 0 1 0 0 1 0 0 0 1 1 1 0 0 1 0
1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0
1 0 1 0 1 0 1 1 0 1 0 0 1 0 1 0 1 0 0 1
0 1 0 0 1 0 1 0 1 1 0 1 0 0 1 0 1 0 1 1
0 1 0 1 0 1 0 1 0 1 1 0 1 0 1 1 1 0 0 1
0 1 0 1 0 1 0 0 1 0 1 0 1 0 1 0 0 1 0 1
0 1 0 1 0 1 0 1 0 1 0 1 0 1 1 1 0 0 1 1
1 0 1 0 1 1 0 1 0 1 0 1 0 1 0 1 0 0 1 1
0 1 0 1 0 1 0 1 0 1 0 1 0 0 1 0 1 0 1 0
1 0 1 1 0 1 0 1 1 0 1 0 1 0 1 1 0 1 1 0
1 1 0 1 0 0 0 1 0 1 0 1 0 1 0 1 0 1 0 1
0 1 1 0 1 0 1 0 1 0 0 1 0 1 0 0 0 1 1 0
1 0 1 0 1 0 0 1 0 1 0 1 0 1 0 1 1 1 0 1
0 1 1 0 0 1 0 0 1 0 1 0 1 0 1 0 1 0 1 0
1 0 1 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1
0 0 0 0 1 0 1 0 1 0 1 0 1 0 1 0 0 1 0 1
 **************************************/
#include <cstdio>
#define MX 2005
// #define MX 3

struct pt {
  int x = 1;
  int y = 1;
  int sqr() {
    if (x < y) return x * x;
    return y * y;
  }
  int area() {
    return x * y;
  }
};

int max(int a, int b) {
  if (a > b) return a;
  return b;
}

int min(int a, int b) {
  if (a < b) return a;
  return b;
}

bool map[MX][MX];
pt dp[MX][MX]; // n * m
int ans1, ans2, m, n;

void update(int x, int y) {
  printf("%d*%d ", dp[x][y].x ,dp[x][y].y);
  ans1 = max(ans1, dp[x][y].sqr());
  ans2 = max(ans2, dp[x][y].area());
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      scanf("%d", map[i] + j);
      // get x
      bool check_x = i && (map[i - 1][j] ^ map[i][j]);
      bool check_y = j && (map[i][j - 1] ^ map[i][j]);
      if (check_x) {
        if (check_y) {
          if (map[i - 1][j - 1] ^ map[i][j]) {
            if (dp[i][j - 1].y < dp[i - 1][j].x)
              dp[i][j].x = dp[i - 1][j].x + 1;
            else dp[i][j].y = dp[i][j - 1].y + 1;
          } else {
            dp[i][j].x = dp[i - 1][j].x + 1;
            dp[i][j].y = dp[i][j - 1].y + 1;
            if (dp[i - 1][j].x + 1 > dp[i][j - 1].x && \
                dp[i - 1][j].y < dp[i][j - 1].y + 1) {
              dp[i][j].x = dp[i][j - 1].x;
              dp[i][j].y = dp[i - 1][j].y;
              ans1 = max(ans1, dp[i][j].sqr());
              if (dp[i][j].area() < (dp[i - 1][j].x + 1) * dp[i - 1][j].y) {
                dp[i][j].x = dp[i - 1][j].x + 1;
                ans1 = max(ans1, dp[i][j].sqr());
              }
              if (dp[i][j].area() < dp[i][j - 1].x * (dp[i][j - 1].y + 1)) {
                dp[i][j].x = dp[i][j - 1].x;
                dp[i][j].y = dp[i][j - 1].y + 1;
              }
            }
          }
        } else dp[i][j].x = dp[i - 1][j].x + 1;
      } else if (check_y) dp[i][j].y = dp[i][j - 1].y + 1;
      update(i, j);
    }
    printf("\n");
  }
  printf("%d\n%d", ans1, ans2);
  return 0;
}