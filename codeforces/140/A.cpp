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
  int n;
  double R, r;
  cin >> n >> R >> r;
  if (R >= 2*r) {
    double theta = 2 * asin(r/(R-r));
    if (2 * M_PI - theta * n >= 0) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  } else {
    if (n == 1 && r <= R) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }

  return 0;
}

