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

double pi;
double case1(double w, double h) {
    return (w*w*(h-w/pi))/(4*pi);
}

double case2(double w, double h) {
    double t = h/(pi+1) > w ? w : h/(pi+1);
    return (pi*w*t*t)/4;
}

int main(void) {
    pi = acos(-1);
    for (;;) {
        int w, h;
        scanf("%d%d", &w, &h);
        if (w == 0 && h == 0) break;

        double ans1 = round(case1(w, h) * 1000.0)/1000.0;
        double ans2 = round(case2(w, h) * 1000.0)/1000.0;
        printf("%.3f\n", max(ans1, ans2));
    }
    return 0;
}
