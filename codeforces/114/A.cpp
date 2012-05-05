#include <algorithm>
#include <functional>
#include <iostream>
#include <limits>
#include <numeric>
#include <queue>
#include <sstream>
#include <vector>

#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

#define rep(i,n) for(int i = 0; i < n; i++)
#define each(it,c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)

int main(void) {
  ios::sync_with_stdio(false);
  ll k, l;
  cin >> k >> l;

  int ans = 0;
  ll t = k;
  while (t < l) {
    t *= k;
    ans++;
  }

  if (t == l) {
    cout << "YES" << endl << ans << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}
