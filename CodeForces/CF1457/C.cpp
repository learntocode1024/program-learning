// CodeForces/CF1457/C.cpp
// https://codeforces.com/contest/1457/problem/C
// Created by learntocode1024 on 11/29/20.
//

#include <cstdio>
#include <iostream>
#include <string>
#include <memory.h>
using std::cin;
using std::cout;
using std::endl;

int min(int a, int b) {
  if (a < b) return a;
  return b;
}

std::string map;
int cnt[100005], x, y, n, p, k;

void solve() {
  memset(cnt, 0, 100005 * sizeof(int));
  cin >> n >> p >> k >> map >> x >> y;
  for (int i = n - 1; i >= 0; i--) {
    if (map[i] == '0') cnt[i]++;
    if (i + k < n) cnt[i] += cnt[i + k];
  }
  int ans = __INT_MAX__, curr;
  for (int i = 0; i <= n - p; ++i) {
    curr = i * y + cnt[i + p - 1] * x;
    ans = min(ans, curr);
  }
  cout << ans << endl;
}

int main() {
  cin.tie(NULL);
  std::ios::sync_with_stdio(false);
  int T = 1;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
