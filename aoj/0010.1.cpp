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
  double x0, y0, x1, y1, x2, y2;
  int t;
  cin >> t;
  rep (i, t) {
    cin >> x0 >> y0 >> x1 >> y1 >> x2 >> y2;
    x1 -= x0; y1 -= y0;
    x2 -= x0; y2 -= y0;
    double a = 2*(x1*y2-y1*x2);
    if (a == 0) return 1;
    double cx = (y2*(x1*x1+y1*y1) - y1*(x2*x2+y2*y2))/a;
    double cy = (-x2*(x1*x1+y1*y1) + x1*(x2*x2+y2*y2))/a;
    double r = sqrt(cx*cx + cy*cy);
    printf("%.3f %.3f %.3f\n", cx+x0, cy+y0, r);
  }
  return 0;
}
