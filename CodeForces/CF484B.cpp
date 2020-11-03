// CodeForces/CF484B.cpp
// https://codeforces.com/problemset/problem/484/B
// Created by learntocode1024 on 11/02/20.
// 
#include <cstdio>
#include <algorithm>
int arr[200005];

int n;

int main() {
  scanf("%d", &n);
  for (int kI = 0; kI < n; ++kI) scanf("%d", arr + kI);
  std::sort(arr, arr + n);
  int ans = 0;
  for (int kI = 0; kI < n; ++kI) {
    for (int times = 2; )
  }
  printf("%d", ans);
  return 0;
}
