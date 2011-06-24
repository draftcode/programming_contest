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

int main(void) {
    int a, b, c, d, e, f;
    while (scanf("%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f) == 6) {
        double x = ((b*f-c*e)*1.0)/((b*d-a*e)*1.0);
        double y = ((c*d-a*f)*1.0)/((b*d-a*e)*1.0);
        x = round(x * 1000.0)/1000.0;
        y = round(y * 1000.0)/1000.0;
        if (x == 0.0) { x = abs(x); }
        if (y == 0.0) { y = abs(y); }
        printf("%.3f %.3f\n", x, y);
    }
    return 0;
}
