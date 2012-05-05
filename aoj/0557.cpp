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
  int N; cin >> N;
  vector<int> v(N);
  for (int i = 0; i < N; i++) {
    cin >> v[i];
  }

  vector<vector<unsigned long long> > dp(N, vector<unsigned long long>(21, 0ULL));
  dp[0][v[0]] = 1;
  for (int i = 1; i < N; i++) {
    for (int j = 0; j <= 20; j++) {
      if (j + v[i] <= 20)
        dp[i][j+v[i]] += dp[i-1][j];
      if (j - v[i] >= 0)
        dp[i][j-v[i]] += dp[i-1][j];
    }
  }
  cout << dp[N-1][0] << endl;
  return 0;
}
