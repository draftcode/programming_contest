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

  int min_diff = INT_MAX;
  int m = 0;
  rep (i, n) {
    int diff = abs(v[i] - v[(i+1)%n]);
    if (min_diff > diff) {
      min_diff = diff;
      m = i;
    }
  }

  cout << m+1 << ' ' << (m+1)%n+1 << endl;
  return 0;
}
