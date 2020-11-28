// luogu/LuoguU133018.cpp
// https://www.luogu.com.cn/problem/U133018
// Created by learntocode1024 on 11/28/20.
// 

#include <cstdio>
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
typedef long long LL;
LL mod = 1000000007;

void fastscan(LL &number) 
{ 
    //variable to indicate sign of input number 
    bool negative = false; 
    register LL c; 
  
    number = 0; 
  
    // extract current character from buffer 
    c = getchar(); 
    if (c=='-') 
    { 
        // number is negative 
        negative = true; 
  
        // extract the next character from the buffer 
        c = getchar(); 
    } 
  
    // Keep on extracting characters if they are integers 
    // i.e ASCII Value lies from '0'(48) to '9' (57) 
    for (; (c>47 && c<58); c=getchar()) 
        number = number *10 + c - 48; 
  
    // if scanned input has a negative sign, negate the 
    // value of the input number 
    if (negative) 
        number *= -1; 
} 

LL q_pow(LL base, LL index) {
  LL ans = 1;
  while (index) {
    if (index & 1) ans = ans * base % mod;
    base = base * base % mod;
    index >>= 1;
  }
  return ans;
}

void solve() {
  LL a, b, h, ans;
  fastscan(a);
  fastscan(b);
  fastscan(h);
  if (h == 0) {
    cout << a << endl;
    return;
  }
  LL tmp = q_pow(b, h);
  if (a < b) {
    ans = tmp * a % mod;
  } else {
    ans = tmp * a % mod;
    if (a != b) {
      if (b == 1) ans = (ans + h * (a - 1)) % mod;
      else ans = (ans + (tmp - 1) * q_pow(b - 1, mod - 2) % mod * (a - b)) % mod;
    }
  }
  cout << ans << endl;
}

int main() {
  LL T = 1;
  fastscan(T);
  while (T--) {
    solve();
  }
  return 0;
}
