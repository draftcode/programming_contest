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

double dp[100001];
void calc(void) {
  dp[1] = 1.0;
  double S = 0.5;
  double P = 0.5;
  double P2 = 0.5;
  for (int n = 2; n <= 100000; n++) {
    dp[n] = (1.0 - dp[n-1]) + S;
    P2 *= 0.5;
    P *= P2;
    S += P;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  calc();
  for (;;) {
    int n; cin >> n;
    if (n == 0) break;
    cout << accumulate(dp, dp+n+1, 0.0) << endl;
  }
  return 0;
}
