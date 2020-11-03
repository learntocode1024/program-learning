// CodeForces/CF1436D.cpp
// https://codeforces.com/problemset/problem/1436/D
// Created by learntocode1024 on 11/03/20.
// 

#include <iostream>
#include <queue>
#define MX 200005
using std::cin;
using std::cout;

int head[MX], nxt[MX], to[MX], tot;
int val[MX], sz[MX], mx[MX], cnt[MX];

void add_edge(int a, int b) {
  to[++tot] = b;
  nxt[tot] = head[a];
  head[a] = tot;
}

void dfs(int curr, int fa) {
  sz[curr] = val[curr];
  int mx_id = 0, mx_val = 0;
  for (int i = head[curr]; i != 0; i = nxt[i]) {
    int &next = to[i];
    if (next == fa) continue;
    dfs(next, curr);
    sz[curr] += sz[next];
    if (sz[next] > mx_val) {
      mx_val = sz[next];
      mx_id = next;
    }
  }
  mx[curr] = mx_id;
}

int calc() {
  std::queue<int> Q;
  Q.push(1);
  int curr, next;
  while (!Q.empty()) {
    curr = Q.front();
    Q.pop();
    
  }
}

int n;

int main() {
  cin >> n;
  for (int kI = 2, tmp; kI <= n; ++kI) {
    cin >> tmp;
    add_edge(tmp, kI);
  }
  for (int kI = 1, tmp; kI <= n; ++kI) {
    cin >> tmp;
    val[kI] = tmp;
  }
  dfs(1, 0);
  cout << calc();
  return 0;
}
