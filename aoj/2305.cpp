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

const int M = 200001;
int a[21];
double dp[21][200001];

int main(void) {
  int N;
  cin >> N;
  rep (i, N) {
    cin >> a[i+1];
  }
  
  for (int k = 1; k < M; k++) {
    dp[N][k] = fabs(a[N]-k)/a[N];
  }
  
  for (int n = N-1; n > 0; n--) {
    for (int k = 1; k < M; k++) {
      double min_back = 1e10;
      for (int l = 1; k*l < M; l++) {
        min_back = min(min_back, dp[n+1][k*l]);
      }
      dp[n][k] = max(min_back, fabs(a[n]-k)/a[n]);
    }
  }
  
  double ans = 1e10;
  for (int k = 1; k < M; k++) {
    ans = min(ans, dp[1][k]);
  }
  printf("%.11f\n", ans);
  return 0;
}
