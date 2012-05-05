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

const double PI = 3.1415926535897932384626433832795;
const int ST_SIZE = (1 << 15) - 1;

int N, C;
int L[10000];

double vx[ST_SIZE], vy[ST_SIZE];
double ang[ST_SIZE];
double prv[10000];

void init(int k, int l, int r) {
  ang[k] = vx[k] = 0.0;

  if (r - l == 1) {
    vy[k] = L[l];
  } else {
    int chl = k*2+1, chr = k*2+2;
    int m = (l+r)/2;
    init(chl, l, m);
    init(chr, m, r);
    vy[k] = vy[chl] + vy[chr];
  }
}

void change(int s, double a, int v, int l, int r) {
  if (s <= l) return;
  else if (s < r) {
    int chl = v*2+1, chr = v*2+2;
    int m = (l+r)/2;
    change(s, a, chl, l, m);
    change(s, a, chr, m, r);
    if (s <= m) ang[v] += a;

    double si = sin(ang[v]), co = cos(ang[v]);
    vx[v] = vx[chl] + (co*vx[chr] - si*vy[chr]);
    vy[v] = vy[chl] + (si*vx[chr] + co*vy[chr]);
  }
}

int main(void) {
  ios::sync_with_stdio(false);

  bool first = true;
  while (scanf("%d%d", &N, &C) > 0) {
    if (!first) putchar('\n');
    first = false;

    for (int i = 0; i < N; i++) {
      scanf("%d", L+i);
      prv[i] = PI;
    }
    init(0, 0, N);

    for (int i = 0; i < C; i++) {
      int s, a_degree;
      scanf("%d%d", &s, &a_degree);
      double a_rad = a_degree / 360.0 * 2 * PI;

      change(s, a_rad-prv[s], 0, 0, N);
      prv[s] = a_rad;

      printf("%.2f %.2f\n", vx[0], vy[0]);
    }
  }

  return 0;
}
