// nowcoder_acm/15429.cpp
// https://ac.nowcoder.com/acm/problem/15429
// Created by learntocode1024 on Sep 02 2020.
// AC on Sep 5 2020

#include <cstdio>
#include <algorithm>
#define MX 1000001
// #define LOCAL
typedef long long ll;

int m, n;
ll k;
int a[MX];
int ckans[MX];
short lg[MX];
ll s[MX];
int st[MX][21];

void get_st() {
    for (int i = 1; i <= n; ++i) {
        st[i][0] = std::upper_bound(s + 1, s + n + 1, s[i - 1] + k) - s;
    }
    for (int i = 1; i <= lg[n]; ++i) {
        for (int j = 1; j + (1 << i) <= n; ++j) {
            // st[i][j] = st[st[i][i - 1]][i - 1]; Wrong!!!
            st[j][i] = st[st[j][i - 1]][i - 1];
        }
    }
}

int main() {
    #ifdef LOCAL
    freopen("test.in", "r", stdin);
    freopen("mytest.out", "w", stdout);
    #endif
    /******* pre-processing *******/
    scanf("%d %d %lld", &n, &m, &k);
    for (register int i = 1; i <= n; ++i) {
        scanf("%d", a + i);
        s[i] = s[i - 1] + a[i];
        ckans[i] = ckans[i - 1] + (a[i] > k);
        lg[i] = lg[i - 1] + ((1 << lg[i - 1]) == i);
    }
    get_st();
    /******* answering *******/
    int l, r;
    for (int j = 0; j < m; ++j) {
        scanf("%d %d", &l, &r);
        if (ckans[r] - ckans[l - 1]) printf("Chtholly\n");
        else {
            int ans = 1;
            // solve
            for (int i = 19; i >= 0 && st[l][0] <= r; --i) {
                if (st[l][i] && st[l][i] <= r) {
                    l = st[l][i];
                    ans += (1 << i);
                }
            }
            printf("%d\n", 1);
        }
    }
    return 0;
}