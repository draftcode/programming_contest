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
    string t;
    string::const_iterator it = s.begin();
    while (it != s.end()) {
      if (*it == '@') {
        it++;
        int rep = *it++ - '0';
        char c = *it++;
        t += string(rep, c);
      } else {
        t.push_back(*it++);
      }
    }
    cout << t << endl;
  }
  return 0;
}
