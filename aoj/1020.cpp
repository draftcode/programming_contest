#include <algorithm>
#include <functional>
#include <iostream>
#include <limits>
#include <numeric>
#include <queue>
#include <vector>

#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

#define rep(i,n) for(int i = 0; i < n; i++)
#define each(it,c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)


vector<int> adjacent[9];

// 0 1 2
// 3 4 5
// 6 7 8

void setup(void) {
  adjacent[0].push_back(1);
  adjacent[0].push_back(3);
  
  adjacent[1].push_back(0);
  adjacent[1].push_back(2);
  adjacent[1].push_back(4);

  adjacent[2].push_back(1);
  adjacent[2].push_back(5);

  adjacent[3].push_back(0);
  adjacent[3].push_back(4);
  adjacent[3].push_back(6);

  adjacent[4].push_back(1);
  adjacent[4].push_back(3);
  adjacent[4].push_back(5);
  adjacent[4].push_back(7);

  adjacent[5].push_back(2);
  adjacent[5].push_back(4);
  adjacent[5].push_back(8);

  adjacent[6].push_back(3);
  adjacent[6].push_back(7);

  adjacent[7].push_back(4);
  adjacent[7].push_back(6);
  adjacent[7].push_back(8);

  adjacent[8].push_back(5);
  adjacent[8].push_back(7);
}

int dp[16][9];
int n, s, t, b;
void calc(void) {
  rep (i, 16) {
    fill(dp[i], dp[i]+9, 0);
  }
  dp[0][s] = 1;
  for (int i = 0; i < n; i++) {
    for (int k = 0; k < 9; k++) {
      int stayed = 4 - adjacent[k].size();
      each (it, adjacent[k]) {
        if (*it == b) {
          stayed++;
        } else {
          dp[i+1][*it] += dp[i][k];
        }
      }
      
      dp[i+1][k] += stayed * dp[i][k];
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  setup();

  string S, T, B;
  for (;;) {
    cin >> n;
    if (n == 0) break;
    cin >> S >> T >> B;
    s = S[0] - 'A';
    t = T[0] - 'A';
    b = B[0] - 'A';
    calc();
    
    int total = 0;
    rep (k, 9) {
      total += dp[n][k];
    }
    printf("%.8f\n", (double)dp[n][t]/total);
  }
  return 0;
}

