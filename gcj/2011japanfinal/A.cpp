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
  rep (t, T) {
    int K;
    vector<int> v;
    cin >> K;
    rep (i, K) {
      int c; cin >> c; v.push_back(c);
    }
    sort(v.begin(), v.end(), greater<int>());

    double angle = 2*M_PI/K;
    double P = 0.0;
    int base1 = v[0], base2 = v[0];
    for (int i = 1; i < K; i++) {
      if (base1 > base2) {
        P += v[i]*base1*sin(angle)/2;
        base1 = v[i];
      } else {
        P += v[i]*base2*sin(angle)/2;
        base2 = v[i];
      }
    }
    P += base1 * base2 * sin(angle) / 2;
    printf("Case #%d: %.8f\n", t+1, P);
  }
  return 0;
}
