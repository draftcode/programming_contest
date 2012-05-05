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

double EPS = 1e-7;

double theta(double as, double ac) {
  if (as < 0 && ac > M_PI_2) {
    return M_PI + ac;
  } else if (as < 0) {
    return 2 * M_PI + as;
  } else {
    return ac;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  double x0, y0, x1, y1, x2, y2;
  cin >> x0 >> y0 >> x1 >> y1 >> x2 >> y2;
  x1 -= x0; y1 -= y0;
  x2 -= x0; y2 -= y0;
  x0 = y0 = 0;
  double a = 2*(x1*y2-y1*x2);
  double cx = (y2*(x1*x1+y1*y1) - y1*(x2*x2+y2*y2))/a;
  double cy = (-x2*(x1*x1+y1*y1) + x1*(x2*x2+y2*y2))/a;
  double r = sqrt(cx*cx + cy*cy);
  x0 -= cx; y0 -= cy;
  x1 -= cx; y1 -= cy;
  x2 -= cx; y2 -= cy;

  double angle01 = abs(theta(asin(y0/r), acos(x0/r)) - theta(asin(y1/r), acos(x1/r)));
  double angle02 = abs(theta(asin(y0/r), acos(x0/r)) - theta(asin(y2/r), acos(x2/r)));

  int vertex = 3;
  for (; vertex <= 100; vertex++) {
    double one_angle = 2*M_PI/vertex;
    for (int k = 1; k <= vertex; k++) {
      if (abs(one_angle*k - angle01) < EPS) {
        for (int j = 1; j <= vertex; j++) {
          if (abs(one_angle*j - angle02) < EPS) {
            double ans = vertex * r * r * sin(one_angle) / 2;
            printf("%.8f\n", ans);
            return 0;
          }
        }
      }
    }
  }

  return 0;
}
