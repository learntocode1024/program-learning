// CodeForces/CF1462/D.cpp
// Author: learntocode1024
// Date: 12-15-20
// URL: https://codeforces.com/contest/1462/problem/D
// tag:
// 

#include <cstdio>
#include <set>
#include <iostream>
#define MX
using std::cin;
using std::cout;
using std::endl;

int a[3005];
std::set<int> mp;

void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  mp = std::set<int>();
  mp.insert(a[0]);
  for (int i = 1; i < n; ++i) {
    a[i] += a[i - 1];
    mp.insert(a[i]);
  }
  int ans = 1;
  for (int i = n; i > 0; i--) {
    if (a[n - 1] % i) continue;
    bool can = true;
    for (int j = a[n - 1] / i; j < a[n - 1]; j += a[n - 1] / i) {
      if (mp.find(j) == mp.end()) {
        can = false;
        break;
      }
    }

    if (can) {
      ans = i;
      break;
    }
  }
  cout << n - ans << endl;
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
