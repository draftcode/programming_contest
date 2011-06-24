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
  int n;
  scanf("%d", &n);
  rep (i, n) {
    int s, e;
    scanf("%d%d", &s, &e);
    ll range = e-s+1;
    printf("Scenario #%d:\n%lld\n", i+1, (s+e)*range/2);
    if (i != n-1) putchar('\n');
  }
  return 0;
}
