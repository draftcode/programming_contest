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
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    int sz;
    cin >> sz;

    vector<ll> v1(sz), v2(sz);
    for (int i = 0; i < sz; i++) cin >> v1[i];
    for (int i = 0; i < sz; i++) cin >> v2[i];

    sort(v1.begin(), v1.end(), greater<ll>());
    sort(v2.begin(), v2.end(), less<ll>());

    ll ans = inner_product(v1.begin(), v1.end(), v2.begin(), 0LL);
    cout << "Case #" << t << ": " << ans << endl;
  }
  return 0;
}
