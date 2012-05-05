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

typedef string::const_iterator State;

int count_syllables(State &s) {
  int ret = 0;
  bool prev = false;
  while (*s != '\0' && *s != '/') {
    switch (*s) {
      case 'a':
      case 'i':
      case 'u':
      case 'e':
      case 'o':
      case 'y':
        if (!prev) ret++;
        prev = true;
        break;
      default:
        prev = false;
    }
    s++;
  }
  s++;
  return ret;
}

int main(void) {
  ios::sync_with_stdio(false);
  for (;;) {
    string s; getline(cin, s); if (s == "e/o/i") break;
    State state = s.begin();
    if (count_syllables(state) != 5) {
      cout << '1' << endl;
    } else if (count_syllables(state) != 7) {
      cout << '2' << endl;
    } else if (count_syllables(state) != 5) {
      cout << '3' << endl;
    } else {
      cout << 'Y' << endl;
    }
  }
  return 0;
}
