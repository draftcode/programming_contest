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

int n;
char map[11][11][11]; // z, y, x
int xs, ys, zs;
int xg, yg, zg;

struct pos {
  int d, x, y, z;
  pos(int _d, int _x, int _y, int _z) : d(_d), x(_x), y(_y), z(_z) {}
  bool operator <(const pos& rhs) const {
    return d > rhs.d;
  }
};

bool movable(const pos &p, int dx, int dy, int dz) {
  if (0 <= p.x+dx && p.x+dx < n
   && 0 <= p.y+dy && p.y+dy < n
   && 0 <= p.z+dz && p.z+dz < n) {
    if (map[p.z+dz][p.y+dy][p.x+dx] == 'O') {
      map[p.z+dz][p.y+dy][p.x+dx] = 'X';
      return true;
    }
  }
  return false;
}

void solve(void) {
  priority_queue<pos> que;
  que.push(pos(0, xs, ys, zs));
  while (!que.empty()) {
    pos p = que.top(); que.pop();

    if (p.x == xg && p.y == yg && p.z == zg) {
      printf("%d %d\n", n, p.d);
      return;
    }

    if (movable(p,  1,  0,  0)) { que.push(pos(p.d+1, p.x+1, p.y, p.z)); }
    if (movable(p, -1,  0,  0)) { que.push(pos(p.d+1, p.x-1, p.y, p.z)); }
    if (movable(p,  0,  1,  0)) { que.push(pos(p.d+1, p.x, p.y+1, p.z)); }
    if (movable(p,  0, -1,  0)) { que.push(pos(p.d+1, p.x, p.y-1, p.z)); }
    if (movable(p,  0,  0,  1)) { que.push(pos(p.d+1, p.x, p.y, p.z+1)); }
    if (movable(p,  0,  0, -1)) { que.push(pos(p.d+1, p.x, p.y, p.z-1)); }
  }
  printf("NO ROUTE\n");
}

int main(void) {
  while (scanf("%*[^0-9]%d", &n) == 1) {
    rep (z, n) {
      rep (y, n) {
        scanf("%s", map[z][y]);
      }
    }

    scanf("%d%d%d", &xs, &ys, &zs);
    scanf("%d%d%d", &xg, &yg, &zg);
    solve();
    scanf("END");
  }
  return 0;
}
