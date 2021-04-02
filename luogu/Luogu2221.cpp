#include <algorithm>
#include <cstdio>
using std::max;
using std::min;
typedef long long LL;
#define MX 100005
LL n = MX,m;

namespace segtree {
LL s0[MX << 2], s1[MX << 2], s2[MX << 2], ts[MX << 2];

void push_down(const LL &u, LL l, LL r) {
  LL lc = (u << 1), rc = lc + 1; // 1 rooted
  LL mid = l + ((r - l) >> 1);
  LL &t = ts[u];
  s0[lc] += t * (mid - l);
  s1[lc] += t * (mid - l) * (mid + l - 1) / 2;
  s2[lc] +=
      ((mid - 1) * (mid) * (2 * mid - 1) - (l - 1) * (l) * (2 * l - 1)) / 6 * t;
  s0[rc] += t * (r - mid);
  s1[rc] += t * (r - mid) * (r + mid - 1) / 2;
  s2[rc] +=
      ((r - 1) * (r) * (2 * r - 1) - (mid - 1) * (mid) * (2 * mid - 1)) / 6 * t;
  ts[lc] += t;
  ts[rc] += t;
  t = 0;
}

LL __segGet(LL buf[], LL u, LL l, LL r, LL s, LL t) {
  if (l == s && r == t) {
    return buf[u];
  }
  push_down(u, l, r);
  LL lc = (u << 1), rc = lc + 1;
  LL mid = l + ((r - l) >> 1);
  LL ans = 0;
  if (s < mid)
    ans += __segGet(buf, lc, l, mid, s, min(t, mid));
  if (t > mid)
    ans += __segGet(buf, rc, mid, r, max(s, mid), t);
  return ans;
}

void __segMod(LL u, LL l, LL r, LL s, LL t, LL v) {
  if (l == s && r == t) {
    s0[u] += v * (r - l);
    s1[u] += (r - l) * (r + l - 1) / 2 * v;
    s2[u] +=
        ((r - 1) * (r) * (2 * r - 1) - (l - 1) * (l) * (2 * l - 1)) / 6 * v;
    ts[u] += v;
    return;
  }
  push_down(u, l, r);
  LL lc = (u << 1), rc = lc + 1;
  LL mid = l + ((r - l) >> 1);
  if (s < mid)
    __segMod(lc, l, mid, s, min(t, mid), v);
  if (t > mid)
    __segMod(rc, mid, r, max(s, mid), t, v);
  s0[u] = s0[lc] + s0[rc];
  s1[u] = s1[lc] + s1[rc];
  s2[u] = s2[lc] + s2[rc];
}

LL Get(LL l, LL r) {
  LL v0 = __segGet(s0, 1, 1, n, l, r);
  LL v1 = __segGet(s1, 1, 1, n, l, r);
  LL v2 = __segGet(s2, 1, 1, n, l, r);
  return (r - l * r) * v0 + (r + l - 1) * v1 - v2;
}

inline void Add(LL l, LL r, LL val) { return __segMod(1, 1, n, l, r, val); }

} // namespace segtree

inline LL gcd(LL a, LL b) {
  while ((a %= b) && (b %= a))
    ;
  return a + b;
}

int main() {
  scanf("%lld%lld", &n, &m);
  char op;
  LL l, r;
  LL v;
  for (LL i = 0; i < m; ++i) {
    scanf("%s%lld%lld", &op, &l, &r);
    if (op == 'C') {
      scanf("%lld", &v);
      segtree::Add(l, r, v);
    } else {
      LL a = segtree::Get(l, r);
      LL b = (r - l) * (r - l + 1) / 2;
      LL c = gcd(a, b);
      printf("%lld/%lld\n", a / c, b / c);
    }
  }
  return 0;
}
