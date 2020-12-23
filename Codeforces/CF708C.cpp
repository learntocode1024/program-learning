// CodeForces/CF708C.cpp
// https://codeforces.com/problemset/problem/708/C
// Created by learntocode1024 on 10/04/20.
// AC on Oct 9 2020

#include <cstdio>
#include <iostream>
#include <algorithm>
#define MX 400001
using std::cin;
using std::max;
struct edge {
  int to;
  edge* nxt = NULL;
};
edge* head[MX];

edge pool[MX << 1];
int it = -1;
void add_edge(const int &a, const int &b) {
  pool[++it].to = b;
  pool[it].nxt = head[a];
  head[a] = pool + it;
}
int n;
int size[MX], mx_chi[MX], fm[MX], dp[MX][2], chroot[MX];
bool ans[MX];

void pre_proc(const int &curr) {
  size[curr] = 1;
  for (edge* iter = head[curr]; iter != NULL; iter = iter->nxt) {
    int child = iter->to;
    if (size[child]) continue;
    pre_proc(child);
    size[curr] += size[child];
    if (size[child] > size[mx_chi[curr]]) mx_chi[curr] = child;
    int mx;
    if (size[child] > (n >> 1)) mx = dp[child][0];
    else mx = size[child];
    if (mx > dp[curr][0]) {
      fm[curr] = child;
      dp[curr][1] = dp[curr][0];
      dp[curr][0] = mx;
    } else
      dp[curr][1] = max(mx, dp[curr][1]);
  }
}

void dfs(const int &curr, const int &fa) {
  ans[curr] = true;
  if (size[mx_chi[curr]] > (n >> 1)) ans[curr] = (size[mx_chi[curr]] -\
                                                  dp[mx_chi[curr]][0] <= n/2);
  else if (n - size[curr] > n/2) ans[curr] = (n - size[curr] - chroot[curr] <= n/2);
  int val = n - size[curr];
  if (val > n/2) val = chroot[curr];
  for (edge* iter = head[curr]; iter != NULL; iter = iter->nxt) {
    int child = iter->to;
    if (child == fa) continue;
    chroot[child] = max(val, dp[curr][fm[curr] == child]);
    dfs(child, curr);
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  for (int kI = 1, a, b; kI < n; ++kI) {
    cin >> a >> b;
    add_edge(a, b);
    add_edge(b, a);
  }
  pre_proc(1);
  dfs(1, 0);
  for (int kI = 1; kI <= n; ++kI) {
    printf("%d ", ans[kI]);
  }
//  printf("\b\n");
  return 0;
}
