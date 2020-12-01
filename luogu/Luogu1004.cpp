// luogu/P1004.cpp
// https://www.luogu.com.cn/problem/P1004
// Created by learntocode1024 on Sat Aug 22 2020.
// AC
#include <cstdio>
#include <iostream>
using namespace std;
int mapping[9][9];
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
        if (a) mapping[a - 1][b - 1] = c;
        else break;
    }
  for (int step = 1; step < (N << 1); ++step) {

  }
    int ans = s[N - 1][N - 1][(N - 1) << 1]; 
    printf("%d", ans);
    return 0;
}
