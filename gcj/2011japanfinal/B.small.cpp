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
  ll T, A, B, C;
  cin >> T;
  rep (t, T) {
    cin >> A >> B >> C;
    A = log(A);
    if (B >= 1) {
      int ans = 1;
      rep (i, A) {
        ans *= A;
      }
      A = ans;
    }

    if (B == 2) {
      int ans = 1;
      rep (i, A) {
        ans *= A;
        ans %= C;
      }
      A = ans;
    }
    cout << "Case #" << t+1 << ": " << (A % C) << endl;
  }
  return 0;
}
