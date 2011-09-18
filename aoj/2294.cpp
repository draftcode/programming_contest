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

double dp[502][102][102];
int static_bar_count[502];

int main(void) {
  int H, N, P, M, K;
  cin >> H >> N >> P >> M >> K;
  
  vector<int> static_bar(H+1, -1);
  rep (i, M) {
    int A, B;
    cin >> A >> B;
    static_bar[A] = B;
  }
  
  for (int h = H; h >= 0; h--) {
    static_bar_count[h] = static_bar_count[h+1];
    if (static_bar[h] != -1) {
      static_bar_count[h]++;
    }
  }
  
  dp[H+1][0][P] = 1.0;
  for (int h = H; h >= 1; h--) {
    for (int k = 0; k <= K; k++) {
      int white_rows_left = H - h - static_bar_count[h] + 1;
      if (static_bar[h] == -1 && white_rows_left != 0) {
        double row_choose_prob = (double) k / white_rows_left;
        for (int n = 1; n <= N; n++) {
          int cnt = 0;
          if (k != 0) {
            if (n >= 2) {
              dp[h][k][n] += row_choose_prob * dp[h+1][k-1][n-1] / (N-1);
              cnt++;
            }
            if (n <= N-1) {
              dp[h][k][n] += row_choose_prob * dp[h+1][k-1][n+1] / (N-1);
              cnt++;
            }
          }
          dp[h][k][n] += row_choose_prob * dp[h+1][k-1][n] * (N-1-cnt) / (N-1);
          dp[h][k][n] += (1-row_choose_prob) * dp[h+1][k][n];
        }
      } else {
        for (int n = 1; n <= N; n++) {
          dp[h][k][n] = dp[h+1][k][n];
        }
        
        if (static_bar[h] != -1) {
          swap(dp[h][k][static_bar[h]], dp[h][k][static_bar[h]+1]);
        }
      }
    }
  }
  
  double mx = 0.0;
  for (int n = 1; n <= N; n++) {
    mx = max(dp[1][K][n], mx);
  }
  printf("%.9f\n", mx);
  
  return 0;
}
