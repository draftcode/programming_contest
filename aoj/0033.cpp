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
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

#define each(it,c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
int v[10];

bool rep(int i, int left, int right) {
  if (i == 10) return true;

  if (v[i] > left && rep(i+1, v[i], right)) return true;
  if (v[i] > right && rep(i+1, left, v[i])) return true;
  return false;
}

int main(void) {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  for (int _ = 0; _ < n; _++) {
    for (int i = 0; i < 10; i++) cin >> v[i];
    if (rep(0, 0, 0)) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}
