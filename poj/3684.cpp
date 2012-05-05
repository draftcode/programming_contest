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

const double g = 10.0;
int C, N, H, R, T;

double calc(int T) {
  if (T < 0) return H;
  double t = sqrt(2*H/g);
  int k = (int)(T/t);
  if (k % 2 == 0) {
    double d = T - k*t;
    return H - g*d*d/2;
  } else {
    double d = k*t + t - T;
    return H - g*d*d/2;
  }
}

int main(void) {
  scanf("%d", &C);
  for (int _ = 0; _ < C; _++) {
    scanf("%d%d%d%d", &N, &H, &R, &T);
    vector<double> ans(N);
    for (int i = 0; i < N; i++) {
      ans[i] = calc(T - i);
    }
    sort(ans.begin(), ans.end());
    for (int i = 0; i < N; i++) {
      printf("%.2f%c", ans[i] + 2*R*i/100.0, i == N-1 ? '\n' : ' ');
    }
  }

  return 0;
}
