// CodeForces/CF1451/B.cpp
// https://codeforces.com/contest/1451/problem/B
// Created by learntocode1024 on 11/21/20.
//

#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

void solve() {
  int T, tmp, l, r;
  string str;
  cin >> tmp >> T >> str;
  while (T--) {
    cin >> l >> r;
    bool flag = false, ans = false;
    string::iterator curr = str.begin() + l - 1;
    for (string::iterator it = str.begin(); !ans && it != str.end();) {
      if (curr == str.begin() + r) {
        ans = true;
        break;
      }
      if (*curr == *it) {
        ++it, ++curr;
        if (flag) flag = false, ++it;
        else flag = true;
      } else ++it, flag = false;
    }
    if (curr == str.begin() + r) {
      ans = true;
    }
    if (ans) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
}

int main() {
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
