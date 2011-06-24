#include <iostream>
#include <cstdio>
#include <climits>
#include <queue>
#include <cmath>
#include <vector>
#include <algorithm>
#include <numeric>
#include <complex>
#define rep(i,n) for(int i = 0; i < n; i++)
#define each(c,it) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define all(c) (c).begin(), (c).end()
#define zclear(v) memset(v, 0, sizeof(v))
using namespace std;
typedef long long ll;

typedef complex<double> point;
namespace std {
    bool operator < (const point& a, const point& b) {
        return real(a) != real(b) ? real(a) < real(b) : imag(a) < imag(b);
    }
}

double cross(const point& a, const point& b) {
    return imag(conj(a)*b);
}

double dot(const point& a, const point& b) {
    return real(conj(a)*b);
}

int main(void) {
    int n;
    int count = 1;
    for (;;) {
        scanf("%d", &n);
        if (n == 0) break;
        vector<point> vec;
        rep (i, n) {
            int x, y;
            scanf("%d%d", &x, &y);
            vec.push_back(point(x,y));
        }

        double ret = 0.0;
        rep (i, n) {
            if (i == n-1) {
                ret += cross(vec[i], vec[0]);
            } else {
                ret += cross(vec[i], vec[i+1]);
            }
        }
        printf("%d %.1f\n", count, abs(ret)/2.0);
        count++;
    }
    return 0;
}
