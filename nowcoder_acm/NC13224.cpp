// nowcoder_acm/13224/local.cpp
// https://ac.nowcoder.com/acm/problem/13224
// Created by learntocode1024 on Sep 08 2020.
// AC on Sep 09 2020
#include <cstdio>
#include <queue>
#include <cstring>
#include <string>
#include <algorithm>
#define MX 10
#define inf 0x3F3F3F3F
using std::string;
using std::queue;

int n;
int iter;
int adj[MX*2];
int next[MX*2];
int head[MX];
char route[MX];
int a[MX];
int b[MX];
bool visit[MX] = {0}; // reachable cities
bool ckring[MX] = {0};
bool ring = false;
queue<int> q;

inline void add_edge(const int &fr, const int &to) {
    adj[++iter] = fr;
    next[iter] = head[to];
    head[to] = iter;
}

void bfs() {
    q.push(n - 1);
    visit[n - 1] = true;
    while (q.size()) {
        int curr = q.front(); q.pop();
        // scan current list
        for (int i = head[curr]; adj[i] != -1; i = next[i]) {
            if (visit[adj[i]]) continue;
            visit[adj[i]] = true;
            q.push(adj[i]);
        }
    }
}

int main() {
    // input
    adj[0] = -1; // guard val
    int temp;
    scanf("%d", &n);
    for (register int i = 0; i < n; ++i) {
        scanf("%d", &temp), temp += i;
        if (temp < n && temp >= 0) {
            add_edge(i, temp);
            a[i] = temp;
        }
        else a[i] = -1;
    }
    for (register int i = 0; i < n; ++i) {
        scanf("%d", &temp), temp += i;
        if (temp < n && temp >= 0) {
            add_edge(i, temp);
            b[i] = temp;
        }
        else b[i] = -1;
    }
    // Solution
    bfs();
    if (visit[0]) {
        int step = -1;
        int i = 0;
        while (!ring && i != n - 1) {
            if (a[i] != -1 && visit[a[i]]) {
                if (!ckring[a[i]]) {
                    route[++step] = 'a';
                    ckring[a[i]] = true;
                    i = a[i];
                    continue;
                } else ring = true;
            } else {
                if (b[i] != -1 && visit[b[i]]) {
                    if (!ckring[b[i]]) {
                        route[++step] = 'b';
                        ckring[b[i]] = true;
                        i = b[i];
                        continue;
                    } else ring = true;
                }
            }
        }
        if (ring) printf("Infinity!");
        else printf("%s", route);
    } else printf("No solution!");
    return 0;
}