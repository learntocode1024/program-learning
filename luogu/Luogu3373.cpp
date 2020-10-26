// luogu/Luogu3373.cpp
// https://www.luogu.com.cn/problem/P3373
// Created by learntocode1024 on 10/26/20.
// 

#include <iostream>
#define MX 100005
using std::cin;
using std::cout;
const int mod = 571373;
const unsigned root = 0;

struct segment {
  int l = 0, r = 0;
  int sum = 0;
  int add = 0;
  int mul = 1;
  #define l(val) left(val)
  #define r(val) right(val)
  #define mul(val) tree[val].mul
  #define add(val) tree[val].add
  #define sum(val) tree[val].sum
  int mid() const {
    return l + (r - l)/2;
  }
  int len() const {
    return r - l;
  }
} tree[MX << 2];

inline unsigned left(unsigned val) {
  return (val << 1) + 1;
}

inline unsigned right(unsigned val) {
  return (val << 1) + 2;
}

void build(const int* p, const unsigned seg, const unsigned beg, const unsigned end) {
  if (end - beg == 1) {
    sum(seg) = p[beg];
    return;
  }
  const unsigned mid = beg + (end - beg)/2;
  unsigned l = l(seg), r = r(seg);
  tree[l].l = beg; tree[l].r = mid;
  tree[r].l = mid; tree[r].r = end;
  build(p, l, beg, mid);
  build(p, r, mid, end);
  sum(seg) = (sum(l(seg)) + sum(r(seg))) % mod;
}

void push_down(unsigned curr) {
  unsigned l = l(curr), r = r(curr);
  // val
  sum(l) = (sum(l) * mul(curr) + add(curr)*tree[l].len())%mod;
  sum(r) = (sum(r) * mul(curr) + add(curr)*tree[r].len())%mod;
  // tag push down
  mul(l) = (mul(l) * mul(curr))%mod;
  add(l) = (add(l) * mul(curr) + add(curr))%mod;
  mul(r) = (mul(r) * mul(curr))%mod;
  add(r) = (add(r) * mul(curr) + add(curr))%mod;
  add(curr) = 0;
  mul(curr) = 1;
}

void seg_mul(const unsigned seg, int beg, int end, int val) {
  // equal
  if (beg == tree[seg].l && end == tree[seg].r) {
    sum(seg) = (sum(seg) * val)%mod;
    add(seg) = (add(seg) * val)%mod;
    mul(seg) = (mul(seg) * val)%mod;
    return;
  }
  int mid = tree[seg].mid();
  push_down(seg);
  if (beg < mid) { // left covered
    seg_mul(l(seg), beg, mid, val);
  }
  if (end > mid) { // right covered
    seg_mul(r(seg), mid, end, val);
  }
  sum(seg) = sum(l(seg)) + sum(r(seg));
}

void seg_add(const unsigned seg, int beg, int end, int val) {
  // equal
  if (beg == tree[seg].l && end == tree[seg].r) {
    sum(seg) = (sum(seg) + val *tree[seg].len())%mod;
    add(seg) = (add(seg) + val)%mod;
    return;
  }
  int mid = tree[seg].mid();
  push_down(seg);
  if (beg < mid) { // left covered
    seg_add(l(seg), beg, mid, val);
  }
  if (end > mid) { // right covered
    seg_add(r(seg), mid, end, val);
  }
  sum(seg) = sum(l(seg)) + sum(r(seg));
}

int query(const unsigned seg, int beg, int end) {
  if (beg == tree[seg].l && end == tree[seg].r) {
    return sum(seg);
  }
  int mid = tree[seg].mid();
  push_down(seg);
  int ans = 0;
  if (beg < mid) { // left covered
    ans += query(l(seg), beg, mid);
  }
  if (end > mid) { // right covered
    ans += query(r(seg), mid, end);
  }
  return ans;
}

int n, m, p;

int main() {
  cin >> n >> m >> p;
  int tmp[n];
  for (int kI = 0; kI < n; ++kI) {
    cin >> tmp[kI];
  }
  tree[root].l = 0;
  tree[root].r = n;
  build(tmp, root, 0, n);
  int op, x, y, k;
  while (m--) {
    cin >> op >> x >> y;
    --x;
    if (op == 3) {
      cout << query(root, x, y) << "\n";
      continue;
    } else {
      cin >> k;
      if (op == 2) {
        seg_add(root, x, y, k);
        continue;
      }
      seg_mul(root, x, y, k);
      continue;
    }
  }
  return 0;
}