// program-learning
// Author: misaka18931
// Date: Feb  2, 2021
// tag: dp, NOIP2008

#include <cstdio>
#include <iostream>
using namespace std;
#define min(X, Y) ((X) < (Y) ? (X) : (Y))
#define max(X, Y) ((X) > (Y) ? (X) : (Y))
#define to_max(X, Y) X = max(X, Y);
#define MX 55

int m, n;
int num[MX][MX];
int dp[2*MX][MX][MX];

void solve() {
  cin >> m >> n;
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> num[i][j];
    }
  }
  for (int step = 1; step < m + n - 1; ++step) {
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < m; ++j) {
        if (i) to_max(dp[step][i][j], dp[step - 1][i - 1][j])
        if (j) to_max(dp[step][i][j], dp[step - 1][i][j - 1])
        if (i & j) to_max(dp[step][i][j], dp[step - 1][i - 1][j - 1])
        to_max(dp[step][i][j], dp[step - 1][i][j])
        dp[step][i][j] += num[i][step - i] + num[j][step - j];
      }
    }
  }
  cout << dp[n + m - 2][m - 1][m - 1] << endl;
}

int main() {
  solve();
  return 0;
}
