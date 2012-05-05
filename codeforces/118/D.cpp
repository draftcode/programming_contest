#include <algorithm>
#include <functional>
#include <iostream>
#include <limits>
#include <numeric>
#include <queue>
#include <sstream>
#include <vector>

#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

#define rep(i,n) for(int i = 0; i < n; i++)
#define each(it,c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)

int N1, N2, K1, K2;
ll dp[101][101][22];

int main(void) {
  ios::sync_with_stdio(false);
  cin >> N1 >> N2 >> K1 >> K2;

  for (int i = 1; i <= K1; i++) {
    dp[i][0][i] += 1;
    dp[i][0][K1+1] += 1;
  }
  for (int i = 1; i <= K2; i++) {
    dp[0][i][K1+1+i] += 1;
    dp[0][i][0] += 1;
  }

  for(int n1 = 1; n1 <= N1; n1++) {
    for(int n2 = 1; n2 <= N2; n2++) {
      for (int k = 0; k <= K1 + K2 + 1; k++) {
        if (k == 0) {
        } else if (k == K1+1) {
        } else if (k <= K1) {
          dp[n1][n2][k] += dp[n1-1][n2][k-1];
          dp[n1][n2][K1+1] += dp[n1-1][n2][k-1];
        } else {
          dp[n1][n2][k] += dp[n1][n2-1][k-1];
          dp[n1][n2][0] += dp[n1][n2-1][k-1];
        }
        dp[n1][n2][k] %= 100000000;
        dp[n1][n2][K1+1] %= 100000000;
        dp[n1][n2][0] %= 100000000;
      }
    }
  }

  ll ans = (dp[N1][N2][0] + dp[N1][N2][K1+1]) % 100000000;
  cout << ans << endl;
  return 0;
}
