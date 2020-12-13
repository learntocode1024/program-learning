// CodeForces/CF1461/D.cpp
// Author: learntocode1024
// Date: 12-11-20
// URL: https://codeforces.com/contest/1461/problem/D
// tag: easy bruteforce
// AC

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <set>
#define MX 100005
using std::cin;
using std::cout;
using std::endl;
using std::memset;
typedef long long LL;
typedef unsigned long long ULL;

ULL a[MX];
std::set<ULL> mem;

int getmid(int l, int r) {
  if (l >= r) return -1;
  int mid, key = (a[l] + a[r - 1]) >> 1;
  while (r > l) {
    mid = l + (r - l) / 2;
    if (a[mid] <= key) l = mid + 1;
    else r = mid;
  }
  return l;
}

ULL calc(int l, int r) {
  ULL val;
  if (a[l] == a[r - 1]) {
    val = 1ull * a[l] * (r - l);
    mem.insert(val);
    return val;
  }
  int mid = getmid(l, r);
  val = calc(l, mid) + calc(mid, r);
  mem.insert(val);
  return val;
}

void solve() {
  mem = std::set<ULL>();
  memset(a, 0, sizeof(a));
  int n, q;
  cin >> n >> q;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  std::sort(a, a + n);
  calc(0, n);
  int t;
  while (q--) {
    cin >> t;
    if (mem.find(t) != mem.end()) {
      cout << "Yes\n";
    } else {
      cout << "No\n";
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
