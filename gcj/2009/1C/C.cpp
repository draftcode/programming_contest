#include <algorithm>
#include <functional>
#include <iostream>
#include <limits>
#include <numeric>
#include <queue>
#include <sstream>
#include <vector>

#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

#define rep(i,n) for(int i = 0; i < n; i++)
#define each(it,c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)

int dp[101][101];

int main(void) {
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    int P, Q;
    cin >> P >> Q;

    vector<int> v(Q+2, 0);
    for (int q = 1; q <= Q; q++) {
      cin >> v[q];
    }
    v[Q+1] = P + 1;

    for (int q = 0; q <= Q; q++) {
      dp[q][q+1] = 0;
    }

    for (int k = 2; k <= Q + 1; k++) {
      for (int j = 0; j+k <= Q + 1; j++) {
        int m = INT_MAX;
        for (int l = j + 1; l < j + k; l++) {
          m = min(m, dp[j][l] + dp[l][j+k]);
        }

        dp[j][j+k] = m + v[j+k] - v[j] - 2;
      }
    }

    cout << "Case #" << t << ": " << dp[0][Q+1] << endl;
  }
  return 0;
}
