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
  string max_s, max_t;
  map<string, int> m;
  int mx = 0;
  string s;
  while (cin >> s) {
    if (s.size() > max_s.size()) {
      max_s = s;
    }
    m[s]++;
    if (m[s] > mx) {
      mx = m[s];
      max_t = s;
    }
  }

  cout << max_t << ' ' << max_s << endl;
  return 0;
}
