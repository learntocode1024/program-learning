// nowcoder_contest/102020_NC/T2.cpp
// https://ac.nowcoder.com/acm/contest/
// Created by learntocode1024 on 10/20/20.
// AC on 10/20/20
#include <cstdio>
#include <cctype>
#include <iostream>
#include <string>
#define MX 1000001
using std::string;
using std::cin;
using std::cout;
typedef unsigned long long ULL;
const int mod = 998244353;
int count[26], len;
int T, it, curr;
ULL ans, reg;
string base;
string match;

inline void shift() {
  int add = it;
  while (base[it] - 'a' != curr) {
    it++;
    it %= len;
  }
  ans += ((it - add >= 0)? it - add : it + len - add);
}

inline void iter() {
  it = (it + 1)%len; ++ans;
}

inline void iter(ULL step) {
  it = (int)(it + step%len)%len; ans += step;
}

int main() {
  cin >> base;
  len = base.size();
  for (char ch : base) {
    ++count[ch - 'a'];
  }
  cin >> T;
  while (T--) {
    reg = 0, ans = 0, it = 0, curr = -1;
    cin >> match;
    match += "n"; // nil
    for (char ch : match) {
      if (!isdigit(ch)) {
        if (curr == -55) {
          if (reg) iter(reg), reg = 0;
          else iter();
          curr = ch - 'a';
          continue;
        }
        if (curr >= 0) { // process
          if (!count[curr]) {
            printf("-1\n");
            break;
          }
          shift();
          if (!reg) {
            iter();
            curr = ch - 'a';
            continue;
          }
          long long times = reg/count[curr] - 1;
          if (times > 0) {
            ans += times * len % mod;
            reg -= times * count[curr];
          }
          while (reg) {
            iter();
            shift();
            reg--;
          }
        }
        curr = ch - 'a';
      } else { // count
        reg = (reg << 1) + (reg << 3);
        reg += ch - '0';
      }
    }
    printf("%lld\n", ans);
  }
  return 0;
}