// luogu/Luogu3820.cpp
// https://www.luogu.com.cn/problem/P3820
// Created by learntocode1024 on 10/30/20.
//

#include <iostream>
#include <queue>
#define MX 1000100
bool is_dirt[MX]{0};
int cc[MX];
int cc_id[MX];
int n, m;

std::queue<int> Q;
void get_cc(int beg)
{ // BFS
  cc_id[beg] = beg;
  cc[beg]++;
  Q.push(beg);
  int curr;
  while (!Q.empty())
  {
    curr = Q.front();
    Q.pop();
    if (curr >= m && !is_dirt[curr - m] && !cc_id[curr - m])
    { // up
      Q.push(curr - m);
      cc_id[curr - m] = curr;
      cc[beg]++;
    }
    if (curr < m * (n - 1) && !is_dirt[curr + m] && !cc_id[curr + m])
    { // down
      Q.push(curr + m);
      cc_id[curr + m] = curr;
      cc[beg]++;
    }
    if (curr % m && !is_dirt[curr - 1] && !cc_id[curr - 1])
    { // left
      Q.push(curr - 1);
      cc_id[curr - 1] = curr;
      cc[beg]++;
    }
    if ((curr + 1) % m && !is_dirt[curr + 1] && !cc_id[curr + 1])
    { // right
      Q.push(curr + 1);
      cc_id[curr + 1] = curr;
      cc[beg]++;
    }
  }
}

int get(int curr)
{
  if (is_dirt[cc_id[curr]])
    cc_id[curr] = curr;
  if (cc_id[curr] != curr)
    cc_id[curr] = get(cc_id[curr]);
  return cc_id[curr];
}

void add(int curr)
{
  is_dirt[curr] = false;
  if (curr >= m && !is_dirt[curr - m])
  { // up
    cc_id[curr] = get(curr - m);
    ++cc[get(curr - m)];
  }
  if (curr < m * (n - 1) && !is_dirt[curr + m])
  { // down
    if (cc_id[curr] == 0)
      cc_id[curr] = get(curr + m), ++cc[get(curr + m)];
    if (get(curr) != get(curr + m))
    {
      cc_id[get(curr + m)] = get(curr);
      cc[get(curr)] += cc[get(curr + m)];
      cc[get(curr + m)] = 0;
    }
  }
  if (curr % m && !is_dirt[curr - 1])
  { // left
    if (cc_id[curr] == 0)
      cc_id[curr] = get(curr - 1), ++cc[get(curr - 1)];
    if (get(curr) != get(curr - 1))
    {
      cc_id[get(curr - 1)] = get(curr);
      cc[get(curr)] += cc[get(curr - 1)];
      cc[get(curr - 1)] = 0;
    }
  }
  if ((curr + 1) % m && !is_dirt[curr + 1])
  { // right
    if (cc_id[curr] == 0)
      cc_id[curr] = get(curr + 1), ++cc[get(curr + 1)];
    if (get(curr) != get(curr + 1))
    {
      cc_id[get(curr + 1)] = get(curr);
      cc[get(curr)] += cc[get(curr + 1)];
      cc[get(curr + 1)] = 0;
    }
  }
}

void del(int curr)
{
  is_dirt[curr] = true;
  cc[get(curr)]--;
  cc_id[curr] = 0;
}

int main()
{
  std::cin >> n >> m;
  char buf;
  for (int kI = 0; kI < n * m; ++kI)
  {
    printf("%d", kI);
    std::cin >> buf;
    if (buf == '*')
      is_dirt[kI] = true;
  }
  for (int kI = 0; kI < n * m; ++kI)
  {

    if (!is_dirt[kI] && !cc_id[kI])
      get_cc(kI);
  }
  int T;
  std::cin >> T;
  int op, num, curr, x, y;
  while (T--)
  {
    std::cin >> op >> num;
    if (op == 1)
    {
      int ans, cnt = 1, max = 0;
      while (num--)
      {
        std::cin >> x >> y;
        curr = x * (m - 1) + y - 1;
        if (cc[get(curr)] > max)
        {
          max = cc[get(curr)];
          ans = cnt;
        }
        ++cnt;
      }
      printf("%d\n", ans);
    }
    else
    {
      while (num--)
      {
        std::cin >> x >> y;
        curr = x * (m - 1) + y - 1;
        if (is_dirt[curr])
          add(curr);
        else
          del(curr);
      }
    }
  }
  return 0;
}
