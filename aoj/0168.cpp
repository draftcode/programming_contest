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
    int n; cin >> n; if (n == 0) break;
    vector<int> v(n+1, 0);
    v[0] = 1;
    for (int i = 1; i <= n; i++) {
      if (i-1 >= 0) v[i] += v[i-1];
      if (i-2 >= 0) v[i] += v[i-2];
      if (i-3 >= 0) v[i] += v[i-3];
    }

    int patterns = v[n];
    int ans = patterns / 3650;
    if (patterns % 3650 != 0) ans++;
    cout << ans << endl;
  }
  return 0;
}
