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
  cin >> s;
  int j = 0;
  int o = 0;
  int i = 0;
  int ans = 0;

  for (int k = 0; k < s.size();) {
    if (s[k] == 'J') {
      j = o = i = 0;
      while (s[k] == 'J' && k < s.size()) {
        j++; k++;
      }
      while (s[k] == 'O' && k < s.size()) {
        o++; k++;
      }
      while (s[k] == 'I' && k < s.size()) {
        i++; k++;
      }
      if (o <= j && o <= i) {
        ans = max(ans, o);
      }
    } else {
      k++;
    }
  }

  cout << ans << endl;
  return 0;
}

