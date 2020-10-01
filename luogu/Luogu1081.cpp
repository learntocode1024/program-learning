// luogu/P1081.cpp
// https://www.luogu.com.cn/problem/P1081
// Created by learntocode1024 on Mon Aug 24 2020.
// 

#include <algorithm>
#include <cstdio>
struct node {
    int pos, h, last = -1, next = -1;
    bool operator < (const node &a) const {
        return h < a.h;
    }
    bool operator > (const node &a) const {
        return h > a.h;
    }
    node prec() {
        if (last >= 0) return city[last];
    }
    node succ() {
        if (next >= 0) return city[next];
    }
};

const int MX = 100005;
node city[MX];
int f[MX]; // find by pos
int n;

int main() {
    // Input
    scanf("%d", &n);
    for (int i = 0, h; i != n; scanf("%d", &h), ++i) {
        city[i].pos = i;
        city[i].h = h;
    };
    std::sort(city, city + n - 1);
    for (int i = 0; i != n; ++i) f[city[i].pos] = i;
    for (int i = 0; i != n; ++i) city[i].last = i - 1, city[i].next = i + 1;

    return 0;
}