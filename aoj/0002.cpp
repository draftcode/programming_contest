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
    int x, y;
    while (scanf("%d%d", &x, &y) == 2) {
        int z = x + y;
        int count = 0;
        while (z != 0) {
            z /= 10;
            count++;
        }
        printf("%d\n", count);
    }
    return 0;
}
