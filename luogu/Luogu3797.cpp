// luogu/Luogu3797.cpp
// https://www.luogu.com.cn/problem/P3797
// Created by learntocode1024 on 10/29/20.
// AC

#include <cstdio>
#include <cstring>
#define MX 200005
#define MX_4 800020

inline int min(int a, int b) {
  return (a < b)? a : b;
}

inline int max(int a, int b) {
  return (a > b)? a : b;
}

char str[MX];
int val[MX_4];
bool tag[MX_4][3]{0};

void modify(unsigned curr, int pos, int l, int r) {
  if (r - l == 1) {
    tag[curr][0] = tag[curr][1] = tag[curr][2] =false;
    if (str[pos] == '(') tag[curr][0] = true;
    else if (str[pos] == ')') tag[curr][1] = true;
    else tag[curr][2] = true;
    return;
  }
  unsigned left = (curr << 1) + 1, right = left + 1;
  int mid = l + ((r - l) >> 1);
  if (pos >= mid) modify(right, pos, mid, r);
  if (pos < mid) modify(left, pos, l, mid);
  val[curr] = val[left] + val[right] + (tag[left][0] && tag[right][1]);
  tag[curr][0] = tag[right][0] || (tag[left][0] && tag[right][2]);
  tag[curr][1] = tag[left][1] || (tag[right][1] && tag[left][2]);
  tag[curr][2] = tag[left][2] && tag[right][2];
}

struct rt {
  int sum;
  bool l, r, e;
  rt() {
    sum = l = r = e = 0;
  }
  rt (int a, bool b, bool c, bool d) {
    sum = a, l = b, r = c, e = d;
  }
  rt operator+ (const rt &b) {
    rt ans;
    ans.sum = sum + b.sum + (l && b.r);
    ans.l = b.l || (l && b.e);
    ans.r = r || (b.r && e);
    ans.e = e && b.e;
    return ans;
  }
};

rt query(unsigned curr, int beg, int end, int l, int r) {
  if (beg == l && end == r) {
    return rt(val[curr], tag[curr][0], tag[curr][1], tag[curr][2]);
  }
  unsigned left = (curr << 1) + 1, right = left + 1;
  int mid = l + ((r - l) >> 1);
  rt lans, rans;
  if (beg < mid) lans = query(left, beg, min(mid, end), l, mid);
  if (end > mid) rans = query(right, max(mid, beg), end, mid, r);
  return lans + rans;
}

void build(unsigned curr, int l, int r) {
  if (r - l == 1) {
    tag[curr][0] = tag[curr][1] =false;
    if (str[l] == '(') tag[curr][0] = true;
    else if (str[l] == ')') tag[curr][1] = true;
    else tag[curr][2] = true;
    return;
  }
  unsigned left = (curr << 1) + 1, right = left + 1;
  int mid = l + ((r - l) >> 1);
  build(right, mid, r);
  build(left, l, mid);
  val[curr] = val[left] + val[right] + (tag[left][0] && tag[right][1]);
  tag[curr][0] = tag[right][0] || (tag[left][0] && tag[right][2]);
  tag[curr][1] = tag[left][1] || (tag[right][1] && tag[left][2]);
  tag[curr][2] = tag[left][2] && tag[right][2];
}

int n, m;

int main() {
  scanf("%d%d", &n, &m);
  std::memset(str, 88, sizeof(str));
  str[0] = '(';
  str[n - 1] = ')';
  build(0, 0, n);
  int op, l, r;
  char ch;
  while (m--) {
    scanf("%d", &op);
    if (op == 1) {
      scanf("%d %c", &l, &ch);
      str[l - 1] = ch;
      modify(0, l - 1, 0, n);
    } else {
      scanf("%d%d", &l, &r);
      printf("%d\n", query(0, l - 1, r, 0, n).sum);
    }
  }
  return 0;
}
