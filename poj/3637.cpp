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

int T, N;
int v[20000];

int main(void) {
  ios::sync_with_stdio(false);
  cin >> T;
  for (int t = 0; t < T; t++) {
    cin >> N;
    for (int i = 0; i < N; i++) cin >> v[i];
    sort(v, v+N, greater<ll>());

    ll ans = 0;
    for (int i = 2; i < N; i += 3) {
      ans += v[i];
    }
    cout << ans << endl;
  }
  return 0;
}
