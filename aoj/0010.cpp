#include <algorithm>
#include <functional>
#include <iostream>
#include <limits>
#include <numeric>
#include <queue>
#include <vector>

#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;
typedef long long ll;

#define rep(i,n) for(int i = 0; i < n; i++)
#define each(it,c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)

int main(void) {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  rep (i, n) {
    double x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    
    double a;
    if (x2-x3 == 0) {
      a = (y3-y1)/(x1-x2)/2;
    } else {
      double t1, t2;
      t1 = (y3-y2)*(y1-y3)/2/(x2-x3) - (x1-x3)/2;
      t2 = (y2-y1) - (y3-y2)*(x1-x2)/(x2-x3);
      a = t1/t2;
    }
    
    double xp, yp;
    xp = (x1+x2)/2 + a*(y2-y1);
    yp = (y1+y2)/2 + a*(x1-x2);

    double r;
    r = sqrt((xp-x1)*(xp-x1) + (yp-y1)*(yp-y1));
    
    printf("%.3f %.3f %.3f\n", xp, yp, r);
  }
  return 0;
}
