// luogu/Luogu3957.cpp
// https://www.luogu.com.cn/problem/P3957
// Created by learntocode1024 on 10/09/20.
// AC on Oct 10 2020
#include <iostream>
#include <deque>
#include <algorithm>
#define MX 500005
using std::cin;
using std::cout;
using std::max;
using std::fill;
// global
const int inf = 0x7fffffff;
int n, d, k;
int x[MX], val[MX];
std::deque<int> mono;
std::deque<int> next;

long long dp[MX];
// binary checking func
bool check(int curr) {
  // init
  mono.clear();
  next.clear();
  dp[0] = 0;
  fill(dp + 1, dp + n + 1, -inf);
  next.push_back(0);
  int  lim_l = max(1, d - curr), lim_r = d + curr;
  // status iteration
  for (int kI = 1; kI <= n; ++kI) {
    // monotonic queue
    while (!mono.empty() && x[mono.front()] + lim_r < x[kI])
      mono.pop_front();
    while (!next.empty() && x[next.front()] + lim_r < x[kI])
      next.pop_front();
    while (!next.empty() && x[next.front()] + lim_l <= x[kI]) {
      while (!mono.empty() && dp[next.front()] >= dp[mono.back()])
        mono.pop_back();
      mono.push_back(next.front());
      next.pop_front();
    }
    // status calc
    if (!mono.empty()) {
      dp[kI] = dp[mono.front()] + val[kI];
      next.push_back(kI);
    }
    if (dp[kI] >= k) return true;
  }
  return false;
}

int main() {
  // set iostream status
  std::ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> d >> k;
  int L = 0, R, mid;
  long long max_val = 0;
  for (int kI = 1; kI <= n; ++kI) {
    cin >> x[kI] >> val[kI];
    if (val[kI] > 0) max_val += val[kI];
  }
  R = x[n] + 1;
  // quick check
  if (max_val < k) {
    cout << -1;
    return 0;
  }
  // binary
  while (L < R) {
    mid = L + ((R - L) >> 1);
    if (check(mid)) R = mid;
    else L = mid + 1;
  }
  cout << L;
  return 0;
}