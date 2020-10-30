// luogu/Luogu1502.cpp
// https://www.luogu.com.cn/problem/P1502
// Created by learntocode1024 on 10/30/20.
// 

#include <cstdio>
#define MX_8 80005
int val[MX_8], tag[MX_8];

inline int max(const int &a, const int &b) {
  if (a > b) return a;
  return b;
}

inline int min(const int &a, const int &b) {
  if (a < b) return a;
  return b;
}

void push_down(unsigned curr) {
  if (tag[curr] == 0) return;
  unsigned left = (curr << 1) + 1, right = left + 1;
  val[left] += tag[curr];
  val[right] += tag[curr];
  tag[left] += tag[curr];
  tag[right] += tag[curr];
}

void modify(int num, unsigned curr,
            int beg, int end, int l, int r) {
  if (beg == l && end == r) {
    val[curr] += num;
    tag[curr] += num;
  }
  push_down(curr);
  unsigned left = (curr << 1) + 1, right = left + 1;
  int mid = l + (r - l)/2;
  if (beg < mid) modify(num, left, beg, min(mid, end), l, mid);
  if (end > mid) modify(num, right, max(beg, mid), end, mid, r);
  val[curr] = max(val[left], val[right]);
}

int query(unsigned curr,
          int beg, int end, int l, int r) {
  if (beg == l && end == r) {
    return val[curr];
  }
  push_down(curr);
  unsigned left = (curr << 1) + 1, right = left + 1;
  int mid = l + (r - l)/2;
  int ans = 0;
  if (beg < mid) ans = query(left, beg, min(mid, end), l, mid);
  if (end > mid) ans = max(ans, query(right, max(beg, mid), end, mid, r));
  return ans;
}

void build(unsigned curr, int* ptr, int l, int r) {
  if (r - l == 1) {
    val[curr] = ptr[l];
  }
  unsigned left = (curr << 1) + 1, right = left + 1;
  int mid = l + (r - l)/2;
  build(left, ptr, l, mid);
  build(right, ptr, mid, r);
  val[curr] = max(val[left], val[right]);
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    
  }
  return 0;
}
