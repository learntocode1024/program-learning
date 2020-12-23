// CodeForces/CF1452/F.cpp
// https://codeforces.com/contest/1452/problem/F
// Created by learntocode1024 on 11/19/20.
// 

#include <iostream>
#include <cstdio>
using std::cin;
using std::cout;
using std::endl;
typedef long long LL;

int n;
int cnt[35];

LL query(int x, LL k) {
  for (int kI = 0; kI <= x; ++kI) k -= cnt[kI];
  LL ans = 0;
  for (int kI = 1; kI <= n - x; ++kI) {
    if (k > (cnt[kI + x] << kI)) {
      k -= (cnt[kI + x] << kI);
      ans += (cnt[kI + x] << kI - 1);
    } else {
      ans += ((k + 1 >> 1) << kI - 1);
      k = 0;
      break;
    }
  }
  if (k) return -1;
  return ans;
}

int main() {
  int Q;
  cin >> n >> Q;
  for (int kI = 0; kI < n; ++kI) cin >> cnt[kI];
  LL op, x, k;
  while (Q--) {
    cin >> op >> x >> k;
    if (op == 1) cnt[x] = k;
    else cout << query(x, k) << endl;
  }
  return 0;
}
