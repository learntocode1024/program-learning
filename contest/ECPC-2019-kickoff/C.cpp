// contest/ECPC-2019-kickoff/C.cpp
// https://codeforces.com/gym/102881
// Created by learntocode1024 on 12/02/20.
// 

#include <cstdio>
#define MX 100005
int n;
int val[MX], nxt[MX], tot;
int a[MX];

void solve(int init) {
  printf("%d ", a[init]);
  for (int i = nxt[0], prev = 0; i > 0; prev = i, i = nxt[i]) {
    if (a[init] & a[val[i]]) nxt[prev] = nxt[i], nxt[i] = 0, solve(val[i]);
  }
  for (int i = nxt[0], prev = 0; i > 0; prev = i, i = nxt[i]) {
    if ((a[init] & ~a[val[i]]) == a[init]) nxt[prev] = nxt[i], nxt[i] = 0, solve(val[i]);
  }
}

int main() {
  freopen("sorting.in", "r", stdin);
  int T = 1;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", a + i);
  }
  for (int i = 2; i <= n; ++i) {
    nxt[tot] = tot + 1;
    val[++tot] = i;
  }
  while (T--) {
    solve(1);
  }
  return 0;
}
