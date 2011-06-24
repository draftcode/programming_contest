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

int main(void) {
    int n, m, c;
    for (;;) {
        scanf("%d%d%d", &n, &m, &c);
        if (n == 0 && m == 0 && c == 0) break;

        m -= 7;
        n -= 7;
        int r = 0;
        if (c == 0) {
            if (m % 2 == 0) {
                r = (m/2) * n;
            } else if (n % 2 == 0) {
                r = (n/2) * m;
            } else {
                r = (m/2)*(n/2+1) + (m/2+1)*(n/2);
            }
        } else {
            if (m % 2 == 0) {
                r = (m/2) * n;
            } else if (n % 2 == 0) {
                r = (n/2) * m;
            } else {
                r = (m/2)*(n/2) + (m/2+1)*(n/2+1);
            }
        }
        printf("%d\n", r);
    }
    return 0;
}
