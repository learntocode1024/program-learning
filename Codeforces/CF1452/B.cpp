// CodeForces/CF1452/B.cpp
// https://codeforces.com/contest/1452/problem/B
// Created by learntocode1024 on 11/19/20.
// AC

#include <cstdio>
#include <iostream>
using namespace std;

int a[100005];

int main() {
  long long T, n;
  long long sum = 0, ans;
  cin >> T;
  while (T--) {
    sum = 0;
    cin >> n;
    for (int kI = 0; kI < n; ++kI) {
      cin >> a[kI];
      sum += a[kI];
    }
    ans = sum;
    if (sum % (n - 1)) sum = (sum / (n - 1) + 1) * (n - 1);
    for (int kI = 0; kI < n; ++kI) {
      if (sum < 1LL * a[kI] * (n - 1))
      sum = 1LL * a[kI] * (n - 1);
    }
    cout << sum - ans << endl;
  }
  return 0;
}
