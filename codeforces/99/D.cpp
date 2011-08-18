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

ll gcd(ll m, ll n) {
    if (m < n) swap(m,n);
    if (n == 0) return m;
    for (;;) {
        if (m % n == 0) return n;
        ll t;
        t = m % n;
        m = n;
        n = t;
    }
}

int main(void) {
  ll n, t = 1;
  int k = 0;
  cin >> n;
  while (n > t) {
    k++;
    t <<= 1;
  }

  ll denom = t*k, numer = n;
  ll g = gcd(denom, numer);
  if (denom == 0) numer = 0;
  cout << denom/g << "/" << numer/g << endl;
  return 0;
}
