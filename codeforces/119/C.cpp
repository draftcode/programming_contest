#include <algorithm>
#include <functional>
#include <iostream>
#include <limits>
#include <numeric>
#include <queue>
#include <sstream>
#include <vector>

#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

#define rep(i,n) for(int i = 0; i < n; i++)
#define each(it,c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)

struct Subject {
  int a, b, c;

  bool operator <(const Subject &rhs) const {
    return c < rhs.c;
  }
};

int n_days, n_subjects, k;
Subject subjects[50];
ll mx = 0;

ll is_carriable(int i, int days_left, ll from, ll to) {
  cerr << days_left << ' ' <<  i << ' ' << from << ' ' << to << endl;
  ll ans = 0;

  if (days_left == 0) {
    return to;
  }

  for (int k = i; k >= days_left; k--) {
    int a = subjects[k].a, b = subjects[k].b;
    ll div_from = from/k, div_to = to/k;

    if (a <= div_from && div_to <= b) {
      ans = max(ans, is_carriable(k-1, days_left-1, div_from, div_to));
    } else if (div_from < a && div_to <= b) {
      ans = max(ans, is_carriable(k-1, days_left-1, a, div_to));
    } else if (a <= div_from && b < div_to) {
      ans = max(ans, is_carriable(k-1, days_left-1, div_from, b));
    } else if (div_from < a && b < div_to) {
      ans = max(ans, is_carriable(k-1, days_left-1, a, b));
    }
  }

  if (ans != 0) { cerr << ans*k << endl; return ans*k; }

  for (int k = i; k >= days_left; k--) {
    int a = subjects[k].a, b = subjects[k].b;
    ll sub_from = from-k, sub_to = to-k;

    if (a <= sub_from && sub_to <= b) {
      ans = max(ans, is_carriable(k, days_left-1, sub_from, sub_to));
    } else if (sub_from < a && sub_to <= b) {
      ans = max(ans, is_carriable(k, days_left-1, a, sub_to));
    } else if (a <= sub_from && b < sub_to) {
      ans = max(ans, is_carriable(k, days_left-1, sub_from, b));
    } else if (sub_from < a && b < sub_to) {
      ans = max(ans, is_carriable(k, days_left-1, a, b));
    }
  }

  if (ans != 0) { cerr << ans+k << endl; return ans+k; }
  cerr << 0 << endl;
  return 0;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin >> n_days >> n_subjects >> k;
  rep (i, n_subjects) {
    cin >> subjects[i].a >> subjects[i].b >> subjects[i].c;
  }
  sort(subjects, subjects+n_subjects);

  ll mx = 0;
  for (int k = n_subjects-1; k >= n_days; k--) {
    mx = max(mx, is_carriable(k-1, n_days-1, subjects[k].a, subjects[k].b));
  }

  if (mx == 0) {
    cout << "NO" << endl;
  } else {
    cout << mx << endl;
  }
  return 0;
}
