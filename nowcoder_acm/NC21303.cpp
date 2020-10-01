// nowcoder_oi_advance/21303/local.cpp
// https://ac.nowcoder.com/acm/problem/21303
// Created by learntocode1024 on Sep 11 2020.
// 
#include <iostream>
#include <memory.h>
#include <string>
#define MX 100
#define new_node &pool[++iter]
using std::string;
using std::cin;
using std::cout;
bool dp[MX][MX];

int main() {
    // set iostream status
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    // input
    string s, t;
    getline(cin, s);
    getline(cin, t);
    memset(dp, 0, sizeof(dp));
    if (s[0] == t[0]) dp[0][0] = true;
    else {
        printf("Impossible");
        return 0;
    }
    for (int dp_t = 0; dp_t != t.size(); ++dp_t) {
        for (int dp_s = 0; dp_s != s.size(); ++dp_s) {
            
        }
    }
    printf("Possible");
    printf("Impossible");
    return 0;
}