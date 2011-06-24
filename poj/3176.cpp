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

int map[350][350];

int main(void) {
  int n;
  scanf("%d", &n);
  rep (y, n) {
    for (int x = 0; x <= y; x++) {
      int t;
      scanf("%d", &t);
      map[y][x] = t;
    }
  }

  for (int y = n - 2; y > -1; y--) {
    for (int x = 0; x <= y; x++) {
      map[y][x] = max(map[y][x]+map[y+1][x], map[y][x]+map[y+1][x+1]);
    }
  }
  printf("%d\n", map[0][0]);
  return 0;
}
