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

int main(void) {
  int n; float d;
  scanf("%d%f", &n, &d);

  int team;
  for (;;) {
    if (scanf("%d", &team) == -1) break;

    bool failed = false;
    int t = 0;
    rep (i, n) {
      int h,m,s;
      if (scanf("%d:%d:%d", &h, &m, &s) != 3) {
        failed = true;
        scanf("%*s");
      } else {
        t += h * 3600 + m * 60 + s;
      }
    }

    if (failed) {
      printf("%3d: -\n", team);
    } else {
      int totalsec = round(t/d);
      int min = totalsec / 60;
      int sec = totalsec % 60;
      printf("%3d: %d:%02d min/km\n", team, min, sec);
    }
  }

  return 0;
}
