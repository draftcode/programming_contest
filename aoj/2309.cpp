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

#define rep(i,n) for(int i = 0; i < n; i++)
#define each(it,c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)

int N, M;
vector<double> v[100];
// diff_len[i][j] ... j's production to i
double diff_len[100][100];

struct P {
  double len;
  int i;
  int j;
  
  bool operator <(const P &rhs) const {
    return this->len > rhs.len;
  }
};

void calc_diff(void) {
  rep (i, M) {
    rep (j, M) {
      if (i != j) {
        double inp = inner_product(v[i].begin(), v[i].end(), v[j].begin(), 0.0);
        double sqr_len_i = diff_len[i][i];
        double sqr_len_j = diff_len[j][j];
        diff_len[i][j] = (sqr_len_i*sqr_len_j - inp*inp)/sqr_len_i;
      }
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);

  cin >> N >> M;
  rep (i, M) {
    double len = 0.0;
    rep (k, N) {
      double t;
      cin >> t;
      v[i].push_back(t);
      len += t*t;
    }
    diff_len[i][i] = len;
  }
  calc_diff();

  double ans = 1e10;

  printf("%.8f\n", ans);
  return 0;
}
