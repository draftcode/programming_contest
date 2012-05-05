#include <algorithm>
#include <functional>
#include <iostream>
#include <limits>
#include <numeric>
#include <queue>
#include <sstream>
#include <vector>
#include <map>

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
  int n; cin >> n;
  map<string, int> m;
  rep (i, n) {
    string s; cin >> s;
    m[s] += 1;
  }

  string top; int top_score = 0;
  each (it, m) {
    if (it->second > top_score) {
      top = it->first;
      top_score = it->second;
    }
  }

  cout << top << endl;
  return 0;
}
