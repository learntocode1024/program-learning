// CodeForces/CF1452/A.cpp
// https://codeforces.com/contest/1452/problem/A
// Created by learntocode1024 on 11/19/20.
// AC

#include <cstdio>
#include <iostream>
using namespace std;

int solve(int x, int y) {
  int ans = y * 2;
  x -= y;
  if (x) ans += 2 * x - 1;
  return ans;
}

int main() {
  int T, x, y;
  cin >> T;
  while (T--) {
    cin >> x >> y;
    if (x < y) {
      x = x + y;
      y = x - y;
      x = x - y;
    }
    cout << solve(x, y) << endl;
  }
  return 0;
}
