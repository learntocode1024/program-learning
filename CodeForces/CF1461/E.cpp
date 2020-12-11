// CodeForces/CF1461/E.cpp
// Author: learntocode1024
// Date: 12-11-20
// URL: https://codeforces.com/contest/1461/problem/E
// tag:
// 

#include <cstdio>
#include <cstring>
#include <iostream>
#define MX
using std::cin;
using std::cout;
using std::endl;
using std::memset;
typedef long long LL;
typedef unsigned long long ULL;

void solve() {
  ULL l, r, t, k, x, y;
  cin >> k >> l >> r >> t >> x >> y;
  if (x == y) {
    cout << "YES" << endl;
    return;
  }
  if (x > y) {
    if (k + y > r) k -= x, t--;
    if (k < l) {
      cout << "NO" << endl;
      return;
    }
    if ((k - l) / (x - y) < t) {
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
    }
    return;
  }
  if (x < y) {
    ULL delta = y - x;
    ULL vr = r - y;
    if (vr < l && (k - l) / x < t) {
      cout << "NO" << endl;
      return;
    }
    
    return;
  }
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
