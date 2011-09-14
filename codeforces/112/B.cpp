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
  int n, x, y;
  cin >> n >> x >> y;

  int kx, ky;
  if (x < n/2) {
    kx = n/2 - x + 1;
  } else {
    kx = x - n/2;
  }

  if (y < n/2) {
    ky = n/2 - y + 1;
  } else {
    ky = y - n/2;
  }

  int k = max(kx, ky);

  if (k <= 1) {
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;
  }

  return 0;
}
