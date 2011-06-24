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

int pv[30];
void calc_primes(void) {/*{{{*/
  pv[0] = 2;
  int count = 1;
  for (int i = 3; i < 1 << 15 && count < 30; i+=2) {
    bool isprime = true;
    for (int k = 0; k < count; k++) {
      if (pv[k] * pv[k] > i) break;
      if (i % pv[k] == 0) {
        isprime = false;
        break;
      }
    }

    if (isprime) {
      pv[count++] = i;
    }
  }
}/*}}}*/

int factors[100];

long pow(int i, int times) {
  if (times == 0) return 1;
  long ret = i;
  for (int k = 1; k < times; k++) ret *= i;
  return ret;
}

long solve(int n, int m) {
  zclear(factors);
  for (int i = n; i > m; i--) {
    int t = i;
    int c = 0;
    while (t != 1) {
      if (t % pv[c] == 0) {
        factors[pv[c]] += 1;
        t /= pv[c];
      } else {
        c++;
      }
    }
  }

  for (int i = n-m; i >= 2; i--) {
    int t = i;
    int c = 0;
    while (t != 1) {
      if (t % pv[c] == 0) {
        factors[pv[c]] -= 1;
        t /= pv[c];
      } else {
        c++;
      }
    }
  }

  long ret = 1;
  for (int i = 0; i < 100; i++) {
    if (factors[i] > 0) {
      ret *= pow(i, factors[i]);
    }
  }
  return ret;
}

int main(void) {
  calc_primes();
  for (;;) {
    int n, m;
    scanf("%d%d", &n, &m);
    if (n == 0 && m == 0) break;
    printf("%d things taken %d at a time is %ld exactly.\n", n, m, solve(n, m));
  }
  return 0;
}
