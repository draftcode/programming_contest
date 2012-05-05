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
  int T; cin >> T;
  for (int _ = 0; _ < T; _++) {
    string s; cin >> s;
    string ans(1, s[0]);
    int cursor = 0;
    for (int i = 2; i < s.size(); i += 2) {
      if (s[i] == '>') {
        cursor++;
      } else {
        cursor--;
      }
      i++;
      if (cursor == -1) {
        cursor = 0;
        ans = string(1, s[i]) + ans;
      } else if (cursor == ans.size()) {
        ans.push_back(s[i]);
      }
    }
    cout << ans << endl;
  }
  return 0;
}
