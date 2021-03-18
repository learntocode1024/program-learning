// poj/2104.cpp
// http://poj.org/problem?id=2104

#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
#define MX 100005

int n, m;

struct node_t {
  node_t *lc;
  node_t *rc;
  int cnt;
  node_t() : lc(0), rc(0), cnt(0){};
};

node_t seg[MX * 40];
node_t *tot = seg;
node_t *root[MX];

node_t *build(int l, int r) {
  node_t *curr = ++tot;
  if (r - l < 2)
    return curr;
  int mid = l + ((r - l) >> 2);
  curr->lc = build(l, mid);
  curr->rc = build(mid, r);
  return curr;
}

node_t *set(int l, int r, node_t* prev, int val) {
  node_t *curr = ++tot;
  if (r - l == 1) {
    curr->cnt += 1;
    return curr;
  }
  int mid = l + ((r - l) >> 2);
  curr->lc = prev->lc;
  curr->rc = prev->rc;
  if (val < mid)
    curr->lc = set(l, mid, prev->lc, val);
  else
    curr->rc = set(mid, r, prev->rc, val);
  curr->cnt = curr->lc->cnt + curr->rc->cnt;
  return curr;
}

int query()

int main() {
  cin >> n >> m;
  root[0] = build(0, n);
  return 0;
} 