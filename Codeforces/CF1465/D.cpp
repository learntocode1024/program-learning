// CodeForces/CF1465/D.cpp
// Author: learntocode1024
// Date: 12-20-20
// URL: https://codeforces.com/contest/1465/problem/D
// tag:
// 

#include <cstdio>
#include <string>
#include <algorithm>
#include <iostream>
#define MX 100005
using std::cin;
using std::cout;
using std::endl;
typedef long long LL;
typedef unsigned long long ULL;

std::string s;
LL nums[MX][2];
LL conv[2];
void solve() {
  cin >> s >> conv[1] >> conv[0];
  const int n = s.size();
  for (int i = 0; i < n; ++i) {
    nums[i][0] = nums[i][1] = __INT64_MAX__ / 2;
  }
  if (s[0] == '?') nums[0][0] = nums[0][1] = 0;
  else nums[0][s[0] - '0'] = 0;
  for (int i = 1; i < n; ++i) {
    if (s[i] == '?') {
      nums[i][0] = std::min(nums[i - 1][0], nums[i - 1][1] + conv[0]);
      nums[i][1] = std::min(nums[i - 1][1], nums[i - 1][0] + conv[1]);
    } else {
      int curr = s[i] - '0';
      nums[i][curr] = std::min(nums[i - 1][curr], nums[i - 1][curr ^ 1] + conv[curr]);
    }
  }
  cout << std::min(nums[n - 1][0], nums[n - 1][1]) << endl;
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
