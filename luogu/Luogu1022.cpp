// luogu/P1022.cpp
// https://www.luogu.com.cn/problem/P1022
// Created by learntocode1024 on 2020/8/6.
// AC

#include <iostream>
#include <string>

int main() {
    std::string input;
    std::getline(std::cin, input);
    input.append(" ");
    char ch;
    int linear = 0, constant = 0;
    int buf = 0, nega = 0, left = 1, read = 0;
    for (char i: input) {
        if (isdigit(i)) {
            if (read) buf *= 10;
            if (nega) buf -= (i - '0');
            else buf += (i - '0');
            read = 1;
            continue;
        }
        if (read) {
            read = 0;
            nega = 0;
        }
        if (i == '-') {
            nega = 1;
        }
        if (isalpha(i)) {
            ch = i;
            if (!buf && left) buf = 1 - 2*nega;
            if (!buf && !left) buf = -1 + 2*nega;
            if (left) linear += buf;
            else linear -= buf;
            buf = 0;
            continue;
        }
        if (left)
            constant -= buf;
        else constant += buf;
        buf = 0;
        if (i == '=') {
            left = 0;
        }
    }
    std::cout << ch;
    // MIND THIS!!!!!!!!!!
    float ans = (float)constant/(float)linear;
    if (ans == 0) printf("=0.000");
    else printf("=%.3f", ans);
    return 0;
}