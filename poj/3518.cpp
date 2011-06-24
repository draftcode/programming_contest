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

char isnotprime[1299710];
void calc_primes(void) {
  for (int i = 2; i < 1150; i++) {
    if (isnotprime[i] == 0) {
      for (int k = 2; k*i < 1299710; k++) {
        isnotprime[k*i] = 1;
      }
    }
  }
}

int main(void) {
  calc_primes();
  for (;;) {
    int n;
    scanf("%d", &n);
    if (n == 0) break;

    int ret = 0;
    if (isnotprime[n] != 0) {
      for (int i = n; isnotprime[i] == 1; i--) {
        ret++;
      }
      for (int i = n+1; isnotprime[i] == 1; i++) {
        ret++;
      }
      ret++;
    }

    printf("%d\n", ret);
  }
  return 0;
}
