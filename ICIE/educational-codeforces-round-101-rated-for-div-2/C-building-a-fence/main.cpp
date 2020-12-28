// $FILEDIR
// Author: $USERNAME
// Date: $DATE
// URL: $PROBLEMURL
// tag:
// AC

#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#define MX 200005
using std::cin;
using std::cout;
using std::endl;
using std::memset;
typedef long long LL;
typedef unsigned long long ULL;
const int mod = 1e9 + 7;
LL h[MX];
void solve() {
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; ++i) {
    cin >> h[i];
  }
  LL l, r;
  bool ans = true;
  l = r = h[0];
  for (int i = 1;ans && i < n; ++i) {
    l += k - 1;
    r -= k - 1;
    if (r > h[i] + k - 1 || h[i] > l) ans = false;
    l = std::min(l, h[i] + k - 1);
    r = std::max(r, h[i]);
  }
  if (ans && h[n - 1] > l || h[n - 1] < r) ans = false;
  if (ans) cout << "YES\n";
  else cout << "NO\n";
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
