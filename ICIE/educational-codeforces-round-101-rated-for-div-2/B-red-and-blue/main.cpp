// $FILEDIR
// Author: $USERNAME
// Date: $DATE
// URL: $PROBLEMURL
// tag:
// AC

#include <cstdio>
#include <queue>
#include <algorithm>
#include <cstring>
#include <iostream>
#define MX
using std::cin;
using std::cout;
using std::endl;
using std::memset;
typedef long long LL;
typedef unsigned long long ULL;
const int mod = 1e9 + 7;
int a[105], b[105];
void solve() {
  int n, m;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  cin >> m;
  for (int i = 0; i < m; ++i) {
    cin >> b[i];
  }
  int ans = 0;
  int curr = 0;
  for (int i = 0; i < n; ++i) {
    curr += a[i];
    ans = std::max(ans, curr);
  }
  curr = 0;
  int ans2 = 0;
  for (int i = 0; i < m; ++i) {
    curr += b[i];
    ans2 = std::max(ans2, curr);
  }
  ans = std::max(ans, std::max(ans2, ans + ans2));
  cout << ans << endl;
  for (int i = 0; i < n; ++i) {
    a[i] = 0;
  }
  for (int i = 0; i < m; ++i) {
  }
    b[i] = 0;
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
