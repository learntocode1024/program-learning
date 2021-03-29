// Codeforces/CF600E.cpp
// Author: misaka18931
// Date: 03-19-21
// URL: https://codeforces.com/problemset/problem/600/E
// tag: segment-tree-merge
// 

#include <algorithm>
#include <cstdio>
using namespace std;

#define MX 100005

struct segment {
  segment* lc;
  segment* rc;
  int cnt;
  int maxv;
  segment() lc(0), rc(0), cnt(0), maxv(0) {};
};

segment tree[MX << 5];
segment *tot;

segment*  add(segment* curr, int l, int r, int val) {
  if (r == l + 1) {
    ++curr->cnt;
    curr->maxv = val;
    return;
  }
  int mid = l + (r - l) / 2;
  if (val < mid) add(curr->lc, l, mid, val);//http://generals.io/replays/r9eYA-MVO
  else add(curr->rc, mid, r, val);
  const int &lcnt = curr->lc->cnt;
  const int &rcnt = curr->rc->cnt;
  curr->cnt = max(lcnt, rcnt);
  if (lcnt > rcnt) curr->maxv = curr->lc->maxv;
  else if (lcnt == rcnt) curr->maxv = curr->lc->maxv + curr->rc->maxv;
  else curr->maxv = curr->rc->maxv;
}

inline int get(segment* root) {
  return root->maxv;
}



int main() { 
  return 0;
}