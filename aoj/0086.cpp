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
  while (!cin.eof()) {
    map<int, int> m;
    for (;;) {
      int a, b;
      cin >> a >> b;
      if (a == 0 && b == 0) break;
      m[a]++;
      m[b]++;
    }

    bool ans = true;
    for (map<int, int>::const_iterator it = m.begin(); it != m.end(); it++) {
      if (it->first == 1 || it->first == 2) {
        if (it->second != 1) {
          ans = false;
          break;
        }
      } else if (it->second % 2 != 0) {
        ans = false;
        break;
      }
    }
    if (ans) {
      cout << "OK" << endl;
    } else {
      cout << "NG" << endl;
    }
    cin.ignore(); cin.peek();
  }
  return 0;
}
