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

int main(void) {
  ios::sync_with_stdio(false);
  for (;;) {
    int X, Y, Z; cin >> X >> Y >> Z; if (X == 0) break;
    vector<int> roulette(X);
    for (int i = 0; i < X; i++) cin >> roulette[i];

    vector<int> proceed(Y+1, 0);
    vector<int> gain(Y+1, 0);
    for (int i = 0; i < Z; i++) {
      int N, E, A; cin >> N >> E >> A;
      if (E == 1) proceed[N] = A;
      else if (E == 2) gain[N] = A;
      else if (E == 3) gain[N] = -A;
    }

    vector<vector<double> > dp(Y+1, vector<double>(5000+1, 0.0));
    dp[0][0] = 1.0;

    for (int i = 0; i < Y; i++) {
      for (int money = 0; money < 5000+1; money++) {
        double next_prob_add = dp[i][money]/X;
        for (int k = 0; k < X; k++) {
          int next_i = i+roulette[k];
          int next_money = money;
          if (next_i > Y) {
            next_i = Y;
          } else {
            if (proceed[next_i] != 0) {
              next_i = min(next_i+proceed[next_i], Y);
            } else {
              next_money = max(0, money+gain[next_i]);
            }
          }
          dp[next_i][next_money] += next_prob_add;
        }
      }
    }

    double ans = 0.0;
    for (int money = 0; money < 5000+1; money++) {
      ans += money*dp[Y][money];
    }

    cout << (int)ans << endl;
  }
  return 0;
}
