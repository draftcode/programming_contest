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
int N, M;
vector<double> colors[20];
double diff[20][20];

inline double sqr(double x) {
  return x * x;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin >> N >> M;
  rep (i, N) {
    double L, a, b;
    cin >> L >> a >> b;
    colors[i].push_back(L);
    colors[i].push_back(a);
    colors[i].push_back(b);
  }
  
  rep (i, N) {
    rep (j, N) {
      diff[i][j] = sqr(colors[i][0] - colors[j][0]) +
        sqr(colors[i][1] - colors[j][1]) +
        sqr(colors[i][2] - colors[j][2]);
    }
  }
  
  vector<int> state(N, 0);
  rep (i, M) {
    state[N-i-1] = 1;
  }
  
  double ans = 0.0;
  do {
    double sum = 0.0;
    rep (i, N) {
      rep (j, i+1) {
        if (state[i] == 1 && state[j] == 1) {
          sum += diff[i][j];
        }
      }
    }
    ans = max(ans, sum);
  } while (next_permutation(state.begin(), state.end()));
  
  printf("%.8f\n", ans);
  
  return 0;
}
