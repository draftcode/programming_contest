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
typedef pair<int, int> ip;

#define rep(i,n) for(int i = 0; i < n; i++)
#define each(it,c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define all(c) (c).begin(), (c).end()
#define zclear(v) memset(v, 0, sizeof(v))

struct state {
  int t, x, y, isleft;
  state(int t, int x, int y, int isleft) : t(t), x(x), y(y), isleft(isleft) { }
  bool operator <(const state &rhs) const {
    return t > rhs.t;
  }
};

int w, h;
char map[31][61];
char visited[31][61][2];

int dx[2][9] = { { 1, 1, 1, 1, 1, 2, 2, 2, 3 }, { -3, -2, -2, -2, -1, -1, -1, -1, -1 } };
int dy[2][9] = { { 2, 1, 0, -1, -2, 1, 0, -1, 0 }, { 0, 1, 0, -1, 2, 1, 0, -1, -2 } };

int solve(vector<ip> &starts) {
  zclear(visited);

  priority_queue<state> que;
  each (it, starts) {
    que.push(state(0, it->first, it->second, 1));
    que.push(state(0, it->first, it->second, 0));
  }

  while (!que.empty()) {
    state s = que.top(); que.pop();

    if (map[s.x][s.y] == 'T') return s.t;

    if (visited[s.x][s.y][s.isleft] == 1) continue;
    else visited[s.x][s.y][s.isleft] = 1;

    int nl = s.isleft^1;
    rep (i, 9) {
      int nx = s.x+dx[nl][i], ny = s.y+dy[nl][i];
      if (0 < nx && nx <= w && 0 < ny && ny <= h) {
        if (visited[nx][ny][nl] == 0) {
          if (map[nx][ny] == 'T') {
            que.push(state(s.t, nx, ny, nl));
          } else if (isdigit(map[nx][ny])) {
            que.push(state(s.t+map[nx][ny]-'0', nx, ny, nl));
          }
        }
      }
    }
  }
  return -1;
}

int main(void) {
  for (;;) {
    scanf("%d%d", &w, &h);

    if (w == 0 && h == 0) break;

    vector<ip> starts;
    rep (y, h) {
      rep (x, w) {
        char c;
        scanf("%*[^0-9STX]%c", &c);
        map[x+1][y+1] = c;
        if (c == 'S') starts.push_back(make_pair(x+1, y+1));
      }
    }
    printf("%d\n", solve(starts));
  }
  return 0;
}
