#include <algorithm>
#include <functional>
#include <iostream>
#include <limits>
#include <numeric>
#include <queue>
#include <sstream>
#include <vector>
#include <map>
#include <set>

#include <cctype>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int dp[100][51][2];

int main(void) {
  ios::sync_with_stdio(false);
  string s; int N;
  cin >> s >> N;

  int ans = 0;

  if (s[0] == 'F') {
    dp[0][0][0] = 1;
    dp[0][0][1] = -INT_MAX/2;
    dp[0][1][0] = -INT_MAX/2;
    dp[0][1][1] = 0;
  } else {
    dp[0][0][0] = -INT_MAX/2;
    dp[0][0][1] = 0;
    dp[0][1][0] = 1;
    dp[0][1][1] = -INT_MAX/2;
  }

  for (int i = 1; i < s.size(); i++) {
    for (int j = 0; j <= i+1 && j <= N; j++) {
      if (s[i] == 'F') {
        dp[i][j][0] = dp[i-1][j][0]+1;
        dp[i][j][1] = dp[i-1][j][1]-1;
        if (j != 0) {
          dp[i][j][0] = max(dp[i][j][0], dp[i-1][j-1][1]);
          dp[i][j][1] = max(dp[i][j][1], dp[i-1][j-1][0]);

          if (j != 1) {
            dp[i][j][0] = max(dp[i][j][0], dp[i][j-2][0]+1);
            dp[i][j][1] = max(dp[i][j][1], dp[i][j-2][1]-1);
          }
        }
      } else {
        dp[i][j][0] = dp[i-1][j][1];
        dp[i][j][1] = dp[i-1][j][0];

        if (j != 0) {
          dp[i][j][0] = max(dp[i][j][0], dp[i-1][j-1][0]+1);
          dp[i][j][1] = max(dp[i][j][1], dp[i-1][j-1][1]-1);

          if (j != 1) {
            dp[i][j][0] = max(dp[i][j][0], dp[i][j-2][1]);
            dp[i][j][1] = max(dp[i][j][1], dp[i][j-2][0]);
          }
        }
      }
    }
  }

  ans = max(ans, dp[s.size()-1][N][0]);
  ans = max(ans, dp[s.size()-1][N][1]);

  cout << ans << endl;
  return 0;
}
