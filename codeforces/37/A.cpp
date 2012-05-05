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
  int n;
  cin >> n;

  vector<int> v(1001, 0);
  rep (i, n) {
    int k; cin >> k; v[k]++;
  }

  sort(v.begin(), v.end(), greater<int>());

  int b = 0;
  rep (i, 1001) {
    if (v[i] == 0) break;
    b++;
  }

  cout << v[0] << ' ' << b << endl;

  return 0;
}
