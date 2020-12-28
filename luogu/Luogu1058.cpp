// luogu/P1058.cpp
// https://www.luogu.com.cn/problem/P1058
// Created by learntocode1024 on 2020/8/7.
// AC

#include <iostream>
#include <cstring>
using namespace std;

int m, n;
char graph[305][405];
int src[55][55];
int x_lim, y_lim, x_0, y_0;
char base[6][8] = {
  "+---+..",
  "|   |/.",
  "|   | +",
  "+---+ |",
  "./   /|",
  "..+---+"
};

void draw_obj(int x, int y) {
  for (int i = 0; i < 6; ++i) {
    for (int j = 0; j < 7; ++j) {
      if (base[i][j] != '.') graph[x - i][y + j] = base[i][j];
    }
  }
}

void draw(int layer) {
  int x0 = x_0 + 2 * layer;
  int y0 = y_0 - 2 * layer;
  for (int i = 0; i < n; ++i) {
    int y1 = y0 + i * 4;
    for (int j = 0; j < src[layer][i]; ++j) {
      int x1 = x0 - 3 * j;
      draw_obj(x1, y1);
    }
  }
}

void print() {
  for (int i = 0; i < x_lim; ++i) {
    for (int j = 0; j < y_lim; ++j) {
      cout << graph[i][j];
    }
    cout << endl;
  }
  cout << endl;
}

int main() {
  cin >> m >> n;
  y_lim = m * 2 + n * 4 + 1;
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> src[i][j];
      x_lim = max(x_lim, 3 * (src[i][j] + 1) + (m - i - 1) * 2);
    }
  }
  y_0 = m * 2 - 2;
  x_0 = x_lim - y_0 - 1;
  for (int i = 0; i < x_lim; ++i) {
    for (int j = 0; j < y_lim; ++j) {
      graph[i][j] = '.';
    }
  }
  for (int i = 0; i < m; ++i) {
    draw(i);
  }
  print();
  return 0;
}