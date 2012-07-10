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
  for (int _ = 0; _ < T; _++) {
    int N; cin >> N;
    int v[2] = {0, 0};
    for (int i = 0; i < N; i++) {
      int c; cin >> c;
      if (c == 1) v[i % 2]++;
    }

    if (N % 2 == 1 || abs(v[0] - v[1]) <= 1) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}
