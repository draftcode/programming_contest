#include <algorithm>
#include <functional>
#include <iostream>
#include <limits>
#include <numeric>
#include <queue>
#include <sstream>
#include <vector>

#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

#define rep(i,n) for(int i = 0; i < n; i++)
#define each(it,c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)

vector<int> m[1000];

int main(void) {
  ios::sync_with_stdio(false);
  vector<int> v;
  int N, C;
  cin >> N >> C;
  rep (i, N) {
    int k; cin >> k; v.push_back(k);
  }
  vector<int>::iterator it = lower_bound(v.begin(), v.end(), C) - 1;

  return 0;
}
