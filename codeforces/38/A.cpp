#include <algorithm>
#include <functional>
#include <iostream>
#include <limits>
#include <numeric>
#include <queue>
#include <sstream>
#include <vector>

#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

#define rep(i,n) for(int i = 0; i < n; i++)
#define each(it,c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)

int main(void) {
  ios::sync_with_stdio(false);
  int n; cin >> n;
  vector<int> v(n, 0);
  rep (i, n-1) cin >> v[i];

  int a, b; cin >> a >> b;
  vector<int>::iterator from = v.begin()+(a-1);
  vector<int>::iterator to = v.begin()+(b-1);

  int ans = 0;
  while (from != to) {
    ans += *from;
    from++;
  }
  cout << ans << endl;
  return 0;
}
