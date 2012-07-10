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
  int K;
  cin >> K >> K >> K;
  vector<int> v(K);
  for (int i = 0; i < K; i++) {
    cin >> v[i];
  }
  int ans = 0;
  for (int i = 0; i < K; i++) {
    int t; cin >> t;
    if (v[i] < t) {
      ans += t-v[i];
    }
  }
  cout << ans << endl;
  return 0;
}
