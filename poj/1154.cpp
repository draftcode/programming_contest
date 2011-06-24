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

int r, c;
char map[22][22];
char used[26];

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int solve(int x, int y) {
  int ret = 0;
  rep (i, 4) {
    if (0 <= x+dx[i] && x+dx[i] < c && 0 <= y+dy[i] && y+dy[i] < r) {
      if (used[map[y+dy[i]][x+dx[i]] - 'A'] == 0) {
        used[map[y+dy[i]][x+dx[i]] - 'A'] = 1;
        ret = max(ret, solve(x+dx[i], y+dy[i]));
        used[map[y+dy[i]][x+dx[i]] - 'A'] = 0;
      }
    }
  }
  return ret + 1;
}

int main(void) {
  scanf("%d%d", &r, &c);
  rep (i, r) {
    scanf("%s", map+i);
  }
  zclear(used);
  used[map[0][0]-'A'] = 1;
  printf("%d\n", solve(0, 0));
  return 0;
}
