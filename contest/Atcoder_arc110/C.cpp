// contest/Atcoder_arc110/C.cpp
// https://atcoder.jp/contests/arc110/tasks
// Created by learntocode1024 on 12/05/20.
// AC

#include <cstdio>
#include <iostream>
#define MX
using std::cin;
using std::cout;
using std::endl;

int pos[200005], tot;

int abs(int x) {
  if (x < 0) return -x;
  return x;
}

void solve() {
  int n;
  cin >> n;
  int cnt = 0;
  for (int i = 1, curr; i <= n; ++i) {
    cin >> curr;
    if (curr == i) cnt += n;
    if (curr < i) cnt += i - curr, pos[++tot] = i;
  }
  if (cnt != n - 1) {
    cout << -1 << endl;
    return;
  }
  pos[0] = 1;
  for (int i = 0; i < tot; ++i) {
    for (int j = pos[i + 1] - 1; j >= pos[i];j--) cout << j << "\n";
  }
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
