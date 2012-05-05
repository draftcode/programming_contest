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

int N, K;
double v[10001];

bool C(double x) {
  int num = 0;
  for (int i = 0; i < N; i++) {
    num += (int)(v[i]/x);
  }
  return num >= K;
}

int main(void) {
  scanf("%d%d", &N, &K);

  double lb = 0, ub = 0;
  for (int i = 0; i < N; i++) {
    scanf("%lf", v+i);
    ub = max(ub, v[i]);
  }

  for (int i = 0; i < 1000; i++) {
    double mid = (lb + ub) / 2;
    if (C(mid))
      lb = mid;
    else
      ub = mid;
  }

  printf("%.2f\n", floor(ub * 100) / 100);

  return 0;
}
