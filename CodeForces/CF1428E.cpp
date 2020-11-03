// CodeForces/CF1428E.cpp
// https://codeforces.com/problemset/problem/1428/E
// Created by learntocode1024 on 11/03/20.
// 

#include <iostream>
#include <algorithm>
using std::cin;
using std::cout;

long long carr[100005];
int n, k;
long long sum = 0;

bool cmp(int a, int b) { // reverse
  return a > b;
}

int main() {
  cin >> n >> k;
  for (int kI = 0; kI < n; ++kI) {
    cin >> carr[kI];
    sum += carr[kI];
  }
  double avg = (double)sum/k;
  std::sort(carr, carr + n, cmp);
  long long ans = 0;
  long long tmp = sum/k;
  k -= n;
  for (int kI = 0; kI < n; ++kI) {
    if (carr[kI] >= 2*avg && k > 0) { // divide
      int div = carr[kI]/avg;
      if (div <= k) {
        ans += tmp * tmp * div;
        ans += (2 * tmp + 1) * (carr[kI] - tmp * div);
        k -= div - 1;
      } else {
        ++k;
        long long tmp2 = carr[kI] / k;
        ans += tmp2 * tmp2 * k;
        ans += (2 * tmp2 + 1) * (carr[kI] - tmp2 * k);
      }
    } else {
      ans += carr[kI] * carr[kI];
    }
  }
  cout << ans << std::endl;
  return 0;
}