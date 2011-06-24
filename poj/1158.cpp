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
typedef pair<int, int> ip;

#define rep(i,n) for(int i = 0; i < n; i++)
#define each(it,c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define all(c) (c).begin(), (c).end()
#define zclear(v) memset(v, 0, sizeof(v))

int s, g;
int n, m;
bool init[300]; // false ... purple, true ... blue
int tb[300];
int tp[300];
int rem[300];
vector<pair<int, int> > edges[300];
int visited[300];

bool currcolor(int t, int j, int& r) {/*{{{*/
  if (t < rem[j]) { r = rem[j] - t; return init[j];  }
  int d = (t-rem[j]) % (tb[j]+tp[j]);
  if (init[j]) {
    if (d < tp[j]) {
      r = tp[j] - d;
      return false;
    } else {
      r = tb[j] + tp[j] - d;
      return true;
    }
  } else {
    if (d < tb[j]) {
      r = tb[j] - d;
      return true;
    } else {
      r = tb[j] + tp[j] - d;
      return false;
    }
  }
}/*}}}*/

int nextpassable(int t, int j1, int j2) {/*{{{*/
  // -1 if unpassable
  int r1, r2;
  bool c1, c2;
  c1 = currcolor(t, j1, r1);
  c2 = currcolor(t, j2, r2);
  if (c1 == c2) {
    return 0;
  } else if (r1 != r2) {
    return min(r1, r2);
  } else {
    int ret = r1;
    c1 = currcolor(t+ret, j1, r1);
    c2 = currcolor(t+ret, j2, r2);
    if (r1 == r2) {
      ret += r1;
      c1 = currcolor(t+ret, j1, r1);
      c2 = currcolor(t+ret, j2, r2);
      if (r1 == r2) {
        return -1;
      } else {
        return ret + min(r1, r2);
      }
    } else {
      return ret + min(r1, r2);
    }
  }
}/*}}}*/

int solve(void) {
  zclear(visited);

  priority_queue<ip, vector<ip>, greater<ip> > que;
  que.push(make_pair(0, s));
  while (!que.empty()) {
    ip p = que.top(); que.pop();
    if (p.second == g) return p.first;
    if (visited[p.second] != 1) { visited[p.second] = 1; } else { continue; }

    each(it, edges[p.second]) {
      ip e = *it;
      if (visited[e.first] != 1) {
        int d = nextpassable(p.first, p.second, e.first);
        if (d >= 0) {
          que.push(make_pair(p.first+d+e.second, e.first));
        }
      }
    }
  }

  return 0;
}

int main(void) {/*{{{*/
  scanf("%d%d", &s, &g);
  s--; g--;
  scanf("%d%d", &n, &m);
  rep (i, n) {
    char ci;
    int ri, tib, tip;
    scanf("%*[^BP]%c%d%d%d", &ci, &ri, &tib, &tip);
    init[i] = ci == 'B' ? true : false;
    tb[i] = tib;
    tp[i] = tip;
    rem[i] = ri;
  }

  rep (i, m) {
    int s, g, l;
    scanf("%d%d%d", &s, &g, &l);
    edges[s-1].push_back(make_pair(g-1, l));
    edges[g-1].push_back(make_pair(s-1, l));
  }

  printf("%d\n", solve());
  return 0;
}/*}}}*/

