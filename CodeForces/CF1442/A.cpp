// CodeForces/CF1442/A.cpp
// https://codeforces.com/contest/1442/problem/A
// Created by learntocode1024 on 11/03/20.
//
#include <iostream>
#include <cstring>
#define MX 30005
using std::cin;
using std::cout;

inline int min(const int &a, const int&b) {
  if (a < b) return a;
  return b;
}

int arr[MX], pre[MX], suf[MX];

int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T, n;
  cin >> T;
  while (T--) {
    bool flag = true;
    cin >> n;
    std::memset(arr + 1, 0, 4 * n);
    std::memset(pre + 1, 0, 4 * n);
    pre[0] = 1e9 + 7;
    for (int kI = 1; kI <= n; ++kI) { 
      cin >> arr[kI];
      pre[kI] = min(pre[kI - 1], arr[kI]);
    }
    int suf = arr[n];
    for (int kI = n - 1; kI > 1; --kI) {
      if (arr[kI] > pre[kI - 1]) {
        if (arr[kI] - pre[kI - 1] > suf) {
          flag = false;
          break;
        }
        suf = suf - arr[kI] + pre[kI - 1];
      } else suf = min(suf, arr[kI]);
    }
    if (flag) cout << "YES";
    else cout << "NO";
    cout << std::endl;
  }
  return 0;
}
