// CodeForces/CF1439C.cpp
// https://codeforces.com/problemset/problem/1439/C
// Created by learntocode1024 on 12/03/20.
// 

#include <cstdio>
#include <algorithm>
#include <iostream>
#define MX 200005
typedef long long LL;
using std::cin;
using std::cout;
using std::endl;
using std::max;
using std::min;

int n, a[MX];
LL sum[MX << 2];
int tag[MX << 2], minv[MX << 2], maxv[MX << 2];

void push_down(unsigned curr, int l, int r) {
  if (tag[curr] <= minv[curr]) return;
  unsigned left = (curr << 1) + 1, right = left + 1;
  int mid = (r - l)/2 + 1;
  sum[left] = tag[curr] * (mid - l);
  sum[right] = tag[curr] * (r - mid);
  maxv[left] = minv[left] = tag[curr];
  maxv[right] = minv[right] = tag[curr];
  tag[curr] = 0;
}

void assign(unsigned curr,
            int l, int r,
            int beg, int end, int val) {
  
}

int query(unsigned curr,
          int l, int r,
          int beg, int val);

void build(unsigned curr,
           int l, int r,
           int* const beg, int* const end);

void solve() {
  
}

int main() {
  cin.tie(NULL);
  std::ios::sync_with_stdio(false);
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  int T = 1;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
