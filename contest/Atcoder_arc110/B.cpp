// contest/Atcoder_arc110/B.cpp
// https://atcoder.jp/contests/arc110/tasks
// Created by learntocode1024 on 12/05/20.
// AC

#include <cstdio>
#include <cstring>
#include <iostream>
#define MX
using std::cin;
using std::cout;
using std::endl;
char str[200005];
char pat[4] = "110";
long long ans = 1e10;

void solve() {
  int n;
  scanf("%d", &n);
  scanf("%s", str);
  int cnt = 0;
  int offset = 0;
  if (str[0] == '0') offset = 1, cnt = 1;
  if (str[0] == '1' && str[1] == '0') offset = 2, cnt = 1;
  bool flag = 0;
  for (int i = offset; i < n && !flag;) {
    ++cnt;
    for (int j = 0; j < 3 && i < n; ++j) {
      if(str[i] == pat[j]) ++i;
      else flag = true;
    }
  }
  if (n == 1 && str[0] == '1') {
    cout << ans * 2 << endl;
    return;
  }
  if (flag) {
    cout << 0 << endl;
    return;
  }
  cout << ans - cnt + 1 << endl;
}

int main() {
  cin.tie(NULL);
  std::ios::sync_with_stdio(false);
  int T = 1;
  // cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
