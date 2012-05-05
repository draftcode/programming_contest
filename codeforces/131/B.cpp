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

ll v[21];
int main(void) {
  ios::sync_with_stdio(false);
  int N; cin >> N;
  for (int i = 0; i < N; i++) {
    int T; cin >> T;
    v[T+10]++;
  }
  ll ans = v[10]*(v[10]-1)/2;
  for (int i = 1; i <= 10; i++) {
    ans += v[10-i] * v[10+i];
  }
  cout << ans << endl;
  return 0;
}
