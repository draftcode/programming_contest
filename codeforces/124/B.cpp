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

int n, k;
string strs[8];
int perms[] = {0,1,2,3,4,5,6,7};

int main(void) {
  ios::sync_with_stdio(false);
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> strs[i];
  }

  int ans = INT_MAX;
  do {
    int mi = INT_MAX, ma = 0;
    for (int i = 0; i < n; i++) {
      int number = 0;
      for (int j = 0; j < k; j++) {
        number *= 10;
        number += strs[i][perms[j]];
      }
      mi = min(mi, number);
      ma = max(ma, number);
    }
    ans = min(ans, ma - mi);
  } while (next_permutation(perms, perms+k));

  cout << ans << endl;

  return 0;
}
