// CodeForces/CF1454/A.cpp
// https://codeforces.com/contest/1454/problem/A
// Created by learntocode1024 on 11/24/20.
// AC

#include <cstdio>
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main() {
  int T, n, k;
  cin >> T;
  while (T--) {
    cin >> n;
    cout << n;
    k = 0;
    while (++k < n) cout << ' ' << k;
    cout << "\n";
  }
  cout << endl;
  return 0;
}
