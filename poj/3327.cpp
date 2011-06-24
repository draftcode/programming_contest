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

int n, w, d;
struct cake {
  int xs, ys, xg, yg;
  cake(int sx, int sy, int gx, int gy) : xs(sx), ys(sy), xg(gx), yg(gy) {}
  cake cut(int s) {
    // return the smaller one.
    int width = xg-xs;
    int height = yg-ys;
    int nxs = xs, nys = ys, nxg = xg, nyg = yg;

    s %= width+width+height+height;
    if (s < width) {
      int diff = s;
      xg -= width - diff;
      nxs += diff;
    } else if (s < height+width) {
      int diff = height+width - s;
      yg -= height - diff;
      nys += diff;
    } else if (s < width+height+width) {
      int diff = width+height+width - s;
      xg -= width - diff;
      nxs += diff;
    } else {
      int diff = height+width+height+width - s;
      yg -= height - diff;
      nys += diff;
    }

    if (size() < (nxg-nxs) * (nyg-nys)) {
      swap(xs, nxs);
      swap(ys, nys);
      swap(xg, nxg);
      swap(yg, nyg);
    }

    return cake(nxs, nys, nxg, nyg);
  }
  int size(void) const {
    return (xg-xs) * (yg-ys);
  }

  int operator <(const cake &rhs) const {
    return size() < rhs.size();
  }
};

int main(void) {
  for (;;) {
    scanf("%d%d%d", &n, &w, &d);
    if (n == 0 && w == 0 && d == 0) break;

    vector<cake> v;
    v.push_back(cake(0, 0, w, d));
    rep (_i, n) {
      int p, s;
      scanf("%d%d", &p, &s);
      cake large = v[p-1];
      v.erase(v.begin()+p-1);
      cake small = large.cut(s);
      v.push_back(small);
      v.push_back(large);
    }
    sort(all(v));

    for (unsigned int i = 0; i < v.size(); i++) {
      printf("%d", v[i].size());
      if (i == v.size() - 1) {
        putchar('\n');
      } else {
        putchar(' ');
      }
    }
  }
  return 0;
}
