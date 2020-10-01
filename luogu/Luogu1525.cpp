// luogu/P1525.cpp
// https://www.luogu.com.cn/problem/P1525
// Created by learntocode1024 on Wed Aug 26 2020.
// AC on Aug 28 2020

#include <cstdio>
#include <cstring>
#define MXN 100005
#define MXM 200005
typedef int ch;

struct edge {
    int key = -1;
    int w;
    int nxt;
    edge next() const;
};

int node[MXN];
bool b = true;
ch visit[MXN];
edge adj[MXM];
edge nil;
int N, M, mid;

edge edge::next() const {
    if (nxt == -1) return nil;
    return adj[nxt];
};

void dfs(int curr, ch color) {
    if (!b) return;
    visit[curr] = color;
    for (edge j = adj[node[curr]]; j.key != -1; j = j.next()) {
        if (j.w > mid) {
            if (!visit[j.key]) dfs(j.key, 3 - color);
            else if (visit[j.key] == color) {
                b = false;
                return;
            }
        }
    }
}

bool judge() {
    b = true;
    memset(visit, 0, sizeof(visit));
    for (int i = 1; i <= N && b; ++i) {
        if (!visit[i]) dfs(i, 1);
    }
    return b;
}

int main() {
    // input
    setbuf(stdout, NULL);
    int mx_w = 0;
    scanf("%d %d", &N, &M);
    memset(node, -1, sizeof(node));
    for (int i = 0, fi, to, w; i != (M << 1);) {
        scanf("%d %d %d", &fi, &to, &w);
        if (w > mx_w) mx_w = w;
        adj[i].nxt = node[fi];
        adj[i].key = to;
        adj[i].w = w;
        node[fi] = i;
        ++i;
        adj[i].nxt = node[to];
        adj[i].key = fi;
        adj[i].w = w;
        node[to] = i;
        ++i;
    }
    // binary answer
    int lo = 0, hi = mx_w;
    while (lo < hi) {
        mid = lo + (hi - lo >> 1);
        if (judge()) hi = mid;
        else  lo = mid + 1;
    }
    printf("%d", lo);
    return 0;
}