// CodeForces/CF1452/E.cpp
// https://codeforces.com/contest/1452/problem/E
// Created by learntocode1024 on 11/19/20.
// 

#include <iostream>
#include <queue>
#include <cstdio>
using std::cin;
using std::cout;
using std::endl;
#define MX 2005

int n, m, k;
int sec[MX];
int sum[MX];

int get(int x) {
  int ans = 0;
  while (x) {
    ans += sum[x];
    x -= x & (-x);
  }
  return ans;
}

void modify(int x, int t) {
  while (x <= n) {
    sum[x] += t;
    x += x & (-x);
  }
}

void assign(int beg, int end) {
  sec[beg]++;
  sec[end]--;
  modify(beg, 1);
  modify(end, -1);
}

int main() {
  cin >> n >> m >> k;
  int tmp1, tmp2;
  while (m--) {
    cin >> tmp1 >> tmp2;
    assign(tmp1 - 1, tmp2);
  }
  int ans = 0;
  int sum_1 = 0, sum = 0, prev = 0, succ = 0;
  for (int kI = 0; kI < k; ++kI) {
    succ += sec[kI];
    sum_1 += succ;
  }
  succ += sec[k];
  for (int kI = 0; kI <= n - k; ++kI) {
    for (int kJ = kI + 1; kJ <= n - k; ++kJ) {
      //calc
    }
    sum_1 += (succ - prev);
    prev += sec[kI];
    succ += sec[kI + k];
  }
  cout << ans << endl;
  return 0;
}
