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
vector<int> v;

int memo[100][1<<5];

int rep(int i, int erase) {
  if (i == v.size()) return 0;
  if (memo[i][erase] != -1) return memo[i][erase];

  int ans = INT_MAX;
  if ((erase & (1 << (v[i]-1))) == 0) {
    int cost = 0;
    int k = i;
    while (k < v.size()) {
      for (; k < v.size(); k++) {
        if (v[k] != v[i]) break;
      }
      ans = min(ans, cost + rep(k, erase | (1 << (v[i]-1))));

      for (; k < v.size(); k++) {
        if (v[k] == v[i]) break;
        cost++;
      }

      for (; k < v.size(); k++) {
        if (v[k] != v[i]) break;
      }

      ans = min(ans, cost + rep(k, erase | (1 << (v[i]-1))));
    }
  }

  {
    int cost = 0;
    int k = i;
    for (; k < v.size(); k++) {
      if (v[k] != v[i]) break;
      cost++;
    }
    if (k == v.size() && (erase & (1 << (v[i]-1))) == 0) {
      ans = 0;
    } else {
      ans = min(ans, cost + rep(k, erase));
    }
  }

  memo[i][erase] = ans;
  return ans;
}

int main(void) {
  ios::sync_with_stdio(false);
  for (;;) {
    int m, k; cin >> m >> k;
    if (m == 0 && k == 0) break;

    fill(memo[0], memo[100], -1);
    v.resize(m, 0);
    for (int i = 0; i < m; i++) {
      cin >> v[i];
    }

    cout << rep(0, 0) << endl;
    cerr << endl;
  }
  return 0;
}
