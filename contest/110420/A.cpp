#include <iostream>
#include <random>
std::random_device rd;
std::uniform_int_distribution
using std::cout;

int mx = 100000;
int fac[4], tot, sum;
int next = 0;

int main() {
  for (int kI = 6; kI <= mx; ++ kI) {
    tot = 0, sum = 0;
    for (int kJ = 1; kJ <= kI && tot < 4; ++ kJ) {
      if (kI%kJ == 0) {fac[tot++] = kJ;
      sum += (kJ * kJ);}
    }
    if (sum == kI) printf("%d %d %d %d %d\n", fac[0], fac[1], fac[2], fac[3], kI);
  }
  return 0;
}