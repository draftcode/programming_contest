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

int map[20][20];
int main(void) {
  int n, s;
  scanf("%d%d", &n, &s);
  for (int x = 0; x < n; x++) {
    for (int y = 0; y <= x; y++) {
      map[x][y] = s++;
      if (s == 10) s = 1;
    }
  }
  for (int y = 0; y < n; y++) {
    for (int i = 0; i < y; i++) {
      printf("  ");
    }
    for (int x = y; x < n; x++) {
      printf("%d", map[x][y]);
      if (x == n-1) {
        putchar('\n');
      } else {
        putchar(' ');
      }
    }
  }
  return 0;
}
