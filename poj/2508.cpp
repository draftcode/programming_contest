#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#include <numeric>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <climits>
using namespace std;
typedef long long ll;

#define rep(i,n) for(int i = 0; i < n; i++)
#define each(it,c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define all(c) (c).begin(), (c).end()
#define zclear(v) memset(v, 0, sizeof(v))

double calc(double r, double h, double d1, double A1, double d2, double A2) {
  double theta = 2 * asin(r * sin(abs(A1-A2)/2) / sqrt(r*r + h*h));
  double tmp1 = d1 * sin(theta);
  double tmp2 = d2 - d1 * cos(theta);
  return sqrt(tmp1 * tmp1 + tmp2 * tmp2);
}

int main(void) {
  double r, h, d1, A1, d2, A2;
  while (cin >> r) {
    cin >> h >> d1 >> A1 >> d2 >> A2;
    printf("%.2f\n", calc(r, h, d1, A1, d2, A2));
  }
  return 0;
}
