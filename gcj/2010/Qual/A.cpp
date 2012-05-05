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

int C, I;
P items[2001];

int main(void) {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  rep (_i, n) {
    cin >> C; cin >> I;
    rep (i, I) {
      int k;
      cin >> k;
      items[i] = P(k, i);
    }

    sort(items, items+I);
    rep (i, I) {
      P *p = lower_bound(items+i+1, items+I, P(C-items[i].first, 0));
      if (p->first == C-items[i].first) {
        if (items[i].second < p->second) {
          cout << "Case #" << _i + 1 << ": " << items[i].second + 1 << ' ' << p->second + 1 << endl;
        } else {
          cout << "Case #" << _i + 1 << ": " << p->second + 1 << ' ' << items[i].second + 1 << endl;
        }
        break;
      }
    }

  }
  return 0;
}

