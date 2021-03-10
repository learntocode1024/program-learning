
 // Author: misaka18931
// Date: Feb 17, 2021
// https://loj.ac/p/135
// tag: data-structure, binary-indexed-tree(2D)
//

#include <cstdio>
#include <vector>
using namespace std;
typedef long long ll;
#define lowbit(X) ((X) & (~(X) + 1))
#define MX 4100

ll n, m;
ll a1[MX][MX], a3[MX][MX], a2[MX][MX], a4[MX][MX];

void add(ll x, ll y, ll val) {
  ll y1 = y, x1 = x;
  while (x <= n) {
    y = y1;
    while (y <= m) {
      a1[x][y] += val;
      a3[x][y] += val * y1;
      a2[x][y] += val * x1;
      a4[x][y] += val * x1 * y1;
      y += lowbit(y);
    }
    x += lowbit(x);
  }
}
ll ask(ll a[][MX], ll x, ll y) {
  ll sum = 0;
  while (x) {
    ll y1 = y;
    while (y1) {
      sum += a[x][y1];
      y1 -= lowbit(y1);
    }
    x -= lowbit(x);
  }
  return sum;
}
ll getsum(ll x, ll y) {
  return (x + 1) * (y + 1) * ask(a1, x, y) - (x + 1) * ask(a3, x, y) -
         (y + 1) * ask(a2, x, y) + ask(a4, x, y);
}
long long asksum(ll x1, ll y1, ll x2, ll y2) {
  return getsum(x2, y2) + getsum(x1 - 1, y1 - 1) - getsum(x2, y1 - 1) -
         getsum(x1 - 1, y2);
}
ll get(ll buf[][MX], ll x, ll y) {
  ll ans = 0;
  ll y1 = y;
  while (x) {
    y = y1;
    while (y) {
      ans += buf[x][y];
      y -= lowbit(y);
    }
    x -= lowbit(x);
  }
  return ans;
}

ll get(ll x, ll y) {
  ll ans = 0;
  ans += (x + 1) * (y + 1) * get(a1, x, y);
  ans -= (y + 1) * get(a3, x, y);
  ans -= (x + 1) * get(a2, x, y);
  ans += get(a4, x, y);
  return ans;
}

int main() {
  scanf("%lld%lld", &n, &m);
  // a1 = a3 = a2 = a4 = vector<vector<ll> >(n + 10, vector<ll>(m + 10, 0));
  ll op, x1, y1, x2, y2;
  ll k;
  while (scanf("%lld%lld%lld%lld%lld", &op, &x1, &y1, &x2, &y2) != EOF) {
    if (op == 1) {
      scanf("%lld", &k);
      add(x2+1,y2+1,k);
      add(x1,y1,k),add(x1,y2+1,-k),add(x2+1,y1,-k);
    } else {
      --x1, --y1;
      ll ans = get(x2, y2) - get(x1, y2) - get(x2, y1) + get(x1, y1);
      printf("%lld\n", asksum(x1, y1, x2, y2));
    }
  }
  return 0;
}
