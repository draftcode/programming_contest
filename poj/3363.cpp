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
#define each(c,it) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define all(c) (c).begin(), (c).end()
#define zclear(v) memset(v, 0, sizeof(v))

// n ... rows
// m ... cols
int n, m, r, c;
bool pic[100][100];

int solve(void) {
    int ret = 0;
    rep (y, n) {
        rep (x, m) {
            if (pic[x][y]) {
                if (x+c-1 < m && y+r-1 < n) {
                    rep(dx, c) {
                        rep(dy, r) {
                            pic[x+dx][y+dy] = !pic[x+dx][y+dy];
                        }
                    }
                    ret += 1;
                } else {
                    return -1;
                }
            }
        }
    }
    return ret;
}

int main(void) {
    for (;;) {
        scanf("%d%d%d%d", &n, &m, &r, &c);
        if (n == 0 && m == 0 && r == 0 && c == 0) return 0;
        rep (y, n) {
            rep (x, m) {
                char c;
                do {
                    scanf("%c", &c);
                } while (c != '1' && c != '0');
                if (c == '1') {
                    pic[x][y] = true;
                } else {
                    pic[x][y] = false;
                }
            }
        }
        printf("%d\n", solve());
    }

    return 0;
}
