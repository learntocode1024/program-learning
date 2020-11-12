#include <iostream>
#define MX 10 //0005
using std::cin;
using std::cout;
const int mod = 998244353;
int val[MX], add[MX], mul = 1;
int n, m;

int head[MX], end[MX], to[MX], nxt[MX], tot;
int pos[MX], op[MX];

void insert(int a, int b) {
  if (!head[a]) {
    head[a] = ++tot;
    to[tot] = b;
    end[a] = tot;
    return;
  }
  nxt[end[a]] = ++tot;
  end[a] = tot;
  to[tot] = b;
}

int q_pow(int a, int index) {
  int ans = 1;
  while (index) {
    if (index & 1) ans = ans * a % mod;
    a = a * a % mod;
    index >>= 1;
  }
  return ans;
}

void call(int curr) {
  if (!head[curr]) {
    if (pos[curr]) { // op 1
      add[pos[curr]] = (add[pos[curr]] + q_pow(mul, mod - 2)) % mod;
    } else { // op 2
      mul = mul * op[curr] % mod;
    }
  } else { // op 3
    for (int kI = head[curr]; kI; kI = nxt[kI]) {
      call(to[kI]);
    }
  }
}

int main() {
  cin >> n;
  for (int kI = 1; kI <= n; ++kI) {
    cin >> val[kI];
  }
  cin >> m;
  for (int kI = 1, type, x, y; kI <=m; ++kI) {
    cin >> type;
    if (type == 3) {
      cin >> x;
      while (x--) {
        cin >> y;
        insert(kI, y);
      }
    } else {
      if (type == 1) cin >> pos[kI];
      cin >> op[kI];
    }
  }
  int Q, cmd;
  cin >> Q;
  while (Q--) {
    cin >> cmd;
    call(cmd);
  }
  for (int kI = 1; kI <= n; ++kI) {
    cout << (val[kI] + add[kI]) * mul % mod << " ";
  }
  cout << std::endl;
  return 0;
}