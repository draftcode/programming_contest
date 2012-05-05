#include <algorithm>
#include <functional>
#include <iostream>
#include <limits>
#include <numeric>
#include <queue>
#include <sstream>
#include <vector>
#include <map>

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
  map<int, int> m;

  int n, mx = 0;
  while (cin >> n) {
    m[n]++;
    mx = max(mx, m[n]);
  }

  vector<int> v;
  for (map<int, int>::const_iterator it = m.begin(); it != m.end(); it++) {
    if (it->second == mx) v.push_back(it->first);
  }

  sort(v.begin(), v.end());
  for (vector<int>::const_iterator it = v.begin(); it != v.end(); it++) {
    cout << *it << endl;
  }

  return 0;
}
