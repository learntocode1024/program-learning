// luogu/LuoguSP1110.cpp
// https://www.luogu.com.cn/problem/SP1110
// Created by learntocode1024 on 11/06/20.
// 

#include <iostream>

char map[16][16];
int aval[16][16];

void fill(unsigned x, unsigned y, unsigned val) {
  if (! aval[x][y] & (1 << val)) return;
  for (int kI = 0; kI < 16; ++kI) {
    aval[x][kI] -= (1 << val);
    aval[kI][y] -= (1 << val);
  }
  for (int kI = 0; kI < 4; ++kI) {
    for (int kJ = 0; kJ < 4; ++kJ) {
      aval[x/4*4 + kI][y/4*4 + kJ] -= (1 << val);
    }
  }
}

void input() {
  for (int kI = 0; kI < 16; ++kI) {
    for (int kJ = 0; kJ < 16; ++kJ) {
      aval[kI][kJ] = (1 << 16) - 1;
    }
  }
  for (int kI = 0; kI < 16; ++kI) {
    for (int kJ = 0; kJ < 16; ++kJ) {
      aval[kI][kJ] = (1 << 16) - 1;
    }
  }
}

int main() {
  
  return 0;
}
