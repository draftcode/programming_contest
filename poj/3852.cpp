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

string s[101];

int main(void) {
  ios::sync_with_stdio(false);
  for (;;) {
    int N; cin >> N; if (N == 0) break;
    for (int n = 0; n < N; n++) cin >> s[n];

    set<string> se;
    int i = 0;
    for (;;) {
      bool passed = true;
      for (int n = 0; n < N; n++) {
        if (s[n].size() == i+1) {
          passed = false; break;
        }
        pair<set<string>::iterator, bool> p = se.insert(s[n].substr(i+1));
        if (!p.second) {
          passed = false; break;
        }
      }
      if (!passed) {
        break;
      }
      i++;
    }
    cout << i << endl;
  }

  return 0;
}
