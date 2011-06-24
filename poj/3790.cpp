#include <iostream>
#include <cstring>
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

int dp[3000];

void calc(void) {
    for (int i = 1; i < 3000; i++) {
        dp[i] = 1;
        if (i%2 == 0) dp[i] += dp[i/2];
        for (int k = 1; k < i; k++) {
            if ((i-k)%2 == 0) {
                dp[i] += dp[(i-k)/2];
            }
        }
    }
}

int main(void) {
    zclear(dp);
    calc();
    int n;
    cin >> n;
    rep (i, n) {
        int k;
        cin >> k;
        cout << i+1 << " " << dp[k] << endl;
    }
    return 0;
}
