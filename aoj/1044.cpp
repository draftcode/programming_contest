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
  for (;;) {
    string s, type;
    cin >> s >> type; if (type[0] == 'X') break;

    bool first = true;
    string t;
    for (int i = 0; i < s.size(); i++) {
      if ((isupper(s[i]) || s[i] == '_')  && t.size() != 0) {
        if (type[0] == 'U') {
          t[0] = t[0] - 'a' + 'A';
          cout << t;
        } else if (type[0] == 'L') {
          if (!first) {
            t[0] = t[0] - 'a' + 'A';
          }
          cout << t;
        } else {
          if (!first) {
            cout << '_';
          }
          cout << t;
        }
        first = false;
        t.clear();
      }

      if (isalpha(s[i])) {
        char c = s[i];
        if (isupper(c)) {
          c = c - 'A' + 'a';
        }
        t.push_back(c);
      }
    }
    if (type[0] == 'U') {
      t[0] = t[0] - 'a' + 'A';
      cout << t;
    } else if (type[0] == 'L') {
      if (!first) {
        t[0] = t[0] - 'a' + 'A';
      }
      cout << t;
    } else {
      if (!first) {
        cout << '_';
      }
      cout << t;
    }
    cout << endl;
  }
  return 0;
}
