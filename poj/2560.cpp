#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#include <complex>
#include <set>
#include <numeric>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <climits>
using namespace std;
typedef long long ll;
typedef complex<double> point;

#define rep(i,n) for(int i = 0; i < n; i++)
#define each(it,c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define all(c) (c).begin(), (c).end()
#define zclear(v) memset(v, 0, sizeof(v))

int n;
point v[100];
double d[100][100];
bool visited[100];

double dist(point v1, point v2) {
  return abs(v1-v2);
}

int main(void) {
  scanf("%d", &n);

  rep (i, n) {
    double x, y;
    scanf("%lf%lf", &x, &y);
    v[i] = point(x, y);
  }

  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      double di = dist(v[i], v[j]);
      d[i][j] = di;
      d[j][i] = di;
    }
  }

  priority_queue<pair<double, int>, vector<pair<double, int> >, greater<pair<double, int> > > que;
  for (int i = 1; i < n; i++) {
    que.push(make_pair(d[0][i], i));
  }
  visited[0] = true;

  double ret = 0.0;
  int count = 1;
  while (count != n) {
    pair<double, int> p = que.top(); que.pop();
    if (visited[p.second]) continue;
    ret += p.first;
    visited[p.second] = true;
    count++;

    for (int i = 0; i < n; i++) {
      if (!visited[i]) {
        que.push(make_pair(d[p.second][i], i));
      }
    }
  }

  printf("%.2f\n", ret);

  return 0;
}

