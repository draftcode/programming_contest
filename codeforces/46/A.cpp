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

int main(void) {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;

  int k = 1;
  int curr = 0;
  rep (i, n-1) {
    curr = (curr + k) % n;
    k++;
    cout << curr+1;
    if (i != n-2) {
      cout << ' ';
    }
  }
  cout << endl;
  return 0;
}
