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

int revert(int q, int from, int to) {
  if (q < from || to < q) return q;
  int num_reverts = to - from + 1;
  int center = num_reverts / 2 + from;
  int diff = center - q;

  if (num_reverts % 2 == 0) {
    return center + diff - 1;
  } else {
    return center + diff;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  int t = 1;
  for (;;) {
    int N; cin >> N; if (N == 0) break;
    int R; cin >> R;
    vector<P> reverts;
    rep (i, R) {
      int a, b; cin >> a >> b;
      reverts.push_back(P(a, b));
    }

    cout << "Genome " << t << endl;
    int Q; cin >> Q;
    rep (i, Q) {
      int q; cin >> q;
      each (it, reverts) {
        q = revert(q, it->first, it->second);
      }
      cout << q << endl;
    }
    t++;
  }
  return 0;
}
