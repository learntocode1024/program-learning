// luogu/Luogu3797.cpp
// https://www.luogu.com.cn/problem/P3797
// Created by learntocode1024 on 10/29/20.
// 

#include <cstdio>
#include <cstring>
#define MX 200005
#define MX_4 800020

inline int min(int a, int b) {
  return (a > b)? a : b;
}

inline int max(int a, int b) {
  return (a < b)? a : b;
}

short str[MX]; // 0 for begin, 1 for end, 2 for middle part
int val[MX_4];
bool lt[MX_4]{0}, rt[MX_4]{0};

void modify(unsigned curr, int pos, int l, int r) {
  if (r - l == 1) {
    lt[curr] = false, rt[curr] = false;
    if (str[pos] == 0) rt[curr] = true;
    if (str[pos] == 1) lt[curr] = true;
    return;
  }
  unsigned left = (curr << 1) + 1, right = left + 1;
  int mid = l + (r - l)/2;
  if (pos < mid) modify(left, pos, l, mid);
  else modify(right, pos, mid, r);
  val[curr] = val[left] + val[right] + (rt[left] && lt[right]);
  lt[curr] = lt[left];
  rt[curr] = rt[right];
}

int query(unsigned curr, int beg, int end, int l, int r) {
  if (beg == l && end == r) {
    return val[curr];
  }
  unsigned left = (curr << 1) + 1, right = left + 1;
  int mid = l + (r - l)/2;
  int ans = 0;
  if (beg < mid) ans += query(left, beg, min(mid, end), l, mid);
  if (end > mid) ans += query(right, max(mid, beg), end, mid, r);
  return ans;
}

void build(unsigned curr, int l, int r) {
  if (r - l == 1) {
    if (str[l] == 0) rt[curr] = true;
    if (str[l] == 1) lt[curr] = true;
    return;
  }
  unsigned left = (curr << 1) + 1, right = left + 1;
  int mid = l + (r - l)/2;
  build(left, l, mid);
  build(right, mid, r);
  val[curr] = val[left] + val[right] + (rt[left] && lt[right]);
  lt[curr] = lt[left];
  rt[curr] = rt[right];
}
int n, m;

int main() {
  scanf("%d%d", &n, &m);
  std::memset(str, 2, sizeof(str));
  str[0] = 0;
  str[n - 1] = 1;
  build(0, 0, n);
  int op, l, r;
  while (m--) {
    
  }
  return 0;
}
