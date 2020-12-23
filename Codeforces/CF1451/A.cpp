// CodeForces/CF1451/A.cpp
// https://codeforces.com/contest/1451/problem/A
// Created by learntocode1024 on 11/21/20.
// AC

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int solve(unsigned n) {
  if (n == 1) return 0;
  if (n == 2) return 1;
  if (n == 3) return 2;
  if (~n & 1) return 2;
  return 3;
}

int main() {
  int T, n;
  cin >> T;
  while (T--) {
    cin >> n;
    cout << solve(n) << endl;
  }
  return 0;
}
