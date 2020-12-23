// CodeForces/CF1463/B.cpp
// Author: learntocode1024
// Date: 12-17-20
// URL: https://codeforces.com/contest/1463/problem/B
// tag: easy
// AC

#include <cstdio>
#include <iostream>
#define MX
using std::cin;
using std::cout;
using std::endl;

void solve() {
  int n;
  cin >> n;
  int prev = 1, curr;
  while (n--) {
    cin >> curr;
    if (curr % prev && prev % curr) {
      if (curr > prev) {
        curr = curr / prev * prev;
      } else {
        curr = 1;
      }
    }
    cout << curr << " ";
    prev = curr;
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
