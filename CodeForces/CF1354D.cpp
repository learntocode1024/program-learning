// CodeForces/CF1354D.cpp
// https://codeforces.com/problemset/problem/1354/D
// Created by learntocode1024 on 12/01/20.
// AC

#include <cstdio>
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int a[1000005], n;

void add(int x) {
  while (x <= n) {
    ++a[x];
    x += x & -x;
  }
}
void del(int x) {
  while (x <= n) {
    --a[x];
    x += x & -x;
  }
}

int get(int x) {
  int ans = 0;
  while (x > 0) {
    ans += a[x];
    x -= x & -x;
  }
  return ans;
}

void query() {
  int k;
  cin >> k;
  if (k > 0) {
    add(k);
  } else {
    k = -k;
    int l = 1, r = n + 1, mid;
    while (l < r) {
      mid = l + (r - l >> 1);
      if (get(mid) >= k) r = mid;
      else l = mid + 1;
    }
    del(l);
  }
}

int main() {
  cin.tie(NULL);
  std::ios::sync_with_stdio(false);
  int T = 1;
  cin >> n >> T;
  for (int i = 0, tmp; i < n; ++i) {
    cin >> tmp;
    add(tmp);
  }
  while (T--) {
    query();
  }
  if (get(n) == 0) cout << '0' << endl;
  else {
    int i = 0;
    while (a[i] == 0) ++i;
    cout << i << endl;
  }
  return 0;
}
