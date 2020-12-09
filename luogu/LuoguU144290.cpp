// luogu/LuoguU144290.cpp
// https://www.luogu.com.cn/problem/U144290
// Created by learntocode1024 on 12/04/20.
// 

#include <cstdio>
#include <string>
#include <iostream>
#define MX
using std::cin;
using std::cout;
using std::endl;
using std::string;
string str;

void solve() {
  cin >> str;
  str += str;
  int ans = 0, cnt = 0;
  for (int i = 0; i < str.size(); ++i) {
    if (str[i] == 'K') ans += i - cnt, cnt++;
  }
  int pref = 0;
  for (int i = 1; i < str.size(); ++i) {
    
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
