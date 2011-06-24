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

int l, xs, ys, xg, yg;
int map[300][300];

struct state {
  int d, x, y;
  state(int _d, int _x, int _y) : d(_d), x(_x), y(_y) { }
  bool operator <(const state& rhs) const {
    return d > rhs.d;
  }
};

int dx[] = { -2, -2, -1, -1, 1, 1, 2, 2 };
int dy[] = { 1, -1, 2, -2, 2, -2, 1, -1 };
int solve(void) {
  zclear(map);
  priority_queue<state> que;
  que.push(state(0, xs, ys));
  while (!que.empty()) {
    state s = que.top(); que.pop();

    if (s.x == xg && s.y == yg) return s.d;
    if (map[s.y][s.x] == 0) { map[s.y][s.x] = s.d; } else { continue; }

    rep (i, 8) {
      if (0 <= s.x+dx[i] && s.x+dx[i] < l && 0 <= s.y+dy[i] && s.y+dy[i] < l) {
        if (map[s.y+dy[i]][s.x+dx[i]] == 0) {
          que.push(state(s.d+1, s.x+dx[i], s.y+dy[i]));
        }
      }
    }
  }
  return 0;
}

int main(void) {
  int n;
  scanf("%d", &n);
  rep (i, n) {
    scanf("%d%d%d%d%d", &l, &xs, &ys, &xg, &yg);
    printf("%d\n", solve());
  }
  return 0;
}
