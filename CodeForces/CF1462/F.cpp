// CodeForces/CF1462/F.cpp
// Author: learntocode1024
// Date: 12-16-20
// URL: https://codeforces.com/contest/1462/problem/F
// tag: index, binary_search
// AC

#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define MX 200005
using std::cin;
using std::cout;
using std::endl;
std::vector<int> lt, rt;
std::pair<int, int> seg[MX];

void solve() {
  int n;
  lt = std::vector<int>();
  rt = std::vector<int>();
  cin >> n;
  for (int i = 0, l, r; i < n; ++i) {
    cin >> l >> r;
    seg[i] = std::make_pair(l, r);
    lt.push_back(l);
    rt.push_back(r);
  }
  std::sort(lt.begin(), lt.end());
  std::sort(rt.begin(), rt.end());
  int ans = n + 1;
  for (int i = 0; i < n; ++i) {
    int curr = std::lower_bound(rt.begin(), rt.end(), seg[i].first) - rt.begin();
    curr += lt.end() - std::upper_bound(lt.begin(), lt.end(), seg[i].second);
    ans = std::min(ans, curr);
  }
  cout << ans << endl;
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
