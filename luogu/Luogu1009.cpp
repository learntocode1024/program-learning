// luogu/P1009.cpp
// https://www.luogu.com.cn/problem/P1009
// Created by learntocode1024 on 2020/8/6.
//

#include <string>
#include <cstring>

class big_int {
  #define MX 100
  unsigned num[MX];
  unsigned digit;
  bool flag;
  void extract_string(const std::string& s) {
    if (s[0] == '-') flag = true;
    else flag = false;
    int reg = 0, cnt = 0;
    digit = 0;
    for (int i = s.size() - 1; i >= 0; --i) {
      int k = (std::isdigit(s[i]))? s[i] - '0': 0;
      reg = reg * 10 + k; ++cnt;
      if (cnt == 4) {
        cnt = 0;
        num[digit++] = reg;
        reg = 0;
      }
    }
  }
public:
  big_int(const std::string& s) {
    clear();
    extract_string(s);
  }
  
  big_int() {
    clear();
  }
  big_int& operator= (const std::string& s) {
    clear();
    extract_string(s);
    return *this;
  }
  big_int& operator= (big_int& other) {
    if (this != &other) {
      
    }
    return *this;
  }
  void clear() {
    flag = false;
    digit = 0;
    std::memset(num, 0, sizeof(num));
  }
};

int main() {

    return 0;
}