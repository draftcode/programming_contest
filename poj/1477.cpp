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

int main(void) {
  int hi[50];
  int count = 1;
  for (;;) {
    int n;
    scanf("%d", &n);
    if (n == 0) break;

    int t = 0;
    rep (i, n) {
      scanf("%d", hi+i);
      t += hi[i];
    }
    t /= n;

    int ret = 0;
    rep (i, n) {
      if (hi[i] > t) {
        ret += hi[i] - t;
      }
    }

    printf("Set #%d\nThe minimum number of moves is %d.\n\n", count, ret);
    count ++;
  }
  return 0;
}
