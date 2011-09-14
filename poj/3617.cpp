#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#include <numeric>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <climits>
using namespace std;
typedef long long ll;

#define rep(i,n) for(int i = 0; i < n; i++)
#define each(it,c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define all(c) (c).begin(), (c).end()
#define zclear(v) memset(v, 0, sizeof(v))

int main(void) {
  int n;
  char s[2048];
  scanf("%d", &n);
  rep (i, n) scanf("%s", s+i);
  
  char *top, *bottom;
  top = s;
  bottom = s + n - 1;
  int count = 0;
  while (top <= bottom) {
    char *temp_top = top;
    char *temp_bottom = bottom;
    while (temp_top < temp_bottom && *temp_top == *temp_bottom) {
      temp_top++;
      temp_bottom--;
    }
    
    if (*temp_top < *temp_bottom) {
      putchar(*top++);
    } else {
      putchar(*bottom--);
    }
    count++;
    if (count == 80) {
      putchar('\n');
      count = 0;
    }
  }
  if (count > 0) putchar('\n');
  return 0;
}
