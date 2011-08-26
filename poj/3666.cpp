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

int N;
int v[2000];
int sortv[2000];
int dp[2000][2000];

int trying(void) {
  for (int i = 0; i < N; i++) {
    for (int target = 0; target < N; target++) {
      if (i == 0) {
        if (target == 0) {
          dp[i][target] = abs(v[i] - sortv[target]);
        } else {
          dp[i][target] = min(dp[i][target-1], abs(v[i] - sortv[target]));
        }
      } else {
        if (target == 0) {
          dp[i][target] = dp[i-1][target] + abs(v[i] - sortv[target]);
        } else {
          dp[i][target] = min(dp[i][target-1],
                              dp[i-1][target] + abs(v[i] - sortv[target]));
        }
      }
    }
  }
  int cost = INT_MAX;
  for (int t = 0; t < N; t++) {
    cost = min(cost, dp[N-1][t]);
  }
  return cost;
}

int main(void) {
  cin >> N;
  rep (i, N) {
    int t;
    cin >> t;
    v[i] = t;
    sortv[i] = t;
  }
  sort(sortv, sortv+N);

  int cost = trying();
  reverse(v, v+N);
  cost = min(cost, trying());
  cout << cost << endl;

  return 0;
}
