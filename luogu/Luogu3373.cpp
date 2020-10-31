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
        add(root, x, y, k);
        continue;
      }
      mul(root, x, y, k);
      continue;
    }
  }
  return 0;
}