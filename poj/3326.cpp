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

char map[10000][720];
int on[10000];

int main(void) {
  for (;;) {
    int n, m;
    scanf("%d%d", &n, &m);
    if (n == 0 && m == 0) break;
    zclear(map);
    zclear(on);

    int r;
    scanf("%d", &r);
    rep (i, r) {
      int t, n, m, s; // n ... PC, m ... Student
      scanf("%d%d%d%d", &t, &n, &m, &s);
      t -= 540;
      if (s == 1) {
        on[m] += 1;
        if (on[m] == 1) {
          map[m][t] = 1;
        }
      } else {
        on[m] -= 1;
        if (on[m] == 0) {
          t--;
          while (map[m][t] == 0) {
            map[m][t] = 1;
            t--;
          }
        }
      }
    }

    int q;
    scanf("%d", &q);
    rep (i, q) {
      int s, e, m;
      scanf("%d%d%d", &s, &e, &m);
      s -= 540;
      e -= 540;
      int ret = 0;
      while (s < e) {
        ret += map[m][s];
        s++;
      }
      printf("%d\n", ret);
    }

  }
  return 0;
}
