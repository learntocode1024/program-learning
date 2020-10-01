// luogu/P3379.cpp
// https://www.luogu.com.cn/problem/P3379
// Created by learntocode1024 on 2020/8/19
// AC on Aug 21 2020

#include <cstring>
#include <cstdio>

const int MAXN = 500005;
int t = -1, N, M, S;
int lg[MAXN];
int fi[MAXN];
int key[MAXN*2];
int nxt[MAXN*2];
int anc[MAXN][22];
int depth[MAXN];

inline void add_edge(int from, int to) {
    ++t;
    key[t] = to;
    nxt[t] = fi[from];
    fi[from] = t;
}

void DFS(int curr, int fath) {
    // can only be called from parents to children
    depth[curr] = depth[fath] + 1;
    anc[curr][0] = fath;
    // build up!!!
    for (int j = 1; j <= lg[depth[curr]]; ++j)
        anc[curr][j] = anc[anc[curr][j - 1]][j - 1];
    // dfs child
    for (int i = fi[curr]; i != -1; i = nxt[i])
        if (key[i] != fath) DFS(key[i], curr);
}

void init() {
    // calc lg2
    for (int i = 1; i != N; ++i) {
        lg[i] = lg[i - 1] + (i >> lg[i - 1] == 1);
    }
    // clear fi;
    memset(fi, -1, MAXN*sizeof(int));
    // init tree
    int from, to;
    for (int i = 1; i != N; ++i) {
        scanf("%d %d", &from, &to);
        add_edge(from, to);
        add_edge(to, from);
    }
    DFS(S, S);
}

int LCA(int a, int b) {
    if (depth[a] < depth[b]) {
        int c = a;
        a = b;
        b = c;
    }
    int delta = depth[a] - depth[b], cnt = 0;
    while (delta) {
        if (delta & 1) a = anc[a][cnt];
        ++cnt;
        delta >>= 1;
    }
    // while (depth[a] > depth[b])
    //     a = anc[a][lg[depth[a] - depth[b]] - 1];
    if (a == b) return b;
    for (int k = lg[depth[a]] - 1; k != -1; --k) {
        if (anc[a][k] != anc[b][k]) {
            a = anc[a][k];
            b = anc[b][k];
        }
    }
    return anc[b][0];
}

int main() {
    scanf("%d %d %d", &N, &M, &S);
    init();
    int a, b;
    for (int l = 0; l != N; ++l) {
        scanf("%d %d", &a, &b);
        printf("%d\n", LCA(a, b));
    }
    return 0;
}