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
  int p1, p2, p3, p4, a, b;
  cin >> p1 >> p2 >> p3 >> p4 >> a >> b;

  int ans = 0;
  for (int i = a; i <= b; i++) {
    if (i == ((((i % p1) % p2) % p3) % p4)) {
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
