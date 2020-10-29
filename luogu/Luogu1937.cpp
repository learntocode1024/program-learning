// luogu/Luogu1937.cpp
// https://www.luogu.com.cn/problem/P1937
// Created by learntocode1024 on 10/29/20.
// AC on 10/29/20

#include <cstdio>
#include <algorithm>
#define MX 100005
#define MXx4 400005
using std::sort;
using std::min;
using std::max;
const int inf = 400000;
const int root = 0;

int tag[MXx4]{}, val[MXx4]{};

void push_down(unsigned curr) {
  if (tag[curr] == 0) return;
  unsigned left = (curr << 1) + 1, right = left + 1;
  val[left] += tag[curr];
  val[right] += tag[curr];
  tag[left] += tag[curr];
  tag[right] += tag[curr];
  tag[curr] = 0;
}

void fit(unsigned curr, int beg, int end, int l, int r) {
  if (beg == l && end == r) {
    val[curr]--;
    tag[curr]--;
    return;
  }
  push_down(curr);
  unsigned left = (curr << 1) + 1, right = left + 1;
  int mid = l + (r - l)/2;
  if (beg < mid) fit(left, beg, min(end, mid), l, mid);
  if (end > mid) fit(right, max(beg, mid), end, mid, r);
  val[curr] = min(val[left], val[right]);
}

int query(unsigned curr, int beg, int end, int l, int r) {
  if (beg == l && end == r) {
    return val[curr];
  }
  push_down(curr);
  unsigned left = (curr << 1) + 1, right = left + 1;
  int mid = l + (r - l)/2;
  int ans = inf;
  if (beg < mid) ans = min(ans, query(left, beg, min(end, mid), l, mid));
  if (end > mid) ans = min(ans, query(right, max(beg, mid), end, mid, r));
  return ans;
}

void build(int curr, int* const ptr, int l, int r) {
  if (r - l == 1) {
    val[curr] = ptr[l];
    return;
  }
  unsigned left = (curr << 1) + 1, right = left + 1;
  int mid = l + (r - l)/2;
  build(left, ptr, l, mid);
  build(right, ptr, mid, r);
  val[curr] = min(val[left], val[right]);
}

int N, M, a[MX];

struct request {
  int l, r;
  bool operator <(const request &b) {
    return r < b.r;
  }
} Req[MX];

int main() {
  scanf("%d%d", &N, &M);
  for (int kI = 0; kI < N; ++kI) scanf("%d", a + kI);
  build(root, a, 0, N);
  for (int kI = 0, l, r; kI < M; ++kI) {
    scanf("%d%d", &l, &r);
    Req[kI].l = l - 1;
    Req[kI].r = r;
  }
  sort(Req, Req + M);
  for (int kI = 0; kI < M; ++kI) {
    printf("%d %d\n", Req[kI].l, Req[kI].r);
  }
  int ans = 0;
  for (int kI = 0; kI < M; ++kI) {
    int &l = Req[kI].l, &r = Req[kI].r;
    if (query(root, l, r, 0, N) <= 0) continue; // drop it
    fit(root, l, r, 0, N);
    ++ans;
  }
  printf("%d\n", ans);
  return 0;
}
