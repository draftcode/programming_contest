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

int pv[2000];
bool isp[20000];
void calc_primes(void) {
  pv[0] = 2;
  isp[2] = true;
  int count = 1;
  for (int i = 3; i < 1 << 15 && count < 2000; i+=2) {
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
      isp[i] = true;
    }
  }
}

int dp[10001];
void solve(void) {
  for (int i = 0; pv[i] <= 10000; i++) {
    int sum = 0;
    for (int k = i; sum + pv[k] <= 10000; k++) {
      sum += pv[k];
      dp[sum]++;
    }
  }
}

int main(void) {
  calc_primes();
  solve();
  for (;;) {
    int n;
    scanf("%d", &n);
    if (n == 0) break;
    printf("%d\n", dp[n]);
  }
  return 0;
}

















