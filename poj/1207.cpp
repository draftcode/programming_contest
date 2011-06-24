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

int solve(ll n) {
  if (n == 1) return 1;
  if ((n%2) == 1) {
    return 1+solve(3*n+1);
  } else {
    return 1+solve(n/2);
  }
}

int main(void) {
  int i, j;
  while (scanf("%d%d", &i, &j) == 2) {
    int mx = 0;
    for (int k = (i<j?i:j); k <= (i<j?j:i); k++) {
      mx = max(mx, solve(k));
    }
    printf("%d %d %d\n", i, j, mx);
  }
  return 0;
}
