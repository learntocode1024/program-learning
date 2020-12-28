#ifndef BIGINT_HPP
#define BIGINT_HPP

#include <cstring>
#include <string>

#define BIGINT_MAX_VAL 100u
class big_int {
  unsigned num[BIGINT_MAX_VAL];
  unsigned digit;
  bool flag;
  void extract_string(const char *const &ptr);

public:
  big_int(const std::string &s);
  big_int(char* const ptr);
  big_int(__uint64_t num);
  big_int(__int64_t num);
  big_int();
  std::ostream &operator<<(std::ostream &dest);
  big_int &operator=(const std::string &s);
  void clear();
  void swap(big_int &other);
  friend void swap(big_int &a, big_int &b);
};
#endif