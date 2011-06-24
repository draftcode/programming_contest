#include <algorithm>
#include <iostream>
#include <numeric>
#include <queue>
#include <vector>

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

int w, h;
int xs, ys, xg, yg;
char map[20][20];

void next(int x, int y, int dx, int dy, int& nx, int& ny) {
  nx = x;
  ny = y;
}

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int solve(int x, int y, int k) {
  if (k == 10) return INT_MAX;

  int mi = INT_MAX;
  rep (i, 4) {
    int nx = x, ny = y;
    int l = 0;
    while (0 <= nx+dx[i] && nx+dx[i] < w && 0 <= ny+dy[i] && ny+dy[i] < h) {
      if (nx+dx[i] == xg && ny+dy[i] == yg) {
        return k+1;
      } else if (map[nx+dx[i]][ny+dy[i]] == 0) {
        l++;
        nx += dx[i];
        ny += dy[i];
      } else {
        if (l > 0) {
          map[nx+dx[i]][ny+dy[i]] = 0;
          mi = min(mi, solve(nx, ny, k+1));
          map[nx+dx[i]][ny+dy[i]] = 1;
        }
        break;
      }
    }
  }
  return mi;
}

int main(void) {
  for (;;) {
    scanf("%d%d", &w, &h);
    if (w == 0 && h == 0) break;

    zclear(map);
    rep (y, h) {
      rep (x, w) {
        int t;
        scanf("%d", &t);
        if (t == 2) { xs = x; ys = y; t = 0; }
        else if (t == 3) { xg = x; yg = y; t = 0; }
        map[x][y] = t;
      }
    }

    int ret = solve(xs, ys, 0);
    if (ret == INT_MAX) {
      ret = -1;
    }
    printf("%d\n", ret);
  }
  return 0;
}
