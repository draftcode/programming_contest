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
  string pass;
  string number[10];
  cin >> pass;
  rep (i, 10) cin >> number[i];

  string ans;
  rep (i, 8) {
    rep (k, 10) {
      if (pass.substr(10*i, 10) == number[k]) {
        ans.push_back(k + '0');
        break;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
