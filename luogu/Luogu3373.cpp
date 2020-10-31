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
  tree[seg].l = beg, tree[seg].r = end;
  if (end - beg == 1) {
    tree[seg].sum = p[beg];
    return;
  }
  const unsigned mid = beg + (end - beg)/2;
  unsigned l = seg*2 + 1, r = seg*2 + 2;
  build(p, l, beg, mid);
  build(p, r, mid, end);
  tree[seg].sum = (tree[seg*2 + 1].sum + tree[seg*2 + 2].sum) % mod;
}

void push_down(unsigned curr) {
  unsigned l = left(curr), r = right(curr);

  tree[l].sum = (tree[l].sum * tree[curr].mul + tree[curr].add*tree[l].len())%mod;
  tree[r].sum = (tree[r].sum * tree[curr].mul + tree[curr].add*tree[r].len())%mod;

  tree[l].mul = (tree[l].mul * tree[curr].mul)%mod;
  tree[l].add = (tree[l].add c* tree[curr].mul + tree[curr].add)%mod;
  tree[r].mul = (tree[r].mul * tree[curr].mul)%mod;
  tree[r].add = (tree[r].add * tree[curr].mul + tree[curr].add)%mod;
  tree[curr].add = 0;
  tree[curr].mul = 1;
}

void seg_mul(const unsigned seg, int beg, int end, int val) {

  if (beg == tree[seg].l && end == tree[seg].r) {
    tree[seg].sum = (tree[seg].sum * val)%mod;
    tree[seg].add = (tree[seg].add * val)%mod;
    tree[seg].mul = (tree[seg].mul * val)%mod;
    return;
  }
  int mid = tree[seg].mid();
  push_down(seg);
  if (beg < mid) {
    seg_mul(seg*2 + 1, beg, mid, val);
  }
  if (end > mid) {
    seg_mul(seg*2 + 2, mid, end, val);
  }
  tree[seg].sum = tree[seg*2 + 1].sum + tree[seg*2 + 2].sum;
}

void seg_add(const unsigned seg, int beg, int end, int val) {

  if (beg == tree[seg].l && end == tree[seg].r) {
    tree[seg].sum = (tree[seg].sum + val *tree[seg].len())%mod;
    tree[seg].add = (tree[seg].add + val)%mod;
    return;
  }
  int mid = tree[seg].mid();
  push_down(seg);
  if (beg < mid) {
    seg_add(seg*2 + 1, beg, mid, val);
  }
  if (end > mid) {
    seg_add(seg*2 + 2, mid, end, val);
  }
  tree[seg].sum = tree[seg*2 + 1].sum + tree[seg*2 + 2].sum;
}

int query(const unsigned seg, int beg, int end) {
  if (beg == tree[seg].l && end == tree[seg].r) {
    return tree[seg].sum;
  }
  int mid = tree[seg].mid();
  push_down(seg);
  int ans = 0;
  if (beg < mid) {
    ans += query(seg*2 + 1, beg, mid);
  }
  if (end > mid) {
    ans += query(seg*2 + 2, mid, end);
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