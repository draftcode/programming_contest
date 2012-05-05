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
  while (getline(cin, s)) {
    int sz = s.size();
    for (int i = 0; i < sz; i++) {
      if (s.compare(i, 5, "apple") == 0) {
        s.replace(i, 5, "peach");
      } else if (s.compare(i, 5, "peach") == 0) {
        s.replace(i, 5, "apple");
      }
    }
    cout << s << endl;
  }
  return 0;
}
