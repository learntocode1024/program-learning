// CodeForces/CF1461/A.cpp
// Author: learntocode1024
// Date: 12-11-20
// URL: https://codeforces.com/contest/1461/problem/A
// tag:
// AC

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
  int n, k;
  cin >> n >> k;
  while (n--) {
    cout << "abc"[n % 3];
  }
  cout << endl;
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
