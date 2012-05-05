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

ll comb[31][31];

void calc(void) {
  for (int n = 1; n <= 30; n++) {
    for (int m = 1; m <= n; m++) {
      if (m == 1) {
        comb[n][m] = n;
      } else {
        comb[n][m] = comb[n-1][m] + comb[n-1][m-1];
      }
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  calc();
  int n, m, t;
  cin >> n >> m >> t;
  ll ans = 0;
  for (int boys = 4; boys <= n; boys++) {
    int girls = t-boys;
    if (girls >= 1 && girls <= m) {
      ans += comb[n][boys] * comb[m][girls];
    }
  }
  cout << ans << endl;

  return 0;
}
