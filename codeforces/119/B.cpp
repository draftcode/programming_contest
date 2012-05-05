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
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

#define rep(i,n) for(int i = 0; i < n; i++)
#define each(it,c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)

int num_q;
double min_p = DBL_MAX, max_p = -1.0;
vector<int> left_th;

void calc(int i, int left_num, int sum_prof) {
  if (left_num == 0) {
    double card_prof = ((double)sum_prof)/num_q;
    min_p = min(min_p, card_prof);
    max_p = max(max_p, card_prof);
    return;
  }

  if (i >= left_th.size()) return;

  calc(i+1, left_num, sum_prof);
  calc(i+1, left_num-1, sum_prof+left_th[i]);
}

int main(void) {
  ios::sync_with_stdio(false);
  int n, k;
  cin >> n >> k;

  num_q = n/k;

  vector<int> v;
  rep (i, n) {
    int t; cin >> t; v.push_back(t);
  }

  vector<bool> q(n, true);

  int unique_info = 0;
  int info;
  cin >> info;
  rep (i, info) {
    int sum_prof = 0;
    bool problem_off = false;
    rep (j, num_q) {
      int t; cin >> t;
      if (q[t-1]) {
        q[t-1] = false;
        problem_off = true;
      }
      sum_prof += v[t-1];
    }
    if (problem_off) {
      unique_info++;
    }

    double card_prof = ((double)sum_prof)/num_q;
    min_p = min(min_p, card_prof);
    max_p = max(max_p, card_prof);
  }

  rep (i, n) {
    if (q[i]) left_th.push_back(v[i]);
  }

  if (unique_info != k && left_th.size() >= num_q) {
    calc(0, num_q, 0);
  }

  printf("%.10f %.10f\n", min_p, max_p);

  return 0;
}
