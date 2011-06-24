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

int pv[4000];
char isprime[40000];
void calc_primes(void) {
  zclear(isprime);
  pv[0] = 2;
  isprime[2] = 1;
  int count = 1;
  for (int i = 3; i < 1 << 15; i+=2) {
    int b = true;
    for (int j = 0; j < count; j++) {
      if (pv[j] * pv[j] > i) break;
      if (i % pv[j] == 0) {
        b = false;
        break;
      }
    }
    if (b) {
      pv[count++] = i;
      isprime[i] = 1;
    }
  }
}

int main(void) {
  calc_primes();
  for (;;) {
    int n;
    scanf("%d", &n);
    if (n == 0) break;
    int count = 0;
    for (int i = 0; pv[i] <= n/2; i++) {
      if (isprime[n-pv[i]] == 1) {
        count++;
      }
    }
    printf("%d\n", count);
  }
  return 0;
}
