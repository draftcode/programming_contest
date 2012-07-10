#include <complex>
#include <vector>
#include <iostream>
#include <cstdio>
using namespace std;
typedef complex<double> P;
static const double PI = acos(-1.0);
static const double EPS = 1e-6;
namespace std {
  bool operator<(const P& a, const P& b)
  {
    if (fabs(a.real() - b.real()) < EPS) {
      return a.imag() < b.imag();
    } else {
      return a.real() < b.real();
    }
  }
};

inline double dot(const P& a, const P& b) { return a.real()*b.real() + a.imag()*b.imag(); }
inline double cross(const P& a, const P& b) { return a.real()*b.imag() - b.real()*a.imag(); }

inline double dist(const P& a, const P& b) {
  double d1 = a.real() - b.real();
  double d2 = a.imag() - b.imag();
  return sqrt(d1*d1 + d2*d2);
}

int ccw(const P& a, P b, P c)
{
  b -= a;
  c -= a;
  if (cross(b, c) > EPS) {
    return +1;
  } else if (cross(b, c) < -EPS) {
    return -1;
  } else if (dot(b, c) < -EPS) {
    return +2;
  } else if (dot(b, b) + EPS < dot(c, c)) {
    return -2;
  } else {
    return 0;
  }
}

struct line/*{{{*/
{
  P a, b;
  line() {}
  line(const P& p, const P& q) : a(p), b(q) {}

  inline P intersection(const line& ln) const
  {
    // assert(intersects(ln))
    const P x = b - a;
    const P y = ln.b - ln.a;
    return a + x*(cross(y, ln.a - a))/cross(y, x);
  }
};/*}}}*/

struct segment/*{{{*/
{
  P a, b;
  segment() {}
  segment(const P& x, const P& y) : a(x), b(y) {}

  inline bool intersects(const line& ln) const
  {
    return cross(ln.b - ln.a, a - ln.a) * cross(ln.b - ln.a, b - ln.a) < EPS;
  }

  inline P intersection(const line& ln) const
  {
    // assert(intersects(ln))
    const P x = b - a;
    const P y = ln.b - ln.a;
    return a + x*(cross(y, ln.a - a))/cross(y, x);
  }
};/*}}}*/

int main(void) {
  ios::sync_with_stdio(false);
  for (;;) {
    double ret = 0;
    int N, H; cin >> N >> H;
    if (N == 0 && H == 0) break;

    P origin(0, H);
    int x, y; cin >> x >> y;
    P prev(x, y);
    P highest(0, 0);
    for (int i = 1; i < N; i++) {
      int x, y; cin >> x >> y;
      P curr(x, y);
      if (ccw(origin, highest, prev) == -1) {
        line ln(origin, highest);
        if (segment(curr, prev).intersects(ln)) {
          P p = ln.intersection(line(curr, prev));
          ret += dist(p, curr);
        }
      } else if (ccw(origin, highest, curr) == 1) {
        ret += dist(prev, curr);
      }

      if (ccw(origin, highest, curr) == 1) {
        highest = curr;
      }

      prev = curr;
    }
    printf("%.2f\n", ret);
  }
  return 0;
}
