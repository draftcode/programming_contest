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

char s[16][16];

int main(void) {
  int n, m;
  scanf("%d%d", &n, &m);
  rep (i, n) {
    scanf("%s", s[i]);
  }
  
  int ans = 0;
  rep (y, n) {
    rep (x, m) {
      if (s[y][x] == 'P') {
        if (y != 0 && s[y-1][x] == 'W') {
          s[y-1][x] = '.'; ans++; continue;
        }
        if (y != n-1 && s[y+1][x] == 'W') {
          s[y+1][x] = '.'; ans++; continue;
        }
        if (x != 0 && s[y][x-1] == 'W') {
          s[y][x-1] = '.'; ans++; continue;
        }
        if (x != m-1 && s[y][x+1] == 'W') {
          s[y][x+1] = '.'; ans++; continue;
        }
      }
    }
  }
  printf("%d\n", ans);
  
  return 0;
}
