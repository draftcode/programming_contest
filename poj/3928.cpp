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

int v[20000];
int sorted[20000];
int ranks[20000];
int ranks_all[20000];

int main(void) {
  int T; scanf("%d", &T);
  for (int _ = 0; _ < T; _++) {
    int N; scanf("%d", &N);
    for (int i = 0; i < N; i++) {
      scanf("%d", v+i);
      int rank = ranks[i] = i - (lower_bound(sorted, sorted+i, v[i]) - sorted);
      for (int k = i; k > i - rank; k--) sorted[k] = sorted[k-1];
      sorted[i - rank] = v[i];
    }
    for (int i = 0; i < N; i++) {
      ranks_all[i] = N - (lower_bound(sorted, sorted+N, v[i]) - sorted) - 1;
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
      int left_hi = ranks[i];
      int left_lo = i - ranks[i];
      int right_hi = ranks_all[i] - left_hi;
      int right_lo = N - ranks_all[i] - left_lo - 1;

      ans += left_hi * right_lo + left_lo * right_hi;
    }
    printf("%d\n", ans);
  }
  return 0;
}
