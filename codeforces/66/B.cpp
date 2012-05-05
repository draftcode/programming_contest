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

int main(void) {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> v(n, 0);
  rep (i, n) cin >> v[i];

  int ans = 0;
  rep (i, n) {
    int fields = 1;
    for (int k = i+1; k < n; k++) {
      if (v[k-1] >= v[k]) {
        fields++;
      } else {
        break;
      }
    }
    for (int k = i-1; k >= 0; k--) {
      if (v[k+1] >= v[k]) {
        fields++;
      } else {
        break;
      }
    }
    ans = max(ans, fields);
  }

  cout << ans << endl;
  return 0;
}
