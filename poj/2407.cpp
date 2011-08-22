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

long gcd(long m, long n) {
    if (m < n) swap(m,n);
    if (n == 0) return m;
    for (;;) {
        if (m % n == 0) return n;
        long t;
        t = m % n;
        m = n;
        n = t;
    }
}

int main(void) {
  int n;
  while (1) {
    cin >> n;
    if (n == 0) break;

    int ans = n;
    for (int x = 2; x*x <= n; ++x) {
      if (n % x == 0) {
        ans -= ans / x;
        while (n % x == 0) n /= x;
      }
    }

    if (n > 1) ans -= ans / n;
    cout << ans << endl;
  }
  return 0;
}


