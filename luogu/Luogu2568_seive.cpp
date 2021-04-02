// luogu/Luogu2568_seive.cpp
// Author: misaka18931
// Date: Apr  2, 2021
// tag: prime seive

#include <cstdio>
#define MX 10000005
int n;
int prime[MX], vis[MX], cnt;
long long phi[MX];
long long ans;

void seive() {
  phi[1] = 1;
  for (int i = 2; i <= n; ++i) {
    if (!vis[i]) { // prime detected
      prime[++cnt] = i;
      vis[i] = cnt;
      phi[i] = i - 1;
    }
    for (int j = 1; j <= vis[i]; ++j) { // travial all primes
      if (prime[j] * i > n) break;
      vis[prime[j] * i] = j;
      phi[prime[j] * i] = phi[i];
      if (j < vis[i]) phi[prime[j] * i] *= (prime[j] - 1);
      else phi[prime[j] * i] *= prime[j];
    }
  }
}

void calc() {
  for (int i = 2; i <= n; ++i)
    phi[i] += phi[i - 1];
  for (int i = 1; i <= cnt; ++i)
    ans += phi[n / prime[i]];
}

int main() {
  scanf("%d", &n);
  seive();
  calc();
  printf("%lld\n", ans * 2 - cnt);
  return 0;
}
