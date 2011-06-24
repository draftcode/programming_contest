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

int n;
int treats[2000];
int dp[2000][2000];

void solve(void) {
  for (int s = n; s >= 0; s--) {
    for (int e = s+1; e <= n; e++) {
        int t = s + n - e + 1;
        dp[s][e] = max(t*treats[s] + dp[s+1][e], t*treats[e-1] + dp[s][e-1]);
    }
  }
}

int main(void) {
  scanf("%d", &n);
  rep (i, n) {
    scanf("%d", treats+i);
  }
  solve();
  printf("%d\n", dp[0][n]);
  return 0;
}
