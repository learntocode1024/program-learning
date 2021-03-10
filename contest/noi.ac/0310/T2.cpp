#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
#define MX 100005
#define MAX_K 15

int k, n, q;
int c[MAX_K][MX];
int stat[MX][MAX_K][MAX_K];

void init() {
  ios::sync_with_stdio(false); lo
  cin.tie(NULL);
  cin >> n >> k >> q;
  for (int i = 1; i <= k; ++i) {
    for (int j = 1; j < k; ++j)
      cin >> c[i][j];
  }

}

int main() {
  init();
  return 0;
}
