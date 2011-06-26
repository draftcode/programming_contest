#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
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

int map[5][5];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

inline bool ok(int x, int y) {
  return (0 <= x && x < 5 && 0 <= y && y < 5);
}

int solve(int x, int y, int d1, int d2, int d3, int d4, int d5) {
  int ret = map[x][y];
  if (ok(x+=dx[d1], y+=dy[d1])) { ret *= 10; ret += map[x][y]; } else return -1;
  if (ok(x+=dx[d2], y+=dy[d2])) { ret *= 10; ret += map[x][y]; } else return -1;
  if (ok(x+=dx[d3], y+=dy[d3])) { ret *= 10; ret += map[x][y]; } else return -1;
  if (ok(x+=dx[d4], y+=dy[d4])) { ret *= 10; ret += map[x][y]; } else return -1;
  if (ok(x+=dx[d5], y+=dy[d5])) { ret *= 10; ret += map[x][y]; } else return -1;
  return ret;
}

int main(void) {
  rep (y, 5) rep (x, 5) scanf("%d", map[y]+x);

  set<int> s;
  rep (d1, 4) {
    rep (d2, 4) {
      rep (d3, 4) {
        rep (d4, 4) {
          rep (d5, 4) {
            rep (y, 5) {
              rep (x, 5) {
                int ret = solve(x, y, d1, d2, d3, d4, d5);
                if (ret != -1) s.insert(ret);
              }
            }
          }
        }
      }
    }
  }

  printf("%ld\n", s.size());

  return 0;
}
