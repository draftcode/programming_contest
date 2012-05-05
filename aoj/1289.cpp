#include <algorithm>
#include <functional>
#include <iostream>
#include <limits>
#include <numeric>
#include <queue>
#include <sstream>
#include <vector>

#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

#define rep(i,n) for(int i = 0; i < n; i++)
#define each(it,c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)

struct vtr {
  double x, y, z;
  vtr (double x, double y, double z) : x(x), y(y), z(z) {}

  double size(void) const {
    return sqrt(x*x+y*y+z*z);
  }

  vtr operator -(const vtr &v) const {
    return vtr(x-v.x, y-v.y, z-v.z);
  }

  vtr operator +(const vtr &v) const {
    return vtr(x+v.x, y+v.y, z+v.z);
  }

  vtr operator *(double k) const {
    return vtr(x*k, y*k, z*k);
  }
};

struct sphere {
  vtr center; double range;
  sphere(vtr center, double range) : center(center), range(range) {}
};

vtr readvtr(void) {
  double x, y, z;
  cin >> x >> y >> z;
  return vtr(x,y,z);
}

double EPS = 1e-6;
int N;
vtr orig(0,0,0);
vtr dir(0,0,0);
vector<sphere> spheres;

double angle(vtr orig, vtr center, vtr point) {
  // angle is always <= M_PI/2
  vtr v1 = center - orig;
  vtr v2 = point - orig;
  // inprod = |v1||v2|cos
  double inprod = (v1.x*v2.x) + (v1.y*v2.y) + (v1.z*v2.z);
  double c = inprod/v1.size()/v2.size();

  double ret = acos(c);
  if (ret > M_PI/2) {
    ret -= M_PI/2;
    ret = M_PI/2 - ret;
  }
  return ret;
}

vtr crossing(vtr v) {
  return vtr(0,v.z*(-1),v.y);
}

bool simulate(void) {
  double l_min = DBL_MAX;
  vtr point(0,0,0);
  vtr nextdir(0,0,0);
  for (int i = 0; i < N; i++) {
    sphere s = spheres[i];
    double angle1 = angle(orig, s.center, orig+dir);
    double angle2 = angle(orig, s.center, crossing(orig - s.center));
    if (angle1 <= angle2) {
      double w = (orig - s.center).size();
      double l = w*cos(angle1) - sqrt(s.range*s.range - (w*sin(angle1))*(w*sin(angle1)));
      if (l < l_min && l > EPS) {
        l_min = l;
        point = orig + dir*(l/dir.size());

        double angle3 = angle(s.center, orig-s.center, point-s.center);

        vtr v1 = orig - s.center;
        vtr v2 = point - s.center;
        v2 = v2 * (v1.size()*cos(angle3)/v2.size());

        vtr m = v2-v1;
        double k = 2.0*(orig-s.center).size()*sin(angle3)/m.size();
        nextdir = m*k-dir;
      }
    }
  }
  if (l_min != DBL_MAX) {
    orig = point;
    dir = nextdir;
    return true;
  }
  return false;
}

int main(void) {
  ios::sync_with_stdio(false);
  for (;;) {
    orig = vtr(0,0,0);
    spheres.clear();

    cin >> N;
    if (N == 0) break;
    dir = readvtr();
    rep (_, N) {
      vtr center(0,0,0);
      double range;
      center = readvtr();
      cin >> range;
      spheres.push_back(sphere(center, range));
    }

    while (simulate()) {
      // cout << orig.x << ' ' << orig.y << ' ' << orig.z << endl;
      // cout << dir.x << ' ' << dir.y << ' ' << dir.z << endl;
      // cout << endl;
    }
    cout << orig.x << ' ' << orig.y << ' ' << orig.z << endl;
  }
  return 0;
}
