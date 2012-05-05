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
  string t;
  char c;
  bool first = true;
  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == ',' || c == '.') {
      if (3 <= t.size() && t.size() <= 6) {
        if (!first) {
          cout << ' ';
        }
        first = false;
        cout << t;
      }
      t.clear();
    } else {
      t.push_back(c);
    }
  }
  if (3 <= t.size() && t.size() <= 6) {
    if (!first) {
      cout << ' ';
    }
    cout << t;
  }
  cout << endl;
  return 0;
}
