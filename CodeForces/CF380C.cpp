// CodeForces/CF380C.cpp
// https://codeforces.com/problemset/problem/380/C
// Created by learntocode1024 on 11/02/20.
// AC on 11/2/20

#include <cstdio>
#include <cstring>
#define MX 1000005
#define MX_4 4000005

inline int min(const int &a, const int &b) {
  if (a < b) return a;
  return b;
}

inline int max(const int &a, const int &b) {
  if (a > b) return a;
  return b;
}

char str[MX];
int lt[MX_4], rt[MX_4], sum[MX_4];

void build(unsigned curr, int l, int r) {
  if (r - l == 1) {
    if (str[l] == '(') lt[curr] = 1;
    else rt[curr] = 1;
    return;
  }
  unsigned left = (curr << 1) + 1, right = left + 1;
  int mid = l + (r - l)/2;
  build(left, l, mid);
  build(right, mid, r);
  int delta = min(lt[left], rt[right]);
  sum[curr] = sum[left] + sum[right] + delta*2;
  lt[curr] = lt[right] + lt[left] - delta;
  rt[curr] = rt[right] + rt[left] - delta;
}

struct seg {
  int lt = 0, rt = 0, sum = 0;
  seg operator+= (const seg &b) {
    int delta = min(lt, b.rt);
    sum += b.sum + delta*2;
    lt += b.lt - delta;
    rt += b.rt - delta;
    return *this;
  }
};

seg query(unsigned curr, int beg, int end, int l, int r) {
  seg ans;
  if (beg == l && end == r) {
    ans.sum = sum[curr];
    ans.lt = lt[curr];
    ans.rt = rt[curr];
    // printf("1[%d, %d)%d %d %d\n",beg, end,ans.lt, ans.rt, ans.sum);
    return ans;
  }
  unsigned left = (curr << 1) + 1, right = left + 1;
  int mid = l + (r - l)/2;
  if (beg < mid) ans = query(left, beg, min(end, mid), l, mid);
  if (end > mid) ans += query(right, max(beg, mid), end, mid, r);
  // printf("2[%d, %d)%d %d %d\n",beg, end,ans.lt, ans.rt, ans.sum);
  return ans;
}

int n, m;

int main() {
  scanf("%s", str);
  scanf("%d", &m);
  n = std::strlen(str);
  build(0, 0, n);
  int l, r;
  while (m--) {
    scanf("%d%d", &l, &r);
    l--;
    seg ans = query(0, l, r, 0, n);
    printf("%d\n", ans.sum);
  }
  return 0;
}
