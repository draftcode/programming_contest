#include <iostream>
#include <climits>
#include <cstdio>
#include <complex>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
typedef complex<double> P;
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
  const double t1 = a.real() - b.real();
  const double t2 = a.imag() - b.imag();
  return sqrt(t1*t1 + t2*t2);
}

P ps[100];
P ch[100];
double convex(const int N)/*{{{*/
{
  // assert(sorted(ps.begin(), ps.end()))
  // const int N = ps.size();
  // vector<P> ch(2*N);
  int k = 0;
  for (int i = 0; i < N; i++) {
    while (k >= 2 && cross(ch[k-1]-ch[k-2], ps[i]-ch[k-2]) <= EPS) {
      k--;
    }
    ch[k] = ps[i];
    k++;
  }
  for (int i = N-2, t = k+1; i >= 0; i--) {
    while (k >= t && cross(ch[k-1]-ch[k-2], ps[i]-ch[k-2]) <= EPS) {
      k--;
    }
    ch[k] = ps[i];
    k++;
  }
  double length = 0.0;
  for (int j = 0; j < k; j++) {
    length += dist(ch[j], ch[(j+1)%k]);
  }
  return length;
  // ch.resize(k-1);
  // return ch;
}/*}}}*/

struct Tree {
  P p; int v, l, n;
  Tree() {}
  Tree(P p, int v, int l, int n) : p(p), v(v), l(l), n(n) {}
  bool operator <(const Tree &rhs) const {
    return p < rhs.p;
  }
};

int main(void) {
  ios::sync_with_stdio(false);
  int cases = 1;
  while (true) {
    int N; cin >> N;
    if (N == 0) break;
    if (cases > 1) printf("\n");
    vector<Tree> trees(N);
    for (int i = 0; i < N; i++) {
      int x, y, v, l;
      cin >> x >> y >> v >> l;
      trees[i] = Tree(P(x, y), v, l, i+1);
    }
    sort(trees.begin(), trees.end());

    int min_value = INT_MAX;
    double ans_length = 0;
    size_t ans_sz = 0;
    int ans_positions = 0;
    for (int i = 0; i < (1 << N)-1; i++) {
      size_t sz = 0;
      // vector<P> points;
      int values = 0;
      double length = 0;
      for (int j = 0; j < N; j++) {
        if (i & (1 << j)) {
          // cut
          length += trees[j].l;
          values += trees[j].v;
        } else {
          ps[sz++] = trees[j].p;
          // points.push_back(trees[j].p);
        }
      }

      // sort(points.begin(), points.end());
      // points = convex(points);
      double l2 = convex(sz);

      if (length >= l2) {
        if (min_value > values || (min_value == values && ans_sz > sz)) {
          min_value = values;
          ans_length = length - l2;
          ans_sz = sz;
          ans_positions = i;
        }
      }
    }

    printf("Forest %d\n", cases);
    printf("Cut these trees: ");
    vector<int> v;
    for (int i = 0; i < N; i++) {
        if (ans_positions & (1 << i)) {
          v.push_back(trees[i].n);
        }
    }
    sort(v.begin(), v.end());
    for (size_t i = 0; i < v.size(); i++) {
      printf("%d ", v[i]);
    }
    printf("\n");
    printf("Extra wood: %.2f\n", ans_length);

    cases++;
  }
  return 0;
}
