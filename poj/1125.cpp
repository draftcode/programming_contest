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
typedef pair<int, int> ip;

#define rep(i,n) for(int i = 0; i < n; i++)
#define each(it,c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define all(c) (c).begin(), (c).end()
#define zclear(v) memset(v, 0, sizeof(v))

int n;
int map[100][100];

void solve(void) {
  rep (k, n) {
    rep (i, n) {
      rep (j, n) {
        map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
      }
    }
  }
}

int main(void) {
  for (;;) {
    scanf("%d", &n);
    if (n == 0) break;

    fill_n((int*)map, sizeof(map)/sizeof(int), INT_MAX/2);
    rep (i, n) {
      int k;
      scanf("%d", &k);

      rep (j, k) {
        int s, t;
        scanf("%d%d", &s, &t);
        map[i][s-1] = t;
      }
    }
    solve();

    int mi_i = -1, mi = INT_MAX;
    rep (i, n) {
      int mx = 0;
      rep (j, n) {
        if (i == j) continue;
        mx = max(mx, map[i][j]);
      }
      if (mi > mx) {
        mi = mx;
        mi_i = i;
      }
    }

    if (mi == INT_MAX/2) {
      printf("disjoint\n");
    } else {
      printf("%d %d\n", mi_i+1, mi);
    }
  }
  return 0;
}
