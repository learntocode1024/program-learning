// contest/ECPC-2019-kickoff/B.cpp
// https://codeforces.com/gym/102881
// Created by learntocode1024 on 12/02/20.
// AC

#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
const double EPS = 1e-6;

double calc(double a, double b, double c) {
  double p = (a + b + c) / 2;
  return p * (p - a) * (p - b) * (p - c);
}

void solve() {
  double a, b, c, k, tmp;
  scanf("%lf%lf%lf%lf", &a, &b, &c, &k);
  double ans = 0;
  for (int i = 0; i < 3; ++i) {
    double l = max(abs(b - c), a), r = min(a + k, b + c), lmid, rmid;
    while (r - l > EPS) {
      lmid = l * 2/3 + r * 1/3;
      rmid = l * 1/3 + r * 2/3;
      if (calc(lmid, b, c) > calc(rmid, b, c)) r = rmid;
      else l = lmid;
    }
    ans = max(ans, calc(l, b, c));
    tmp = a, a = b, b = c, c = tmp;
  }
  ans = sqrt(ans);
  printf("%.9lf\n", ans);
}

int main() {
  freopen("sticks.in", "r", stdin);
  int T = 1;
  scanf("%d", &T);
  while (T--) {
    solve();
  }
  return 0;
}
