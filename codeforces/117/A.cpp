#include <algorithm>
#include <functional>
#include <iostream>
#include <limits>
#include <numeric>
#include <queue>
#include <vector>

#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

#define rep(i,n) for(int i = 0; i < n; i++)
#define each(it,c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)

ll n, m;
bool is_up(ll t) {
  return (t/(m-1) % 2) == 0;
}

ll floor(ll t) {
  ll q = t%(m-1);
  if (is_up(t)) {
    return q+1;
  } else {
    return m-q;
  }
}

ll how_long(ll s, ll f, ll t) {
  if (s == f) {
    return 0;
  } else if (s > f) {
    if (is_up(t)) {
      return (m-s)+(m-f);
    } else {
      return s-f;
    }
  } else {
    if (is_up(t)) {
      return f-s;
    } else {
      return f+s-2;
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin >> n >> m;
  rep (i, n) {
    ll s, f, t;
    cin >> s >> f >> t;
    if (s == f) {
      cout << t << endl;
    } else {
      t += how_long(floor(t), s, t);
      t += how_long(s, f, t);
      cout << t << endl;
    }
  }
  
  return 0;
}
