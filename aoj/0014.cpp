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
    int d;
    while (scanf("%d", &d) == 1) {
        int ret = 0;
        for (int i = 0; i < 600; i += d) {
            ret += d * i * i;
        }
        cout << ret << endl;
    }
    return 0;
}
