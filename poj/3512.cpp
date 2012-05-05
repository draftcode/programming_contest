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
#include <cfloat>
#include <cmath>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

#define rep(i,n) for(int i = 0; i < n; i++)
#define each(it,c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)

P parse(const string &s) {
  int x, y;
  sscanf(s.c_str(), "%d %d", &x, &y);
  return P(x, y);
}

double EPS = 1e-40;

int calc(P &p, const vector<P> &points) {
  vector<double> inclines;
  each (it, points) {
    if (*it != p) {
      double incline;
      if (it->first - p.first == 0) {
        incline = DBL_MAX;
      } else if (it->second - p.second == 0) {
        incline = DBL_EPSILON;
      } else {
        incline = ((double)(it->second - p.second))/(it->first - p.first);
      }
      inclines.push_back(incline);
    }
  }
  sort(inclines.begin(), inclines.end());

  int ret = 0;
  int count = 0;
  double prev = 0.0;
  each (it, inclines) {
    if (*it != prev) {
      count = 1;
    }
    count++;
    prev = *it;
    ret = max(ret, count);
  }
  return ret;
}

int main(void) {
  ios::sync_with_stdio(false);
  int c = 1;
  for (;;) {
    vector<P> points;

    string s;
    while (getline(cin, s)) {
      if (s[0] == '-' && s[1] == '-') break;
      points.push_back(parse(s));
    }
    if (points.size() == 0) break;

    int ans = 0;
    each (it, points) {
      ans = max(ans, calc(*it, points));
    }
    cout << c++ << ". " << ans << endl;
  }
  return 0;
}
