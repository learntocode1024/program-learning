// contest/noi.ac/0315/T1.cpp

#include <cstdio>
#include <iostream>
using namespace std;
typedef long long LL;
const LL mod = 998244353ll;

LL q_pow(LL a, int b) {
  LL ans = 1;
  while (b) {
    if (b & 1) ans = ans * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return ans;
}

int n, m, a, b;

int main() {
  int T;
  cin >> T;
  while (T--) {
    cin >> n >> m >> a >> b;
    
  }
  return 0;
}