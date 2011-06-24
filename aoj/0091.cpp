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

int n;
int board[10][10];

bool check(void) {
    rep(x, 10) {
        rep(y, 10) {
            if (board[x][y] != 0) return false;
        }
    }
    return true;
}

int large_x[] = {-2,-1,-1,-1,0,0,0,0,0,1,1,1,2};
int large_y[] = {0,-1,0,1,-2,-1,0,1,2,-1,0,1,0};
int mid_x[] = {-1,-1,-1,0,0,0,1,1,1};
int mid_y[] = {-1,0,1,-1,0,1,-1,0,1};
int small_x[] = {-1,0,0,0,1};
int small_y[] = {0,-1,0,1,0};

bool try_put(int x, int y, int* dx, int* dy, int count) {
    rep (i, count) {
        if (0 <= x+dx[i] && x+dx[i] <= 9 && 0 <= y+dy[i] && y+dy[i] <= 9) {
            if (board[x+dx[i]][y+dy[i]] == 0) {
                return false;
            }
        } else {
            return false;
        }
    }
    return true;
}

void put(int x, int y, int* dx, int* dy, int count, int d) {
    rep (i, count) {
        board[x+dx[i]][y+dy[i]] += d;
    }
}

bool solve(int k) {
    if (k == n) return check();

    rep (x, 10) {
        rep (y, 10) {
            if (board[x][y] != 0) {
                if (try_put(x, y, large_x, large_y, 13)) {
                    put(x, y, large_x, large_y, 13, -1);
                    if (solve(k+1)) {
                        printf("%d %d 3\n", x, y);
                        return true;
                    } else {
                        put(x, y, large_x, large_y, 13, 1);
                    }
                }
                if (try_put(x, y, mid_x, mid_y, 9)) {
                    put(x, y, mid_x, mid_y, 9, -1);
                    if (solve(k+1)) {
                        printf("%d %d 2\n", x, y);
                        return true;
                    } else {
                        put(x, y, mid_x, mid_y, 9, 1);
                    }
                }
                if (try_put(x, y, small_x, small_y, 5)) {
                    put(x, y, small_x, small_y, 5, -1);
                    if (solve(k+1)) {
                        printf("%d %d 1\n", x, y);
                        return true;
                    } else {
                        put(x, y, small_x, small_y, 5, 1);
                    }
                }
            }
        }
    }
    return false;
}

int main(void) {
    for (;;) {
        scanf("%d", &n);
        if (n == -1) break;

        rep(x, 10) {
            rep(y, 10) {
                scanf("%d", &board[x][y]);
            }
        }

        solve(0);
        putchar('\n');
    }
    return 0;
}
