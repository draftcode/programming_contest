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

int sqr(int x) { return x * x; }

int main(void) {
    int n;
    scanf("%d", &n);
    rep(i, n) {
        int arr[3];
        scanf("%d%d%d", arr, arr+1, arr+2);
        sort(arr, arr+3);
        if (sqr(arr[0]) + sqr(arr[1]) == sqr(arr[2])) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}
