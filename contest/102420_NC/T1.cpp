#include <cstdio>

int T;
unsigned char encode[26];
bool is_np[100001];

int main() {
  scanf("%d", &T);
  is_np[0] = true;
  while (T--) {
    for (int kI = 0; kI != 26; scanf("%hhu", encode + kI), ++kI);
    getchar();
    unsigned char curr;
    int tot = 0;
    while ((curr = getchar()) != '\n') {

    }
  }
  return 0;
}