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

int main(void) {
  ios::sync_with_stdio(false);
  map<int, int> m;
  vector<int>v;

  for (;;) {
    char c;
    int team, num;
    cin >> team >> c >> num;
    if (team == 0 && num == 0) break;
    m[team] = num;
    v.push_back(num);
  }

  sort(v.begin(), v.end(), greater<int>());
  unique(v.begin(), v.end());

  int q;
  while (cin >> q) {
    int find = m[q];
    for (int i = 0; i < v.size(); i++) {
      if (v[i] == find) {
        cout << i + 1 << endl;
        break;
      }
    }
  }

  return 0;
}
