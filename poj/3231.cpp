#include <algorithm>
#include <functional>
#include <iostream>
#include <limits>
#include <numeric>
#include <queue>
#include <sstream>
#include <vector>
#include <map>
#include <set>

#include <cctype>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
static const double EPS = 1e-6;

struct Obj {
  double left, speed, mxsp;
  Obj(double a, double b, double c) : left(a), speed(b), mxsp(c) {}
};

void calc(vector<Obj> &v) {
  unsigned int fin = 0;
  double sofar = 0.0;
  while (fin < v.size()) {
    double mtime = DBL_MAX;
    for (unsigned int i = 0; i < v.size(); i++) {
      if (v[i].left <= EPS) continue;
      double tleft = v[i].left / v[i].speed;
      if (tleft < mtime) {
        mtime = tleft;
      }
    }
    double dist_left = 0.0;
    int dist_count = 0;
    for (unsigned int i = 0; i < v.size(); i++) {
      v[i].left -= v[i].speed * mtime;
      if (v[i].left <= EPS && v[i].speed != 0.0)  {
        printf("NO%d:%.3fs\n", i+1, sofar + mtime);
        dist_left += v[i].speed;
        v[i].speed = 0.0;
        fin++;
      }

      if (v[i].left > EPS && abs(v[i].mxsp - v[i].speed) >= EPS) {
        dist_count++;
      }
    }
    sofar += mtime;
    double dist_bw = dist_left / dist_count;
    dist_count = 0; dist_left = 0;
    do {
      for (unsigned int i = 0; i < v.size(); i++) {
        if (v[i].left > EPS && abs(v[i].mxsp - v[i].speed) >= EPS) {
          if (v[i].speed + dist_bw < v[i].mxsp) {
            v[i].speed += dist_bw;
            dist_count = 0;
          } else {
            dist_left += v[i].mxsp - v[i].speed;
            v[i].speed = v[i].mxsp;
          }
        }
      }
    } while (dist_left > EPS && dist_count > 0);
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  for (int i = 1;; i++) {
    int n; cin >> n;
    if (n == 0) break;
    int t; cin >> t;
    vector<Obj> v;
    for (int k = 0; k < n; k++) {
      int a, b, c;
      cin >> a >> b >> c;
      v.push_back(Obj(a, b, c));
    }
    printf("Case %d:\n", i);
    calc(v);
  }
  return 0;
}
