// CodeForces/CF1463/F.cpp
// Author: learntocode1024
// Date: 12-17-20
// URL: https://codeforces.com/contest/1463/problem/F
// tag:
// 

#include <cstdio>
#include <iostream>
#define MX 300005
using std::cin;
using std::cout;
using std::endl;
typedef long long LL;
typedef unsigned long long ULL;

int prev[MX];
int belong[MX];
int cond[MX];

int get(int x) {
  if (belong[x] == x) return x;
  belong[x] = get(belong[x]);
  return belong[x];
}

void solve() {
  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) {
    cin >> prev[i];
    belong[i] = (prev[i] == 0)? i: prev[i];
  }
  for (int i = 0, a, b; i < k; ++i) {
    cin >> a >> b;
    if (cond[b] || cond[a] == b) {
      cout << "0" << endl;
      return;
    }
    cond[b] = a;
  } // input
  for (int i = 1; i <= n; ++i) {
    if (cond[i]) {
      if (get(i) == get(cond[i]) && prev[i] != cond[i]) {
        cout << "0" << endl;
        return;
      }
    }
  } // check
  return;
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
