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
  string s;
  int ans = 0;
  while (getline(cin, s)) {
    int sz = s.size()-1;
    bool same = true;
    for (int i = 0; i <= sz-i; i++) {
      if (s[i] != s[sz-i]) {
        same = false;
        break;
      }
    }
    if (same) ans++;
  }
  cout << ans << endl;
  return 0;
}
