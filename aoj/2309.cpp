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

int N, M;
vector<double> v[100];
// diff[i][j] ... j's production to i
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
        double inner_r = (sqr_len_i*sqr_len_j - inp*inp)/(sqr_len_i*sqr_len_j);
        
        double len = inner_r * sqr_len_j;
        diff_len[i][j] = len;
      }
    }
  }
}

int main(void) {
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
  rep (base, M) {
    int used_count = 1;
    vector<bool> used(M, false);
    
    priority_queue<P> que;
    rep (j, M) {
      if (j != base) {
        que.push((P){diff_len[j][j], j, j});
      }
      que.push((P){diff_len[base][j], base, j});
    }
    
    double sum_len = diff_len[base][base];
    used[base] = true;
    while (!que.empty() && used_count != M) {
      P p = que.top(); que.pop();
      if (used[p.j]) continue;
      used[p.j] = true;
      sum_len += diff_len[p.i][p.j];
      used_count++;
      
      rep (j, M) {
        if (!used[j]) {
          que.push((P){diff_len[p.j][j], p.j, j});
        }
      }
    }
    ans = min(ans, sum_len);
  }

  printf("%.8f\n", ans);
  return 0;
}
