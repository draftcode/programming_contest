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

int N, M;
ll An[100];
ll Bn[100];
int At[100];
int Bt[100];

ll dp[101][101];
ll AAcc[101][101];
ll BAcc[101][101];

void calc(void) {
  cin >> N >> M;
  for (int i = 0; i < N; i++) { cin >> An[i] >> At[i]; }
  for (int i = 0; i < M; i++) { cin >> Bn[i] >> Bt[i]; }

  memset(dp, 0, sizeof(dp));
  memset(AAcc, 0, sizeof(AAcc));
  memset(BAcc, 0, sizeof(BAcc));

  for (int type = 1; type <= 100; type++) {
    for (int i = 0; i < N; i++) {
      AAcc[i+1][type] = AAcc[i][type] + ((At[i] == type) ? An[i] : 0);
    }

    for (int i = 0; i < M; i++) {
      BAcc[i+1][type] = BAcc[i][type] + ((Bt[i] == type) ? Bn[i] : 0);
    }
  }


  for (int sn = 0; sn <= N; sn++) {
    for (int sm = 0; sm <= M; sm++) {
      for (int ln = sn; ln <= N; ln++) {
        for (int lm = sm; lm <= M; lm++) {
          int type = At[sn];
          ll A = AAcc[ln][type] - AAcc[sn][type];
          ll B = BAcc[lm][type] - BAcc[sm][type];

          dp[ln][lm] = max(dp[ln][lm], dp[sn][sm] + min(A, B));
        }
      }
    }
  }

  cout << dp[N][M];
}

int main(void) {
  ios::sync_with_stdio(false);
  int T; cin >> T;
  for (int i = 1; i <= T; i++) {
    cout << "Case #" << i << ": ";
    calc();
    cout << endl;
  }
  return 0;
}
