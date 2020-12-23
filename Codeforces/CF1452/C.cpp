// CodeForces/CF1452/C.cpp
// https://codeforces.com/contest/1452/problem/C
// Created by learntocode1024 on 11/19/20.
// AC

#include <iostream>
#include <string>
using namespace std;

string s;
int t1, t2;

int solve() {
  int ans = 0;
  t1 = 0;
  t2 = 0;
  for (string::iterator it = s.begin(); it != s.end(); ++it) {
    if (*it == '(') t1++;
    if (*it == '[') t2++;
    if (t1 && *it == ')') t1--, ans++;
    if (t2 && *it == ']') t2--, ans++;
  }
  return ans;
}

int main() {
  int T;
  cin >> T;
  while (T--) {
    cin >> s;
    cout << solve() << endl;
  }
}
