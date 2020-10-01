// luogu/P1083.cpp
// https://www.luogu.com.cn/problem/P1083
// Created by learntocode1024 on Mon Aug 24 2020.
// AC on Aug 25 2020

#include <cstdio>
#include <cstring>

const int MX = 1e6 +11;
int m, n;
int diff[MX];
int temp[MX];
int d[MX];
int s[MX];
int t[MX];

int main() {
    scanf("%d %d",&n, &m);
    for (int i = 0, curr = 0, last = 0; i != n; ++i) {
        scanf("%d", &curr);
        diff[i] = curr - last;
        last = curr;
    }
    for (int i = 0, currd, currs, currt; i != m; ++i) {
        scanf("%d %d %d", &currd, &currs, &currt);
        d[i] = currd;
        s[i] = currs - 1;
        // t[i] = currt - 1;
        t[i] = currt; // mind this!!
    }
    int beg = 0,end = m - 1, mid;
    while (beg != end) {
        mid = (beg + end) / 2;
        memset(temp, 0, sizeof(temp));
        // judge if mid
        for (int i = 0; i <= mid; ++i) {
            mid = (beg + end) / 2;
            temp[s[i]] -= d[i];
            temp[t[i]] += d[i];
        }
        bool judge = true;
        for (int i = 0, curr = 0; i <= n; ++i) {
            curr += (diff[i] + temp[i]);
            if (curr < 0) {
                judge = false;
                break;
            }
        }
        if (judge) beg = mid + 1;
        else end = mid;
    }
    ++beg;
    if (beg == m) printf("0");
    else printf("-1\n%d", beg);
    return 0;
}