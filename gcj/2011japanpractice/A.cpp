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
  int T;
  cin >> T;
  rep (i, T) {
    int N;
    ll K;
    cin >> N >> K;

    bool ok = true;
    rep (ii, N) {
      if ((K & 1) == 0) {
        ok = false;
        break;
      }
      K >>= 1;
    }

    cout << "Case #" << i+1 << ": ";
    if (ok) {
      cout << "ON" << endl;
    } else {
      cout << "OFF" << endl;
    }
  }
  return 0;
}
