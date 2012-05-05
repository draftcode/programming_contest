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

int main(void) {
  ios::sync_with_stdio(false);
  int N, T, S;
  cin >> N >> T >> S;
  vector<int> A(N);
  vector<int> B(N);
  for (int i = 0; i < N; i++) cin >> A[i] >> B[i];

  vector<vector<int> > tab(N+1, vector<int>(T+1, 0));

  for (int k = 0; k < N; k++) {
    for (int t = 0; t < T; t++) {
      tab[k+1][t] = max(tab[k+1][t], tab[k][t]);
      if (t < S && t+B[k] > S) continue;
      if (t+B[k] > T) continue;
      tab[k+1][t+B[k]] = max(tab[k+1][t+B[k]], tab[k][t] + A[k]);
    }
  }

  int ans = 0;
  for (int t = 0; t < T; t++) {
    ans = max(ans, tab[N][t]);
  }

  cout << ans << endl;
  return 0;
}
