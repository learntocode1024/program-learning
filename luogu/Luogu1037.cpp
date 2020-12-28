// luogu/P1037.cpp
// https://www.luogu.com.cn/problem/P1037
// Created by learntocode1024 on 2020/8/3.

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sys/types.h>
using namespace std;
int cnt[10];
vector<int> rule[10];

int main() {
    string s;
    int T;
    for (int i = 0; i < 10; ++i) cnt[i] = 1;
    cin >> s >> T;
    __int64_t ans = 1;
    while (T--) {
        int a, b;
        cin >> a >> b;
        if (find(rule[a].begin(), rule[a].end(), b) == rule[a].end()) {
            rule[a].push_back(b);
        }
    }
    for (__uint32_t i = 0; i < s.size(); ++i) {
      ans *= cnt[s[i] - '0'];
    }
    cout << ans << endl;
    return 0;
}