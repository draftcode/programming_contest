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

int n, m;
int lef[501][501];
int top[501][501];
int dp[501][502];

int solve(void) {
  zclear(dp);
  rep (y, n) {
    rep (x, m+1) {
      int r = 0;
      if (y > 0) {
        for (int i = 0; i <= x; i++) {
          r = max(r, dp[y-1][i]);
        }
      }
      for (int i = 0; i < x; i++) {
        r += lef[y][i];
      }
      for (int i = x; i < m; i++) {
        r += top[y][i];
      }
      dp[y][x] = r;
    }
  }

  int r = 0;
  for (int i = 0; i < m+2; i++) {
    r = max(r, dp[n-1][i]);
  }
  return r;
}

int main(void) {
  for (;;) {
    scanf("%d%d", &n, &m);
    if (n == 0 && m == 0) break;

    rep (y, n) {
      rep (x, m) {
        scanf("%d", &(lef[y][x]));
      }
    }
    rep (y, n) {
      rep (x, m) {
        scanf("%d", &(top[y][x]));
      }
    }

    printf("%d\n", solve());
  }
  return 0;
}
