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

int w, h;

char map[20][20];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
int solve(int x, int y) {
    int count = 1;
    map[x][y] = '#';
    for (int i = 0; i < 4; i++) {
        if (0 <= x+dx[i] && x+dx[i] < w && 0 <= y+dy[i] && y+dy[i] < h) {
            if (map[x+dx[i]][y+dy[i]] == '.') {
                count += solve(x+dx[i], y+dy[i]);
            }
        }
    }
    return count;
}

int main(void) {
    for (;;) {
        scanf("%d%d", &w, &h);
        if (w == 0 && h == 0) break;

        int xs = 0, ys = 0;
        char s[30];
        rep (y, h) {
            scanf("%s", s);
            rep (x, w) {
                if (s[x] == '@') {
                    xs = x; ys = y; s[x] = '.';
                }
                map[x][y] = s[x];
            }
        }

        printf("%d\n", solve(xs, ys));
    }
    return 0;
}
