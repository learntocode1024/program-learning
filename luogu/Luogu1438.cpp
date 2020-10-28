// luogu/Luogu1438.cpp
// https://www.luogu.com.cn/problem/P1438
// Created by learntocode1024 on 10/28/20.
// AC on 10/28/20

#include <cstdio>
#include <algorithm>
#define MXx4 400005
#define MX 100005
using std::max;
using std::min;

int sum[MXx4]{}, tag[MXx4]{};

void push_down(const unsigned curr, const int l, const int r) {
  if (tag[curr] == 0 || r - l == 1) {
    return;
  }
  unsigned left = (curr << 1) + 1, right = left + 1;
  int mid = l + (r - l)/2;
  sum[left] += tag[curr] * (mid - l);
  sum[right] += tag[curr] * (r - mid);
  tag[left] += tag[curr], tag[right] += tag[curr]; // MIND THIS!!!
  tag[curr] = 0;
}

void add(const int val, const unsigned curr,
         const int beg, const int end,
         const int l, const int r) {
  if (beg == l && end == r) {
    sum[curr] += val * (r - l);
    tag[curr] += val;
    return;
  }
  push_down(curr, l, r);
  unsigned left = (curr << 1) + 1, right = left + 1;
  int mid = l + (r - l)/2;
  if (beg < mid) add(val, left, beg, min(end, mid), l, mid);
  if (end > mid) add(val, right, max(beg, mid), end, mid, r);
  sum[curr] = sum[left] + sum[right];
}

int query(const unsigned curr,
         const int beg, const int end,
         const int l, const int r) {
  if (beg == l && end == r) {
    return sum[curr];
  }
  push_down(curr, l, r);
  unsigned left = (curr << 1) + 1, right = left + 1;
  int mid = l + (r - l)/2;
  int ans = 0;
  if (beg < mid) ans += query(left, beg, min(end, mid), l, mid);
  if (end > mid) ans += query(right, max(beg, mid), end, mid, r);
  return ans;
}

void build(const unsigned curr, int* const ptr,
           const int l, const int r) {
  if (r - l == 1) {
    sum[curr] = ptr[l];
    return;
  }
  unsigned left = (curr << 1) + 1, right = left + 1;
  int mid = l + (r - l)/2;
  build(left, ptr, l, mid);
  build(right, ptr, mid, r);
  sum[curr] = sum[left] + sum[right];
}

int n, m, tmp[MX];

void insert() {
  int l, r, k, d;
  scanf("%d%d%d%d", &l, &r, &k, &d);
  add(k, 0, l - 1, l, 0, n);
  if (r > l) add(d, 0, l, r, 0, n);
  if (r < n) add(-k - (r - l)*d, 0, r, r + 1, 0, n);
}

int main() {
  scanf("%d%d", &n, &m);
  for (int kI = 0; kI < n; ++kI) scanf("%d", tmp + kI);
  // build(0, tmp, 0, n);
  int op, p;
  while (m--) {
    scanf("%d", &op);
    if (op == 1) insert();
    else scanf("%d", &p), printf("%d\n", query(0, 0, p, 0, n) + tmp[p - 1]);
  }
  return 0;
}
