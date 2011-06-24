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

int m;
int solve(int safe, int fail, int k) {
  if (k == 1) {
    return max(fail*(fail-1)/2, (m*(m+1)-safe*(safe+1))/2);
  }

  int mi = INT_MAX;
  for (int i = safe; i < fail; i++) {
    mi = min(mi, solve(safe, i,  k-1));
  }
  for (int i = fail;  safe < i; i--) {
    mi = min(mi, solve(i, fail,  k-1));
  }
  return mi;
}

int main(void) {
  int n;
  scanf("%d", &n);
  rep (_i, n) {
    int k;
    scanf("%d%d", &k, &m);
    printf("%d\n", solve(0, m+1, k));
  }
  return 0;
}
