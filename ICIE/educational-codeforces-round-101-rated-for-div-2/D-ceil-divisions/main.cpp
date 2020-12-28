// Author: $USERNAME
// $FILEDIR
// Date: $DATE
// URL: $PROBLEMURL
// tag:
// AC

#include <cstdio>
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

void solve() {
  int n;
  cin >> n;
  int k = 0;
  if (n < 32) k = 1;
  else if (n < 1024) k = 2;
  else if (n < 32768) k = 3;
  else if (n < 1048576) k = 4;
  else k = 5;
  int cnt = 0;
  for (int i = 3; i < n; ++i) {
    bool ind = false;
    for (int j = 0, l = 1; j < k; ++j) {
      l <<= 1;
      if (i == l) {
        ind = true;
        break;
      }
    }
    if (ind)
      continue;
    ++cnt;
  }
  for (int i = n; i > 1;) {
    ++cnt;
    if (i % (1 << k))
      i = i / (1 << k) + 1;
    else
      i /= (1 << k);
  }
  if (k == 2)
    cnt += 2;
  if (k == 3)
    cnt += 4;
  if (k == 4)
    cnt += 5;
  cout << cnt << endl;
  for (int i = 3; i < n; ++i) {
    bool ind = false;
    for (int j = 0, l = 1; j < k; ++j) {
      l <<= 1;
      if (i == l) {
        ind = true;
        break;
      }
    }
    if (ind) continue;
    cout << i << " " << n << "\n";
  }
  for (int i = n; i > 1;) {
    cout << n << " " << (1 << k) << "\n";
    if (i % (1 << k))
      i = i / (1 << k) + 1;
    else
      i /= (1 << k);
  }
  if (k == 2) cout << "4 2\n4 2" << endl;
  if (k == 3)
    cout << "4 8\n8 2\n8 2\n8 2" << endl;
  if (k == 4)
    cout << "8 16\n16 4\n16 4\n4 2\n4 2" << endl;
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
