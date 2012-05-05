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

int v[100000];
int sum[100001];

int main(void) {
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  for (int _ = 0; _ < T; _++) {
    int N, S;
    cin >> N >> S;
    sum[0] = 0;
    for (int n = 0; n < N; n++) {
      cin >> v[n];
    }

    int ans = N + 1;
    int s = 0, t = 0, sum = 0;
    for (;;) {
      while (t < N && sum < S) {
        sum += v[t++];
      }
      if (sum < S) break;
      ans = min(ans, t-s);
      sum -= v[s++];
    }

    if (ans > N) {
      cout << 0 << endl;
    } else {
      cout << ans << endl;
    }
  }
  return 0;
}
