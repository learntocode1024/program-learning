#include "bigint.hpp"

big_int::big_int() { clear(); }

big_int::big_int(const std::string &s) {
  clear();
  extract_string(s);
}

void big_int::clear() {
  flag = false;
  digit = 0;
  std::memset(num, 0, sizeof(num));
}

void big_int::swap(big_int& other) {
  big_int temp = other;
  other = *this;
  *this = temp;
}

void big_int::extract_string(const char* const &ptr) {
  if (ptr[0] == '-')
    flag = true;
  else
    flag = false;
  int reg = 0, cnt = 0;
  digit = 0;
  for (int i = std::strlen(ptr) - 1; i >= 0; --i) {
    int k = (std::isdigit(ptr[i])) ? ptr[i] - '0' : 0;
    reg = reg * 10 + k;
    ++cnt;
    if (cnt == 4) {
      cnt = 0;
      num[digit++] = reg;
      reg = 0;
    }
  }
}

// Operators
big_int &big_int::operator=(const std::string &s) {
  clear();
  extract_string(s.c_str());
  return *this;
}

std::ostream &big_int::operator<<(std::ostream &dest) {

  return dest;
}

void swap(big_int &a, big_int &b) {
  a.swap(b);
}
