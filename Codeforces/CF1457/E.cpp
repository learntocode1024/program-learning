// CodeForces/CF1457/E.cpp
// https://codeforces.com/contest/1457/problem/E
// Created by learntocode1024 on 11/29/20.
// tag: review
// AC

#include <cstdio>
#include <queue>
#include <iostream>
#include <algorithm>
using std::cin;
using std::cout;
using std::endl;

long long c[500005], n, k;

bool cmp(long long a, long long b) {
  return a > b;
}

std::priority_queue<long long> Q;
void solve() {
  cin >> n >> k;
  for (long long kI = 0; kI < n; ++kI) {
    cin >> c[kI];
  }
  std::sort(c, c + n, cmp);
  long long bonus = 0, ans = 0, it = 0;
  while (it < n && bonus >= 0) {
    ans += bonus;
    bonus += c[it++];
  }
  if (bonus >= 0) {
    cout << ans << endl;
    return;
  }
  std::sort(c + it, c + n);
  for (long long i = 0; i <= k; ++i) {
    Q.push(0);
  }
  while(it < n) {
    long long x = -Q.top(); Q.pop();
    ans += x * c[it++];
    Q.push(-x - 1);
  }
  cout << ans - bonus * Q.top() << endl;
}

int main() {
  cin.tie(NULL);
  std::ios::sync_with_stdio(false);
  solve();
  return 0;
}
