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

int N;
int XS, XE, YS, YE, ZS, ZE;

void f(int &xs, int &xe, int &XS, int &XE) {
  if (xs <= XS && XE <= xe) {}
  else if (xe < XS) { XS = XE = 0; }
  else if (xs <= XS && xe <= XE) { XE = xe; }
  else if (XS <= xs && xe <= XE) { XS = xs; XE = xe; }
  else if (xs <= XE && XE <= xe) { XS = xs; }
  else if (XE <= xs) { XS = XE = 0; }
}

int main(void) {
  for (;;) {
    scanf("%d", &N);
    if (N == 0) break;
    int d;
    scanf("%d%d%d%d", &XS, &YS, &ZS, &d);
    XE = XS + d;
    YE = YS + d;
    ZE = ZS + d;

    for (int i = 1; i < N; i++) {
      int xs, ys, zs, xe, ye, ze;
      scanf("%d%d%d%d", &xs, &ys, &zs, &d);
      xe = xs + d;
      ye = ys + d;
      ze = zs + d;

      f(xs, xe, XS, XE);
      f(ys, ye, YS, YE);
      f(zs, ze, ZS, ZE);
    }

    printf("%d\n", (XE - XS) * (YE - YS) * (ZE - ZS));
  }
  return 0;
}
