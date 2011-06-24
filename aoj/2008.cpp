#include <algorithm>
#include <iostream>
#include <queue>
#include <complex>
#include <vector>
#include <numeric>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <climits>
using namespace std;
typedef long long ll;
typedef pair<int, int> ip;

#define rep(i,n) for(int i = 0; i < n; i++)
#define each(it,c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define all(c) (c).begin(), (c).end()
#define zclear(v) memset(v, 0, sizeof(v))

int n;
ip hp, dp;
int end;
ip crystals[20];

bool prohibit(double t, ip p) {
  return t >= hypot(dp.first-p.first, dp.second-p.second);
}

bool dfs(int l, double t, int s) {
  if (end == s) return true;

  double temp[20];
  zclear(temp);
  rep (i, n) {
    if ((s & (1 << i)) == 0) {
      ip from = crystals[l];
      ip dest = crystals[i];
      double nt = t + hypot(from.first-dest.first, from.second-dest.second);
      if (prohibit(nt, dest)) return false;
      temp[i] = nt;
    } else {
      temp[i] = 0.0;
    }
  }

  rep (i, n) {
    if (temp[i] != 0.0) {
      if (dfs(i, temp[i], s | (1 << i))) return true;
    }
  }
  return false;
}

bool solve(void) {
  end = (1 << n) - 1;
  rep (i, n) {
    double dist = hypot(hp.first-crystals[i].first, hp.second-crystals[i].second);
    if (prohibit(dist, crystals[i])) return false;
    if (dfs(i, dist, 1 << i)) {
      return true;
    }
  }
  return false;
}

int main(void) {
  for (;;) {
    int hx, hy, dx, dy;
    scanf("%d%d%d%d%d", &n, &hx, &hy, &dx, &dy);
    hp = ip(hx, hy);
    dp = ip(dx, dy);

    if (n == 0 && hx == 0 && hy == 0 && dx == 0 && dy == 0) break;
    rep (i, n) {
      int x, y;
      scanf("%d%d", &x, &y);
      crystals[i] = ip(x, y);
    }
    if (solve()) {
      printf("YES\n");
    } else {
      printf("NO\n");
    }
  }
  return 0;
}
