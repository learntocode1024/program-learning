// CodeForces/CF1437E.cpp
// https://codeforces.com/problemset/problem/1437/E
// Created by learntocode1024 on 11/03/20.
// AC on 11/3/20

#include <iostream>
#include <vector>
#include <algorithm>
#define MX 50//0005
using std::cin;
using std::cout;
int arr[MX];
int lim[MX];

int solve(int beg, int end) { // solve LIS in n logn
  std::vector<int> v;
  for (int kI = beg; kI < end; ++kI) {
    if (arr[kI] >= arr[beg] && arr[kI] <= arr[end]) {
      if (v.empty() || v.back() <= arr[kI]) v.push_back(arr[kI]);
      else *std::upper_bound(v.begin(), v.end(), arr[kI]) = arr[kI];
    }
  }
  return (end - beg - v.size());
}

int main() {
  int n, k;
  cin >> n >> k;
  for (int kI = 1, t; kI <= n; ++kI) {
    cin >> t;
    arr[kI] = t - kI;
  }
  arr[0] = -1e9 - 5;
  arr[n + 1] = 2e9 + 5;
  for (int kI = 1, t; kI <= k; ++kI) {
    cin >> t;
    lim[kI] = t;
  }
  lim[k + 1] = n + 1;
  int ans = 0;
  for (int kI = 0; kI <= k; ++kI) {
    if (arr[lim[kI]] > arr[lim[kI + 1]]) {
      cout << "-1\n";
      return 0;
    }
    ans += solve(lim[kI], lim[kI + 1]);
  }
  cout << ans << "\n";
  return 0;
}
