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
  string s;
  cin >> s;
  int upper = 0;
  rep (i, s.size()) {
    if (isupper(s[i])) upper++;
  }

  if (upper > s.size() - upper) {
    rep (i, s.size()) {
     cout << (char)toupper(s[i]);
    }
  } else {
    rep (i, s.size()) {
     cout << (char)tolower(s[i]);
    }
  }
  cout << endl;
  return 0;
}
