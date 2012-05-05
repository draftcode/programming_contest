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

string next_str(void) {
  static bool end = false;
  string ret;
  if (end) return "";
  for (;;) {
    char c = getchar();
    if (c == ';') break;
    else if (c == '.') {
      end = true;
      break;
    }
    if (!isspace(c)) ret.push_back(c);
  }
  return ret;
}

typedef string::const_iterator State;
vector<string> parse(State &s, int &center) {
  char bottom = *s++;
  if (*s == '(') {
    s++;
    int rhs_center;
    vector<string> rhs = parse(s, rhs_center);
    if (*s == ',') {
      int rhs_size = 0;
      s++;
      int lhs_center;
      vector<string> lhs = parse(s, lhs_center);
      s++;

      rhs.push_back(string(rhs_center, ' ') + string(, '-'));
      rhs.push_back(string(rhs_center, ' ') + bottom);

    } else {
      s++;
      rhs.push_back(string(rhs_center, ' ') + string(1, '-'));
      rhs.push_back(string(rhs_center, ' ') + bottom);
      center = rhs_center;
      return rhs;
    }
  } else {
    center = 0;
    return vector<string>(1, string(1, bottom));
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  int t = 1;
  for (;;) {
    string s = next_str();
    if (s.empty()) break;
    State state = s.begin();
    int center;
    vector<string> v = parse(state, center);

    cout << t << ':' << endl;
    for (int i = 0; i < v.size(); i++) {
      cout << v[i] << endl;
    }
    t++;
  }
  return 0;
}
