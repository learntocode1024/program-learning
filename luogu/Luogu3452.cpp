// luogu/Luogu3452.cpp
// https://www.luogu.com.cn/problem/P3452
// Created by learntocode1024 on 12/01/20.
//

#include <memory.h>
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <list>
#include <queue>
#define MX 200005
using std::cin;
using std::cout;
using std::endl;
std::list<int> lt;
std::queue<int> q;

using namespace std;
int n, m;
int ans;
int h[100001], to[4000001], nx[4000001], cnt;
int pre[100001], nxt[100001];
bool book[100001];
bool tmp[100001];
int sum[100001];
inline void add(int f, int t) {
  nx[++cnt] = h[f];
  to[cnt] = t;
  h[f] = cnt;
}
inline void del(int x) {
  book[x] = 1;
  nxt[pre[x]] = nxt[x];
  pre[nxt[x]] = pre[x];
}
int main() {
  int a, b;
  std::ios::sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    cin >> a >> b;
    add(a, b);
    add(b, a);
  }
  queue<int> e;
  int he = 1, ta = n;
  for (int i = 1; i <= n; i++) pre[i] = i - 1, nxt[i] = i + 1;
  nxt[n] = 0;
  for (int i = 1; i <= n; i++)
    if (!book[i]) {
      del(i);
      ++ans;
      e.push(i);
      while (!e.empty()) {
        int x = e.front();
        e.pop();
        for (int j = h[x]; j; j = nx[j]) tmp[to[j]] = 1;
        for (int j = nxt[0]; j; j = nxt[j])
          if (!tmp[j] && !book[j]) e.push(j), ++sum[ans], del(j);
        for (int j = h[x]; j; j = nx[j]) tmp[to[j]] = 0;
      }
    }
  sort(sum + 1, sum + ans + 1);
  printf("%d\n", ans);
  for (int i = 1; i <= ans; i++) printf("%d ", sum[i] + 1);
}