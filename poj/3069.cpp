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
  int R, n;
  int v[1001];
  for (;;) {
    cin >> R >> n;
    if (R == -1 && n == -1) break;
    rep (i, n) cin >> v[i];
    sort(v, v+n);
    
    int *up = v;
    int count = 0;
    while (up != v+n) {
      up = upper_bound(up, v+n, *up+R)-1;
      up = upper_bound(up, v+n, *up+R);
      count++;
    }
    cout << count << endl;
  }
  

  return 0;
}
