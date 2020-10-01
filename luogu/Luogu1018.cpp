// luogu/P1018.cpp
// https://www.luogu.com.cn/problem/P1018
// Created by learntocode1024 on Sep 16 2020.
// 

#include <cstdio>
#include <memory.h>
#define MX 45
#define MOD 

void addup (char* a, const char* b) {
    for (int i = 0, reg = 0, curr; i < MX; ++i) {
        curr = *(a + i) + *(b + i) + reg;
        if (!curr) break;
        curr %= 48;
        reg = curr % 10;
        *(a + i) = curr % 10 + '0';
    }
}

char num[MX];
int n, k;
char dp[MX][6][MX];
int main() {
    char a[MX] = {'9', '0'};
    char c[MX] = {'3', '4'};
    addup(a,c);
    printf("%s", a);
    // scanf("%d%d", &n, &k);
    // scanf("%s", num);
    // dp[1][0][0] = num[0] - '0';
    // for (int step = 1; step <= k; ++step) {
    //     for (int curr = 1; curr < n; ++curr) {
            
    //     }
    // }
    return 0;
}