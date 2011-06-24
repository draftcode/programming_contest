#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#include <numeric>
#include <complex>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <climits>
using namespace std;
typedef long long ll;
typedef complex<double> p;

#define rep(i,n) for(int i = 0; i < n; i++)
#define each(it,c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define all(c) (c).begin(), (c).end()
#define zclear(v) memset(v, 0, sizeof(v))

double cross(p v1, p v2) {
  return imag(conj(v1)*v2);
}

int main(void) {
  for (;;) {
    int n;
    scanf("%d", &n);
    if (n < 3) break;

    vector<p> v;
    rep (i, n) {
      double x, y;
      scanf("%lf%lf", &x, &y);
      v.push_back(p(x, y));
    }

    double temp = 0.0;
    rep (i, n) {
      if (i == n-1) {
        temp += cross(v[i], v[0]);
      } else {
        temp += cross(v[i], v[i+1]);
      }
    }

    double vol;
    scanf("%lf", &vol);
    printf("BAR LENGTH: %.2f\n", abs(vol/(temp/2)));
  }
  return 0;
}
