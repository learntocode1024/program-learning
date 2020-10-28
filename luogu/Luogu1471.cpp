// luogu/Luogu1471.cpp
// https://www.luogu.com.cn/problem/P1471
// Created by learntocode1024 on 10/28/20.
// AC on 10/28/10

#include <cstdio>
#include <algorithm>
#define 4MX 400005
using std::min;
using std::max;
double sum[4MX]{}, sum2[4MX]{}, tag[4MX]{}; // can't declare inside struct
class segmentTree {
  const unsigned root = 0;
  int size = 0;
  void push_down(const unsigned curr, const int l, const int r) {
    if (tag[curr] == 0) return;
    unsigned left = (curr << 1) + 1, right = left + 1;
    int mid = l + (r - l)/2;
    sum2[left] += (tag[curr]*sum[left]*2) + (mid - l)*tag[curr]*tag[curr];
    sum2[right] += (tag[curr]*sum[right]*2) + (r - mid)*tag[curr]*tag[curr];
    sum[left] += tag[curr] * (mid - l);
    sum[right] += tag[curr] * (r - mid);
    // pass down
    tag[right] += tag[curr], tag[left] += tag[curr];
    tag[curr] = 0;
  }
  void add_up(const double val, const unsigned curr,
              const int beg, const int end,
              const int l, const int r) {
    if (beg == l && end == r) {
      sum2[curr] += (val*sum[curr]*2) + (r - l) * val * val;
      sum[curr] += val * (r - l);
      tag[curr] += val;
      return;
    }
    push_down(curr, l, r);
    unsigned left = (curr << 1) + 1, right = left + 1;
    int mid = l + (r - l)/2;
    if (beg < mid) add_up(val, left, beg, min(mid, end), l, mid);
    if (end > mid) add_up(val, right, max(beg, mid), end, mid, r);
    sum2[curr] = sum2[left] + sum2[right];
    sum[curr] = sum[left] + sum[right];
  }
  double get_sum(const unsigned curr,
              const int beg, const int end,
              const int l, const int r) {
    if (beg == l && end == r) {
      return sum[curr];
    }
    push_down(curr, l, r);
    unsigned left = (curr << 1) + 1, right = left + 1;
    int mid = l + (r - l)/2;
    double ans = 0;
    if (beg < mid) ans += get_sum(left, beg, min(mid, end), l, mid);
    if (end > mid) ans += get_sum(right, max(mid, beg), end, mid, r);
    return ans;
  }
  double get_sum2(const unsigned curr,
              const int beg, const int end,
              const int l, const int r) {
    if (beg == l && end == r) {
      return sum2[curr];
    }
    push_down(curr, l, r);
    unsigned left = (curr << 1) + 1, right = left + 1;
    int mid = l + (r - l)/2;
    double ans = 0;
    if (beg < mid) ans += get_sum2(left, beg, min(mid, end), l, mid);
    if (end > mid) ans += get_sum2(right, max(mid, beg), end, mid, r);
    return ans;
  }
  void build(const unsigned curr, double* const ptr,
             const int l, const int r) {
    if (r - l == 1) {
      sum[curr] = ptr[l];
      sum2[curr] = ptr[l] * ptr[l];
      return;
    }
    unsigned left = (curr << 1) + 1, right = left + 1;
    int mid = l + (r - l)/2;
    build(left, ptr, l, mid);
    build(right, ptr, mid, r);
    sum2[curr] = sum2[left] + sum2[right];
    sum[curr] = sum[left] + sum[right];
  }
public:
  segmentTree(double* const beg, double* const end) {
    size = end - beg;
    build(root, beg, 0, size);
  }
  void add(const double val, const int beg, const int end) {
    add_up(val, root, beg, end, 0, size);
  }
  double avg(const int beg, const int end) {
    return (get_sum(root, beg, end, 0, size) / (end - beg));
  }
  double mdev(const int beg, const int end) {
    double ans = get_sum2(root, beg, end, 0, size) / (end - beg);
    double segavg = avg(beg, end);
    return (ans - (segavg * segavg));
  }
};

int n, m;
double a[MX];

int main() {
  scanf("%d%d", &n, &m);
  for (int kI = 0; kI < n; ++kI) {
    scanf("%lf", a + kI);
  }
  segmentTree Tree(a, a + n);
  int op, x, y;
  double k;
  while (m--) {
    scanf("%d%d%d", &op, &x, &y);
    if (op == 1) {
      scanf("%lf", &k);
      Tree.add(k, x - 1, y);
      continue;
    }
    if (op == 2) {
      printf("%.4lf\n", Tree.avg(x - 1, y));
      continue;
    }
    if (op == 3) {
      printf("%.4lf\n", Tree.mdev(x - 1, y));
    }
  }
  return 0;
}
