#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#include <numeric>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <set>
#include <climits>
using namespace std;
typedef long long ll;

#define rep(i,n) for(int i = 0; i < n; i++)
#define each(it,c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define all(c) (c).begin(), (c).end()
#define zclear(v) memset(v, 0, sizeof(v))

int gcd(int m, int n) {
  if (m < n) swap(m,n);
  if (n == 0) return m;
  for (;;) {
    if (m % n == 0) return n;
    int t;
    t = m % n;
    m = n;
    n = t;
  }
}

int main(void) {
  vector<int> v;

  int n;
  cin >> n;

  rep (i, n) {
    int x, y;
    cin >> x >> y;

    vector<int> g;
    for (int k = 1; k <= y; k++) {
      g.push_back(gcd(v[i-k], x));
    }
    v.push_back(x);

    cout << count << endl;
  }

  return 0;
}
