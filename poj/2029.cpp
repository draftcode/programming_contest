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

int n, w, h, s, t;
char map[100][100];

int solve(void) {
    int mx = 0;
    rep (y, h) {
        rep (x, w) {
            if (x+s <= w && y+t <= h) {
                int count = 0;
                rep (dy, t) {
                    rep (dx, s) {
                        if (map[x+dx][y+dy] == 1) {
                            count++;
                        }
                    }
                }
                mx = max(mx, count);
            }
        }
    }
    return mx;
}

int main(void) {
    for (;;) {
        if (scanf("%d%d%d", &n, &w, &h) == 1) break;
        zclear(map);

        rep (_i, n) {
            int x, y;
            scanf("%d%d", &x, &y);
            map[x-1][y-1] = 1;
        }

        scanf("%d%d", &s, &t);
        printf("%d\n", solve());
    }
    return 0;
}
