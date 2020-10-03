// luogu/Luogu1005.cpp
// https://www.luogu.com.cn/problem/P1005
// Created by learntocode1024 on 10/03/20.
// AC on Oct 3 2020

#include <iostream>
#include <memory.h>
#include <algorithm>
#define MX 6
using std::cin;
using std::cout;
using std::max;

std::ostream&
operator<<( std::ostream& dest, __int128_t value )
{
  std::ostream::sentry s( dest );
  if ( s ) {
    __uint128_t tmp = value < 0 ? -value : value;
    char buffer[ 128 ];
    char* d = std::end( buffer );
    do
    {
      -- d;
      *d = "0123456789"[ tmp % 10 ];
      tmp /= 10;
    } while ( tmp != 0 );
    if ( value < 0 ) {
      -- d;
      *d = '-';
    }
    int len = std::end( buffer ) - d;
    if ( dest.rdbuf()->sputn( d, len ) != len ) {
      dest.setstate( std::ios_base::badbit );
    }
  }
  return dest;
}

int m, n;
__int128_t ans;
__int128_t dp[MX][MX];

int main() {
  cin >> n >> m;
  for (int kI = 0; kI < n; ++kI) {
    memset(dp, 0, sizeof(dp));
    for (int kJ = 0; kJ < m; ++kJ) {
      int tmp;
      cin >> tmp;
      dp[kJ][1] = tmp << 1;
    }
    for (int step = 2; step <= m; ++step) {
      for (int beg = 0; beg < m - 1; ++beg) {
        if (step + beg > m) continue;
        dp[beg][step] = (dp[beg][step - 1] << 1) + dp[beg + step - 1][1];
        dp[beg][step] = max(dp[beg][step], (dp[beg + 1][step - 1] << 1) + dp[beg][1]);
        // This is not the same thing as  dp[beg + step - 1][1] > dp[beg][1]!!
        // always be careful
      }
    }
    ans += dp[0][m];
  }
  cout << ans;
  return 0;
}