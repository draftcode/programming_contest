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
  printf("n e\n- -----------\n");
  int r[10], q[10];
  r[0] = q[0] = 1;
  for (int i = 1; i < 10; i++) {
    q[i] = q[i-1] * i;
    r[i] = 0;
    for (int j = 0; j <= i; j++) {
      r[i] += q[i] / q[j];
    }
  }

  for (int i = 0; i < 10; i++) {
    if (i < 2) {
      printf("%d %.0f\n", i, r[i]*1.0/q[i]);
    } else if (i < 3) {
      printf("%d %.1f\n", i, r[i]*1.0/q[i]);
    } else {
      printf("%d %.9f\n", i, r[i]*1.0/q[i]);
    }
  }
  return 0;
}
