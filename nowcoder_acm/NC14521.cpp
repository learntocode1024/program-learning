// nowcoder_acm/14521/local.cpp
// https://ac.nowcoder.com/acm/problem/14521
// Created by learntocode1024 on Sep 09 2020.
// AC on Sep 10 2020
#include <stdio.h>
#include <queue>
#include <memory.h>
#define MX 10
using std::queue;

int n, m, q;
int adj[MX*2], iter = 0;
int next[MX*2];
int head[MX];
int dist[MX];
bool vis[MX];

inline void add_edge(const int &to, const int &fr) {
    adj[++iter] = fr;
    next[iter] = head[to];
    head[to] = iter;
}

int main() {
    // input
    scanf("%d %d %d", &n, &m, &q);
    int fi, to;
    while (m--) {
        scanf("%d %d", &fi, &to);
        add_edge(fi, to);
        add_edge(to, fi);
    }
    // delete &fi;
    // delete &to;
    while(q--) {
        int t, s;
        scanf("%d %d", &t, &s);
        memset(dist, s + 1, sizeof(dist));
        memset(vis, 0, sizeof(vis));
        int temp, ans = 0;
        queue<int> q;
        while (t--) {
            scanf("%d", &temp);
            q.push(temp);
            dist[temp] = 0;
            vis[temp] = true;
        }
        while (q.size()) {
            int curr = q.front();
            q.pop();
            for (int i = head[curr]; i != 0; i = next[i]) {
                if (!vis[adj[i]]) {
                    dist[adj[i]] = dist[curr] + 1;
                    vis[adj[i]] = true;
                    q.push(adj[i]);
                }
            }
        }
        for (int i = 0; i <= n; ++i) {
            if (dist[i] <= s) ans++;
        }
        printf("%d\n", ans);
    }
    return 0;
}