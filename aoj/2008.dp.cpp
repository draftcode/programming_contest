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

// DPでやろうと思ったらMLE．あきらめて探索することにする．

int n, hx, hy, dx, dy;
int xs[20];
int ys[20];
float map[1<<20][20];

float dist(int from, int dest) {
  int dx = xs[from]-xs[dest];
  int dy = ys[from]-ys[dest];
  return sqrt(dx*dx + dy*dy);
}

bool prohibit(float t, int x, int y) {
  int diffx = x - dx;
  int diffy = y - dy;
  return t >= sqrt(diffx*diffx + diffy*diffy);
}

bool solve(void) {
  for (int dest = 0; dest < n; dest++) {
    int state = 1 << dest;
    int dx = hx - xs[dest];
    int dy = hy - ys[dest];
    float t = sqrt(dx*dx + dy*dy);

    if (prohibit(t, xs[dest], ys[dest])) return false;
    map[state][dest] = t;
  }

  for (int state = 1; state < (1 << n); state++) {
    for (int dest = 0; dest < n; dest++) {
      if (state & (1 << dest)) {
        int fromstate = state & ~(1 << dest);
        if (fromstate == 0) continue;

        float mi = HUGE_VAL;
        for (int from = 0; from < n; from++) {
          float t = map[fromstate][from]+dist(from, dest);

          if (prohibit(t, xs[dest], ys[dest])) return false;
          mi = min(mi, t);
        }
        map[state][dest] = mi;
      }
    }
  }

  return true;
}

int main(void) {
  for (;;) {
    scanf("%d%d%d%d%d", &n, &hx, &hy, &dx, &dy);
    if (n == 0 && hx == 0 && hy == 0 && dx == 0 && dy == 0) break;
    rep (i, n) scanf("%d%d", xs+i, ys+i);
    if (solve()) {
      printf("YES\n");
    } else {
      printf("NO\n");
    }
  }
  return 0;
}

