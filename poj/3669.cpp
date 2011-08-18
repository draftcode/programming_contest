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
typedef pair<int, pair<int, int> > ppp;
ppp make(int t, int x, int y) { return make_pair(t, make_pair(x, y)); }
int get_time(ppp p) { return p.first; }
int get_x(ppp p) { return p.second.first; }
int get_y(ppp p) { return p.second.second; }

#define rep(i,n) for(int i = 0; i < n; i++)
#define each(it,c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define all(c) (c).begin(), (c).end()
#define zclear(v) memset(v, 0, sizeof(v))

int M;
int t[305][305];

int calc(void) {
  priority_queue<ppp, vector<ppp>, greater<ppp> > que;
  que.push(make(0,0,0));

  while (!que.empty()) {
    ppp p = que.top(); que.pop();
    int x, y, ti;
    x = get_x(p); y = get_y(p); ti = get_time(p);
    if (t[x][y] == INT_MAX) {
      return ti;
    } else if (t[x][y] <= ti) {
      continue;
    }

    t[x][y] = ti;
    ti++;
    if (0 <= x-1)   que.push(make(ti, x-1, y));
    if (0 <= y-1)   que.push(make(ti, x, y-1));
    if (x+1 <= 304) que.push(make(ti, x+1, y));
    if (y+1 <= 304) que.push(make(ti, x, y+1));
  }

  return -1;
}

int main(void) {
  scanf("%d", &M);
  rep (x, 304) rep(y, 304) {
    t[x][y] = INT_MAX;
  }

  rep (i, M) {
    int x, y, ti;
    scanf("%d%d%d", &x, &y, &ti);
    t[x][y] = min(t[x][y], ti);
    if (0 <= x-1) t[x-1][y] = min(t[x-1][y], ti);
    if (0 <= y-1) t[x][y-1] = min(t[x][y-1], ti);
    if (x+1 <= 300) t[x+1][y] = min(t[x+1][y], ti);
    if (y+1 <= 300) t[x][y+1] = min(t[x][y+1], ti);
  }

  printf("%d\n", calc());
  return 0;
}

