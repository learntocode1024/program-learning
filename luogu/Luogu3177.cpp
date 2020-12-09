// luogu/P3177.cpp
// https://www.luogu.com.cn/problem/P3177
// Created by learntocode1024 on 9/28/20.
// AC on Oct 2,2020

#include <cstdio>
#include <algorithm>
#include <cstring>
#define MX 2002
const int inf = 0x3fffffff;
using std::max;
using std::min;
using std::memset;

int head[MX];int t = 0;
int val[MX<<1];
int to[MX<<1];
int next[MX<<1];
int n, k;
int size[MX];
long long dp[MX][MX], temp[MX];

void dfs(const int &curr, const int & fa) {
  dp[curr][0] = dp[curr][1] = 0;
  size[curr] = 1;
  for (int iter = head[curr]; iter; iter = next[iter]) {
    if (to[iter] == fa) continue;
    dfs(to[iter], curr);
    // dp
    // learned from @czytysnow
    // use special method to avoid superfluous calculates.
    memset(temp, 0, sizeof(temp));
    for (int bk = size[curr]; bk >= 0; --bk) {
      for (int kI = 0; kI <= size[to[iter]]; ++kI) {
        if (bk + kI > k) continue;
        long long val_ = val[iter] * 1LL * ((k - kI)*kI + (n - k - size[to[iter]] + kI)*(size[to[iter]] - kI));
        temp[bk + kI] = max(temp[bk + kI], dp[curr][bk] + dp[to[iter]][kI] + val_);
      }
    }
    for(int j=0;j<=size[curr]+size[to[iter]];j++) dp[curr][j] = temp[j];
    size[curr] += size[to[iter]];
  }
}

int main() {
  scanf("%d%d", &n, &k);
  for (int kI = 1, a, b, c; kI < n; ++kI) {
    scanf("%d%d%d", &a, &b, &c);
    val[++t] = c;
    to[t] = b;
    next[t] = head[a];
    head[a] = t;
    val[++t] = c;
    to[t] = a;
    next[t] = head[b];
    head[b] = t;
  }
  std::fill(dp[0], dp[0] + MX * MX, -1);
  dfs(1, 0);
  printf("%lld", dp[1][k]);
  return 0;
}
