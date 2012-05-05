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
  int T; cin >> T;
  for (int t = 0; t < T; t++) {
    int N; cin >> N;
    vector<int> v(N, 0);
    for (int i = 0; i < N; i++) {
      cin >> v[i];
    }
    sort(v.begin(), v.end());
  }
  return 0;
}
