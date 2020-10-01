// luogu/P1015.cpp
// https://www.luogu.com.cn/problem/P1015
// Created by learntocode1024 on 2020/8/6.
// AC

#include <cstring>
#include <string>
#include <iostream>

std::string hex = "0123456789ABCDEF";

int N;
int A[120];

int main() {
    std::string in;
    std::cin >> N >> in;
    int ln = in.length();
    for (int i = 0; i < ln; ++i) {
        A[i] = hex.find(in[i]);
    }
    int cnt = 1;
    while (cnt <= 30) {
        // add
        for (int i = 0; i < (ln + 1)/2; ++i) {
            A[i] += A[ln - i - 1];
            A[ln - i - 1] = A[i];
        }
        // indent
        int reg = 0;
        for (int j = 0; j < ln; ++j) {
            if ((A[j] + reg) >= N) {
                A[j] += (reg - N);
                reg = 1;
            } else {
                A[j] += reg;
                reg = 0;
            }
        }
        if (reg == 1) {
            ++A[ln];
            ++ln;
        }
        int flag = 0;
        for (int i = 0; i < (1 + ln)/2; ++i) {
            if (A[ln - i - 1] != A[i]) {
                flag = 1;
                break;
            }
        }
        if (flag == 0) {
            std::cout << "STEP=" << cnt;
            return 0;
        }
        ++cnt;
    }
    std::cout << "Impossible!";
    return 0;
}