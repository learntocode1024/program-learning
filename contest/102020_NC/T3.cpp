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
int count[27], len;
int T, it;
ULL ans, reg;
string base;
bool flag = true, error = false;

inline void shift(int ch) {
  int add = it;
  while (base[it] - 'a' != ch) {
    it++;
    it %= len;
  }
  ans += ((it - add >= 0) ? it - add : it + len - add);
  ans %= mod;
}

inline void iter() {
  it = (it + 1) % len;
  ++ans;
  ans %= mod;
}

inline void iter(ULL step) {
  it = (int) (it + step % len) % len;
  ans += step;
  ans %= mod;
}

int main() {
  cin >> base;
  len = base.size();
  for (char ch : base) {
    ++count[ch - 'a'];
  }
  count[26] = 1;
  cin >> T;
  getchar();
  while (T--) {
    reg = 0, ans = 0, it = 0, flag = true, error = false;
    int val = getchar() - 'a', curr = 0;
    while (flag) {
      curr = getchar();
      if (isdigit(curr)) { // count
        reg *= 10;
        reg += curr - '0';
        reg %= (mod * count[val]);
        continue;
      }
      if (curr == '\n') flag = false;
      if (curr >= 'a') curr -= 'a';
      else curr = 26;
      if (!count[curr]) { // char not exist
        printf("-1\n");
        error = true;
        break;
      }
      // process
      do {
        if (val == 26) {
          iter(reg ? reg : 1);
          reg = 0;
          break;
        }
        shift(val);
        if (!reg) {
          iter();
          break;
        }
        if (reg > count[val]) {
          if (reg % count[val]) {
            ans += reg / count[val] * len % mod;
            reg %= count[val];
          } else {
            ans += (reg / count[val] - 1) * len % mod;
            reg = count[val];
          }
        }
        iter();
        while (--reg) {
          shift(val);
          iter();
        }
      } while (false);
      // pass
      val = curr;
    }
    if (!error) printf("%lld\n", ans);
  }
  return 0;
}