#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#include <numeric>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <climits>
using namespace std;
typedef long long ll;

#define rep(i,n) for(int i = 0; i < n; i++)
#define each(it,c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define all(c) (c).begin(), (c).end()
#define zclear(v) memset(v, 0, sizeof(v))

int main(void) {
  ll n, x, y;
  cin >> n >> x >> y;

  ll k = y - (n - 1);
  if (k <= 0 || k*k < x - (n - 1)) {
    cout << -1 << endl;
    return 0;
  }

  cout << k << endl;

  rep (i, n-1)
    cout << 1 << endl;

  return 0;
}
