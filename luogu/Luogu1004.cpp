// luogu/P1004.cpp
// https://www.luogu.com.cn/problem/P1004
// Created by learntocode1024 on Sat Aug 22 2020.
// 
#include <cstdio>
#include <iostream>
using namespace std;
int map[9][9];
//    x1 x2 step
int s[20][20][40];
int N;

int max(int a, int b, int c, int d) {
    if (b > a) a = b;
    if (c > a) a = c;
    if (d > a) a = d;
    return a;    
}

int main() {
    scanf("%d", &N);
    int a, b, c;
    while (scanf("%d %d %d", &a, &b, &c)) {
        if (a + b + c) map[a - 1][b - 1] = c;
        else break;
    }
    s[0][0][0] = map[0][0];
    s[1][0][1]=map[1][1];
    for (int step = 1; step < (N << 1) - 1; ++step) {
        for (int x1 = 1; x1 < N && x1 <= step; ++x1) {
            for (int x2 = 1; x2 < N && x2 <= step; ++x2) {
                s[x1][x2][step] = map[x1][step - x1] + map[x2][step - x2]
                                + max(s[x1 - 1][x2][step - 1],
                                      s[x1][x2 - 1][step - 1],
                                      s[x1][x2][step - 1],
                                      s[x1 - 1][x2 - 1][step - 1]);
                if (x1 == x2)
                    s[x1][x2][step] -= map[x1][step - x1];
            }
        } 
    }

    int ans = s[N - 1][N - 1][(N - 1) << 1]; 
    printf("%d", ans);
    return 0;
}