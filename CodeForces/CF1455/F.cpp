// CodeForces/CF1455/F.cpp
// https://codeforces.com/contest/1455/problem/F
// Created by learntocode1024 on 11/30/20.
// 

#include <cstdio>
#include <string>
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
std::string str;

void solve() {
  int k, n;
  cin >> n >> k >> str;
  for (int i = 0; i < n; ++i) {
    if (str[i] - 'a' ==  0) continue;
    if (str[i] - 'a' == k - 1) str[i] = 'a';
    else if (str[i] - 'a')
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
