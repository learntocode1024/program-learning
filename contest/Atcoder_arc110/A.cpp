// contest/Atcoder_arc110/A.cpp
// https://atcoder.jp/contests/arc110/tasks
// Created by learntocode1024 on 12/05/20.
// AC

#include <cstdio>
#include <iostream>
#define MX
using std::cin;
using std::cout;
using std::endl;
int prime[30] = {2,3,5,7,11,13,17,19,23,29};
void solve() {
  int n;
  cin >> n;
  long long ans = 1;
  for (int it = 0; it < 10;++it) {
    int p = prime[it];
    while (p <= n) p *= prime[it];
    ans *= p / prime[it];
  }
  cout << ans + 1 << endl;
}

int main() {
  cin.tie(NULL);
  std::ios::sync_with_stdio(false);
  int T = 1;
  // cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
