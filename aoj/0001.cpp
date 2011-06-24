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
    int arr[10];
    rep (i, 10) scanf("%d", arr+i);
    sort(arr, arr+10, greater<int>());
    printf("%d\n%d\n%d\n", arr[0], arr[1], arr[2]);
    return 0;
}
