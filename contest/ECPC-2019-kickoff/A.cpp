// contest/ECPC-2019-kickoff/A.cpp
// https://codeforces.com/gym/102881
// Created by learntocode1024 on 12/02/20.
// 

#include <cstdio>
#include <string>
#include <memory.h>
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
const unsigned full = (1 << 26) - 1;
std::string s;
unsigned vis[800][800];

int lowbit(int x) {
  return x & -x;
}

void solve() {
  int n;
  cin >> n >> s;
  for (int i = 0; i < n; ++i) {
    vis[i][1] = 1 << (25 - s[i] + 'A');
  }
  for (int len = 2; len <= n; ++len) {
    for (int i = 0; i + len <= n; ++i) {
      vis[i][len] = vis[i][len - 1];
      if (lowbit(vis[i + len - 1][1]) + 1 == lowbit(vis[i][len - 1])) vis[i][len] = vis[i][len - 1] | vis[i + len - 1][1];
      if (vis[i][len] == full) {
        cout << len << endl;
        return;
      }
    }
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
