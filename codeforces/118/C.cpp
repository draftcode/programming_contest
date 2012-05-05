#include <algorithm>
#include <functional>
#include <iostream>
#include <limits>
#include <numeric>
#include <queue>
#include <sstream>
#include <vector>

#include <climits>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

#define rep(i,n) for(int i = 0; i < n; i++)
#define each(it,c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
int n, k;
string s;
int cnt[10];
int costs[10];
int table[10][10];

int main(void) {
  ios::sync_with_stdio(false);
  cin >> n >> k;
  s.reserve(n+1);
  cin >> s;

  rep (i, s.size()) {
    cnt[s[i]-'0']++;
  }

  int min_cost = INT_MAX;
  rep (to, 10) {
    int num = cnt[to];
    int cost = 0;
    int diff = 1;
    while (diff < 10 && num < k) {
      if (num < k && 0 <= to+diff && to+diff <= 9) {
        int sub = min(k-num, cnt[to+diff]);
        cost += sub*diff;
        num += sub;
        table[to][to+diff] = sub;
      }

      if (num < k && 0 <= to-diff && to-diff <= 9) {
        int sub = min(k-num, cnt[to-diff]);
        cost += sub*diff;
        num += sub;
        table[to][to-diff] = sub;
      }
      diff++;
    }
    costs[to] = cost;
    if (min_cost > cost) {
      min_cost = cost;
    }
  }

  vector<string> v;
  rep (k, 10) {
    if (costs[k] == min_cost) {
      string t(s);
      rep (j, 10) {
        if (j > k) {
          for (int i = 0; i < s.size() && table[k][j] > 0; i++) {
            if (t[i] == j + '0') {
              t[i] = k + '0';
              table[k][j]--;
            }
          }
        } else if (j < k) {
          for (int i = s.size()-1; i >= 0 && table[k][j] > 0; i--) {
            if (t[i] == j + '0') {
              t[i] = k + '0';
              table[k][j]--;
            }
          }
        }
      }
      v.push_back(t);
    }
  }
  sort(v.begin(), v.end());
  cout << min_cost << endl << v[0] << endl;

  return 0;
}
