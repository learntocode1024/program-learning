// contest/noi.ac/0317/T1.cpp
// Date: Mar 17, 2021

#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;
typedef long long LL;

int num[200005];
int* endnum;
int a[100005];
char type[100005];
int var1[100005], var2[100005];

inline int get_id(int x) {
  return lower_bound(num, endnum, x) - num;
}

int n, m, T;
LL sum[400];
LL cross[400];
int cnt[400][200005];

int main() {
  scanf("%d%d", &n, &m);
  T = ceil(sqrt(n));
  for (int i = 0; i < n; ++i)
    scanf("%d", a + i), num[i] = a[i];
  int tot = n;
  for (int i = 0; i < m; ++i) {
    scanf("%c%d%d", type + i, var1 + i, var2 + i);
    if (type[i] == 'R') num[tot++] = var2[i];
  }
  // end input
  sort(num, num + tot - 1);
  endnum = unique(num, num + tot - 1);
  // end int distribution
  for (int i = 0, curr = 0; i < n; ++i) {
    int id = get_id(a[i]);
    ++cnt[curr][id];
    curr += ((i + 1) % T == 0);
  }

  return 0;
}