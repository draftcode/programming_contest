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
  bool iscaps = true;
  for (int i = 1; i < s.size(); i++) {
    if (!isupper(s[i])) {
      iscaps = false;
      break;
    }
  }
  if (iscaps) {
    for (int i = 0; i < s.size(); i++) {
      if (isupper(s[i])) {
        cout << (char)(s[i] - 'A' + 'a');
      } else {
        cout << (char)(s[i] - 'a' + 'A');
      }
    }
  } else {
    cout << s;
  }
  cout << endl;
  return 0;
}
