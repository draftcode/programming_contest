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
int seq[1001];
int dp[1001];

int solve(void) {
  for (int i = 1; i <= n; i++) {
    int mx = 0;
    for (int k = 1; k < i; k++) {
      if (seq[i] > seq[k]) mx = max(mx, dp[k]);
    }
    dp[i] = mx+1;
  }

  return *max_element(dp, dp+n+1);
}

int main(void) {
  scanf("%d", &n);
  rep (i, n) scanf("%d", seq+i+1);

  printf("%d\n", solve());
  return 0;
}
