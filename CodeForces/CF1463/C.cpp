// CodeForces/CF1463/C.cpp
// Author: learntocode1024
// Date: 12-17-20
// URL: https://codeforces.com/contest/1463/problem/C
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
const int mod = 1e9 + 7;

void solve() {
  int n;
  cin >> n;
  int cnt = 0;
  int t, x;
  int t_prev = 0, x_prev = 0, curr = 0;
  while (n--) {
    cin >> t >> x;
    if (t_prev + (x_prev - curr) > t) { // ignore
      if (x <= x_prev && x >= )
    }
  }
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
