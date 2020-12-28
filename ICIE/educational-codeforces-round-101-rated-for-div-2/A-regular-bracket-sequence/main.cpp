// $FILEDIR
// Author: $USERNAME
// Date: $DATE
// URL: $PROBLEMURL
// tag:
//

#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
#define MX
using std::cin;
using std::cout;
using std::endl;
std::string str;
int a[105], b[105];

void solve() {
  cin >> str;
  bool ans = true;
  if (str[0] == ')')
    ans = false;
  else a[0] = 1;
  for (int i = 1; ans && i < str.size(); ++i) {
    if (str[i] == '(' || str[i] == '?')
      a[i] = a[i - 1] + 1;
    else
      a[i] = a[i - 1] - 1;
    if (str[i] == '?')
      b[i] = 1;
    if (a[i] < 0) ans = false;
  }
  if (a[str.size() - 1] < 0)
    ans = false;
  for (int i = str.size() - 2; i >= 0; --i) {
    a[i] = std::min(a[i + 1], a[i]);
  }
  int aval = 0;
  for (int i = 0; i < str.size(); ++i) {
    if (b[i] && a[i] > aval) aval += 2; 
  }
  if (a[str.size() - 1] == 0 && aval % 4 == 0 ||
      a[str.size() - 1] % 2 == 0 && a[str.size() - 1] <= aval)
    ans = true;
  if (ans)
    cout << "YES\n";
  else
    cout << "NO\n";
  for (int i = 0; i < str.size(); ++i) {
    b[i] = a[i] = 0;
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
