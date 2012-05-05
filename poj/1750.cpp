#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;

int main(void) {
  int count = 1;
  char prev[16];
  scanf("%s", prev);
  puts(prev);

  char s[16];
  while (scanf("%s", s) == 1) {
    for (int i = 0; i < count; i++) {
      if (prev[i] == s[i]) {
        if (prev[i] == '\0') break;
        putchar(' ');
      } else {
        count = i;
        break;
      }
    }
    count++;

    puts(s);
    strcpy(prev, s);
  }
  return 0;
}
