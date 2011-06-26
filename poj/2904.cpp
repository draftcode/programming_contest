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

int dp[11][101][102];
void solve(void) {
  for (int l = 0; l < 101; l++) {
    for (int u = l+2; u < 102; u++) {
      dp[1][l][u] = (u*u - u - l*l - l)/2;
    }
  }

  for (int k = 2; k <= 10; k++) {
    for (int l = 100; l >= 0; l--) {
      for (int u = 101; u >= l+1; u--) {
        int mi = dp[k-1][l][u];
        for (int i = l+1; i < u; i++) {
          mi = min(mi, i+max(dp[k][i][u], dp[k-1][l][i]));
        }
        dp[k][l][u] = mi;
      }
    }
  }
}

int main(void) {
  solve();

  int n;
  scanf("%d", &n);
  rep (_i, n) {
    int k, m;
    scanf("%d%d", &k, &m);
    printf("%d\n", dp[k][0][m+1]);
  }
  return 0;
}
