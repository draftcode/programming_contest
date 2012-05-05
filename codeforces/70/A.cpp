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

#define rep(i,n) for(int i = 0; i < n; i++)
#define each(it,c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)

ll calc(int n) {
  if (n == 0) {
    return 1;
  } else if (n == 1) {
    return 1;
  } else {
    return (3 * calc(n-1)) % 1000003;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  cout << calc(n) << endl;
  return 0;
}
