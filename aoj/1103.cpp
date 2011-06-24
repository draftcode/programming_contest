#include <iostream>
#include <cstdio>
#include <climits>
#include <queue>
#include <cmath>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
typedef long long ll;

#define rep(i,n) for(int i = 0; i < n; i++)
#define each(c,it) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define all(c) (c).begin(), (c).end()
#define zclear(v) memset(v, 0, sizeof(v))

int dx[4];
int dy[4];
bool board[4][4];
bool exist(int x, int y) {
    if (0 <= x && x <= 3 && 0 <= y && y <= 3) {
        return board[x][y];
    }
    return true;
}

int solve(int k) {
    if (k == 8) return 1;

    int p_x = 4, p_y = 4;
    rep(y, 4) {
        rep(x, 4) {
            if (!exist(x,y)) {
                p_x = x, p_y = y;
                break;
            }
        }
        if (p_x != 4) break;
    }

    int ret = 0;
    if (!exist(p_x,p_y)) {
        board[p_x][p_y] = true;
        rep(i, 4) {
            if (!exist(p_x+dx[i], p_y+dy[i])) {
                board[p_x+dx[i]][p_y+dy[i]] = true;
                ret += solve(k+1);
                board[p_x+dx[i]][p_y+dy[i]] = false;
            }
        }
        board[p_x][p_y] = false;
    }
    return ret;
}

int main(void) {
    for (;;) {
        rep (i,4) {
            if (scanf("%d%d", dx+i, dy+i) != 2) {
                return 0;
            }
        }
        rep(x, 4) {
            rep(y, 4) {
                board[x][y] = false;
            }
        }
        printf("%d\n", solve(0));
    }
    return 0;
}
