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

long gcd(long m, long n) {
    if (m < n) swap(m,n);
    if (n == 0) return m;
    for (;;) {
        if (m % n == 0) return n;
        long t;
        t = m % n;
        m = n;
        n = t;
    }
}

int main(void) {
    long a, b;
    while (scanf("%ld%ld", &a, &b) == 2) {
        long cd = gcd(a, b);
        long cm = (a/cd) * (b/cd) * cd;
        printf("%ld %ld\n", cd, cm);
    }
    return 0;
}
