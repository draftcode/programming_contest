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
  while (cin >> s) {
    string::const_iterator it = s.begin();
    int ans = 0;
    int prev_num = INT_MAX;
    while (it != s.end()) {
      int n = 0;
      if (*it == 'I') {
        n = 1;
      } else if (*it == 'V') {
        n = 5;
      } else if (*it == 'X') {
        n = 10;
      } else if (*it == 'L') {
        n = 50;
      } else if (*it == 'C') {
        n = 100;
      } else if (*it == 'D') {
        n = 500;
      } else if (*it == 'M') {
        n = 1000;
      }

      if (prev_num < n) {
        ans += n - 2*prev_num;
      } else {
        ans += n;
      }
      prev_num = n;
      it++;
    }

    cout << ans << endl;
  }
  return 0;
}
