// CodeForces/CF1457/E.cpp
// https://codeforces.com/contest/1457/problem/E
// Created by learntocode1024 on 11/29/20.
// 

#include <cstdio>
#include <iostream>
#include <algorithm>
using std::cin;
using std::cout;
using std::endl;

int c[500005], n, k;

bool cmp(int a, int b) {
  return a > b;
}

void solve() {
  cin >> n >> k;
  for (int kI = 0; kI < n; ++kI) {
    cin >> c[kI];
  }
  std::sort(c, c + n, cmp);
  int bonus = 0, ans = 0, it = 0;
  while (it < n && bonus >= 0) {
    ans += bonus;
    bonus += c[it++];
  }
  if (bonus >= 0) {
    cout << ans << endl;
    return;
  }
  // c[--it] = bonus;
  // int res = n - it - 1;
  // for (int i = res % k; i > 0; i--) {
  //   ans += c[it++] * (res / k);
  // }
  // for (int i = res / k; i > 0; i--) {
  //   for (int kI = 0; kI < k; ++kI) {
  //     ans += c[it++] * (i - 1);
  //   }
  // }
  cout << ans << endl;
}

int main() {
  cin.tie(NULL);
  std::ios::sync_with_stdio(false);
  solve();
  return 0;
}
