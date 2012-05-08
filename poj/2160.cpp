#include <algorithm>
#include <functional>
#include <iostream>
#include <limits>
#include <numeric>
#include <queue>
#include <sstream>
#include <vector>
#include <map>
#include <set>

#include <cctype>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

P v[6];

int main(void) {
  ios::sync_with_stdio(false);
  for (int i = 0; i < 6; i++) {
    int a, b; cin >> a >> b;
    v[i] = P(min(a, b), max(a, b));
  }

  sort(v, v+6);
  if (!(v[0] == v[1] && v[2] == v[3] && v[4] == v[5])) {
    cout << "IMPOSSIBLE" << endl;
    return 0;
  } else {
    if (v[0].first == v[2].first) {
      if (v[4] == P(min(v[0].second, v[2].second), max(v[0].second, v[2].second))) {
        cout << "POSSIBLE" << endl;
        return 0;
      }
    } else if (v[0].first == v[4].first) {
      if (v[2] == P(min(v[0].second, v[4].second), max(v[0].second, v[4].second))) {
        cout << "POSSIBLE" << endl;
        return 0;
      }
    } else if (v[0].first == v[2].second) {
      if (v[4] == P(min(v[0].second, v[2].first), max(v[0].second, v[2].first))) {
        cout << "POSSIBLE" << endl;
        return 0;
      }
    } else if (v[0].first == v[4].second) {
      if (v[2] == P(min(v[0].second, v[4].first), max(v[0].second, v[4].first))) {
        cout << "POSSIBLE" << endl;
        return 0;
      }
    }
    cout << "IMPOSSIBLE" << endl;
  }

  return 0;
}
