// luogu/Luogu1382.cpp
// https://www.luogu.com.cn/problem/P1382
// Created by learntocode1024 on 10/27/20.
// AC on 20/27/10

#include <iostream>
#include <algorithm>
#include <queue>
#define MX 100005
using std::lower_bound;
using std::sort;
using std::unique;
using std::priority_queue;
using std::cin;
using std::cout;

struct point {
  int pos;
  unsigned h;
  bool beg;
  void init(int x, unsigned y, bool z) {
    pos = x;
    h = y;
    beg = z;
  }
  bool operator< (const point& b) const {
    return pos < b.pos;
  }
} pt[MX*2];

int val[MX], cnt[MX];
int* v_end;
std::pair<int, int> buffer[MX*2];
int cnt_output;

inline void print(int pos, int h) {
  if (buffer[cnt_output - 1].first == buffer[cnt_output - 2].first) {
    if (buffer[cnt_output - 1].first == pos) {
      buffer[cnt_output - 1].second = h;
      return;
    }
  }
  buffer[cnt_output] = {pos, h};
  ++cnt_output;
}

inline void print_all() {
  cout << cnt_output << '\n';
  for (int kI = 0; kI < cnt_output; ++kI) {
    cout << buffer[kI].first << ' ' << buffer[kI].second << '\n';
  }
}

int get_rank(int h) {
  return lower_bound(val, v_end, h) - val;
}

priority_queue<int> heap;
int get_top() {
  while (cnt[get_rank(heap.top())]) {
    cnt[get_rank(heap.top())]--;
    heap.pop();
  }
  return heap.top();
}

void erase(int h) {
  if (heap.top() == h) {
    heap.pop();
  } else {
    cnt[get_rank(h)]++;
  }
}

int n;

int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  int hI, lI, rI;
  for (int kI = 0; kI < n*2; ++kI) {
    cin >> hI >> lI >> rI;
    val[kI/2] = hI;
    pt[kI].init(lI, hI, true);
    pt[++kI].init(rI, hI, false);
  }
  sort(pt, pt + 2*n);
  // distance
  sort(val, val + n);
  v_end = unique(val, val + n);

  heap.push(0);
  for (int kI = 0; kI < n*2; ++kI) {
    point &curr = pt[kI];
    if (curr.beg) {
      if (curr.h > get_top()) {
        print(curr.pos, heap.top());
        print(curr.pos, curr.h);
      }
      heap.push(curr.h);
    } else {
      erase(curr.h);
      if (curr.h > get_top()) {
        print(curr.pos, curr.h);
        print(curr.pos, heap.top());
      }
    }
  }
  print_all();
  return 0;
}