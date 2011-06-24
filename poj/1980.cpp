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

int a, n;

int solve(int p, int q, int prev, int b, int k) {
  if (p == 0) return 1;
  if (k == n) return 0;

  int ret = 0;
  for (int i = prev; b*i <= a; i++) {
    int np = p*i - q;
    int nq = q*i;
    if (np >= 0) {
      ret += solve(np, nq, i, b*i, k+1);
    }
  }
  return ret;
}

int main(void) {
  for (;;) {
    int p, q;
    scanf("%d%d%d%d", &p, &q, &a, &n);
    if (p == 0) break;

    printf("%d\n", solve(p, q, 1, 1, 0));
  }
  return 0;
}
