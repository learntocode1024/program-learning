// luogu/Luogu6619.cpp
// Author: misaka18931
// Date: 03-08-21
// URL: https://www.luogu.com.cn/problem/P6619
// tag:
//

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long LL;

template <typename T> void fastscan(T &number) {
  // variable to indicate sign of input number
  bool negative = false;
  register T c;
  number = 0;
  // extract current character from buffer
  c = getchar();
  if (c == '-') {
    // number is negative
    negative = true;
    // extract the next character from the buffer
    c = getchar();
  }
  // Keep on extracting characters if they are integers
  // i.e ASCII Value lies from '0'(48) to '9' (57)
  for (; (c > 47 && c < 58); c = getchar())
    number = number * 10 + c - 48;
  // if scanned input has a negative sign, negate the
  // value of the input number
  if (negative)
    number *= -1;
}

#define MX 20//00005
#define lowbit(X) (X & (~X + 1))
int T;
int n, c0, c1;
int query[4][MX];
struct {
  int id;
  int x;
} val[MX];
int tot;

int l[MX], r[MX];
int s0[MX], s1[MX];
int s_all;

void add(int *const buf, int x, int val) {
  while (x <= n) {
    buf[x] += val;
    x += lowbit(x);
  }
}

int get(int *const buf, int x) {
  int ans = 0;
  while (x) {
    ans += buf[x];
    x -= lowbit(x);
  }
  return ans;
}

void solve() {
  for (int i = 0; i < T; ++i) {
    if (query[0][i] == 1) {
      if (query[1][i] == 0) {
        ++c0;
        add(s0, query[2][i], query[3][i]);
      } else {
        ++c1;
        add(s1, query[2][i], query[3][i]);
        s_all += query[3][i];
      }
    } else {
      int t = query[1][i];
      if (query[1][t] == 0) {
        --c0;
        add(s0, query[2][t], -query[3][t]);
      } else {
        --c1;
        add(s1, query[2][t], -query[3][t]);
        s_all -= query[3][i];
      }
    }
    if (c0 == 0 || c1 == 0) {puts("Peace"); continue;}
    int x = 0, sum = 0;
    for (int bit = 20; bit >= 0; --bit) {
      int tmp = x + (1 << bit);
      if (tmp <= n && sum + s0[tmp] + s1[tmp] <= s_all) {
        sum = sum + s0[tmp] + s1[tmp];
        x = tmp;
      }
    }
    int ans = get(s0, l[x]);
    int ans1 = s_all - get(s1, r[x]);
    if (ans1 >= ans) ans = ans1, x = r[x];
    else x = l[x];
    printf("%d %d\n", val[x - 1].x, 2 * ans);
  }
}

int main() {
  fastscan(T);
  for (int i = 0; i < T; ++i) {
    fastscan(query[0][i]);
    fastscan(query[1][i]);
    if (query[0][i] == 1) {
      fastscan(query[2][i]);
      fastscan(query[3][i]);
      val[tot].id = i;
      val[tot++].x = query[2][i];
    }
  }
  n = tot;
  sort(val, val + tot, [](auto a, auto b) { return a.x < b.x; });
  for (int i = 0; i < tot; ++i) {
    query[2][val[i].id] = i + 1;
  }
  for (int i = 1; i < tot; ++i) {
    if (val[i].x > val[i - 1].x) l[i + 1] = i;
    else l[i + 1] = l[i];
  }
  r[n] = n;
  for (int i = tot - 2; i >= 0; --i) {
    if (val[i + 1].x > val[i].x) r[i + 1] = i + 2;
    else r[i + 1] = r[i + 2];
  }
  solve();
  return 0;
}
