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

int days[100];
int main(void) {
    int N, Q;
    for (;;) {
        scanf("%d%d", &N, &Q);
        if (N == 0 && Q == 0) break;

        zclear(days);
        int mx = 0;
        rep (_i, N) {
            int M;
            scanf("%d", &M);
            rep (__i, M) {
                int day;
                scanf("%d", &day);
                days[day]++;
                mx = max(mx, days[day]);
            }
        }

        if (mx < Q) {
            printf("%d\n", 0);
        } else {
            rep (i, 100) {
                if (days[i] == mx) {
                    printf("%d\n", i);
                    break;
                }
            }
        }
    }
    return 0;
}
