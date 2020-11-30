// CodeForces/CF1455/A.cpp
// https://codeforces.com/contest/1455/problem/A
// Created by learntocode1024 on 11/30/20.
// AC

#include <cstdio>
#include <string>
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
std::string S;

void solve() {
  cin >> S;
  cout << S.length() << endl;
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
