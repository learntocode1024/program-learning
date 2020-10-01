// luogu/P2239.cpp
// https://www.luogu.com.cn/problem/P2239
// Created by learntocode1024 on 2020/8/6.
// AC

#include <iostream>

int n, i, j;
int var;
int pos[4];
int jump[4] = {3, 0, 1, 2};

int main() {
    std::cin >> n >> i >> j;
    // get position
    pos[0] = i;
    pos[1] = n - j + 1;
    pos[2] = n - i + 1;
    pos[3] = j;
    // process
    int side = 0, layer = i;
    for (int k = 1; k < 4; ++k) {
        if (pos[k] < layer) {
            layer = pos[k];
            side = k;
        }
    }
    layer--;
    var = 4 * (n - layer) * layer;
    int sub_n = n - 2 * layer - 1;
    var = var + side * sub_n + pos[jump[side]] - layer;
    std::cout << var;
    return 0;
}