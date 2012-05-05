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

  bool ans = false;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 'H' || s[i] == 'Q' || s[i] == '9') {
      ans = true;
      break;
    }
  }
  if (ans) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}
