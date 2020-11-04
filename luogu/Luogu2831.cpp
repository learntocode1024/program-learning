// luogu/Luogu2831.cpp
// https://www.luogu.com.cn/problem/P2831
// Created by learntocode1024 on 11/04/20.
// 

#include <iostream>
#include <cstring>
using std::cin;
using std::cout;
const double EPS = 1e-6;

int T, n, m;

double abs(double a) {
  if (a > 0) return a;
  return -a;
}

struct point {
  double x, y;
} pts[20];

bool path[20][20][20];
bool alive[20], tmp[20];
int ans = 18;
void dfs(int remain, int cnt) {
  if (cnt >= ans) return;
  if (remain == 1) {
    ans = cnt + 1;
    return;
  }
  if (remain == 0) {
    ans = cnt;
    return;
  }
  int first;
  for (int kI = 1; kI <= n; ++kI) {
    if (alive[kI]) {
      first = kI;
      break;
    }
  }
  for (int kI = first + 1; kI <= n; kI++) { // try
    if (alive[kI]) {
      std::memcpy(tmp, alive, sizeof(alive));
      int hit = 0;
      for (int kJ = 1; kJ <= n; ++kJ) {
        if (path[first][kI][kJ]) {
          alive[kJ] = false;
          ++hit;
        }
      }
      dfs(remain - hit, cnt + 1);
      std::memcpy(alive, tmp, sizeof(alive));
    }
  }
}

int main() {
  cin >> T;
  while (T--) {
    std::memset(path, 0, sizeof(path));
    std::memset(alive, 1, sizeof(alive));
    ans = 18;
    cin >> n >> m;
    double x, y;
    for (int kI = 1; kI <= n; ++kI) {
      cin >> x >> y;
      pts[kI].x = x;
      pts[kI].y = y;
    }
    for (int kI = 1; kI <= n; ++kI) {
      for (int kJ = kI + 1; kJ <= n; ++kJ) {
        double &x1 = pts[kI].x, &x2 = pts[kJ].x;
        double &y1 = pts[kI].y, &y2 = pts[kJ].y;
        double a = (x2 * y1 - x1 * y2) / ((x1 - x2) * x1 * x2);
        if (a > 0) continue;
        double b = (x2 * x2 * y1 - x1 * x1 * y2) / ((x2 - x1) * x1 * x2);
        for (int kQ = 1; kQ <= n; ++kQ) {
          if (abs(a * pts[kQ].x * pts[kQ].x + b * pts[kQ].x - pts[kQ].y) < EPS) path[kI][kJ][kQ] = true;
        }
      }
    }
    dfs(n, 0);
    cout << ans << std::endl;
  }
  return 0;
}
