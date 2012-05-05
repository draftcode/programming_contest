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
  int ans = 0;
  string s;
  while (cin >> s) {
    int num = 0;
    for (string::const_iterator it = s.begin(); it != s.end(); it++) {
      if (isdigit(*it)) {
        num *= 10;
        num += *it - '0';
      } else {
        ans += num;
        num = 0;
      }
    }
    ans += num;
  }
  cout << ans << endl;
  return 0;
}
