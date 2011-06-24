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

int main(void) {
    for (int a = 1; a <= 2000; a++) {
        for (int b = a; b <= 2000-a; b++) {
            for (int c = b; c <= 2000-b-a; c++) {
                for (int d = c; d <= 2000-c-b-a; d++) {
                    if (a + b + c + d == a * b * c * d) {
                        printf("%d %d %d %d\n", a, b, c, d);
                    }
                }
            }
        }
    }
    return 0;
}
