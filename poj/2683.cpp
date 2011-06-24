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

int simple(int amount, int years, double pct, int comm) {
    int interests = 0;
    rep (y, years) {
        interests += amount * pct;
        amount -= comm;
    }
    return amount + interests;
}

int compound(int amount, int years, double pct, int comm) {
    rep (y, years) {
        int interest = amount * pct;
        amount += interest - comm;
    }
    return amount;
}

int main(void) {
    int m;
    scanf("%d", &m);
    rep (_i, m) {
        int amount, years, n;
        scanf("%d%d%d", &amount, &years, &n);
        int mx = 0;
        rep (__i, n) {
            int kind, comm;
            float pct;
            scanf("%d%f%d", &kind, &pct, &comm);
            if (kind == 0) {
                mx = max(mx, simple(amount, years, pct, comm));
            } else {
                mx = max(mx, compound(amount, years, pct, comm));
            }
        }
        printf("%d\n", mx);
    }
    return 0;
}
