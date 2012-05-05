#include <algorithm>
#include <functional>
#include <iostream>
#include <limits>
#include <numeric>
#include <queue>
#include <sstream>
#include <vector>

#include <cfloat>
#include <climits>
#include <cmath>
#include <cctype>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

#define rep(i,n) for(int i = 0; i < n; i++)
#define each(it,c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)

typedef string::const_iterator State;
class ParseError {};

int expr(State &);
int factor(State &begin) {
  if (*begin == '(') {
    begin++; // Eat '('
    int ret = expr(begin);
    if (*begin == ')') {
      begin++; // Eat ')'
      return ret;
    } else {
      throw ParseError();
    }
  } else if (isdigit(*begin)) {
    int ret = 0;
    while (isdigit(*begin)) {
      ret *= 10;
      ret += *begin - '0';
      begin++;
    }
    return ret;
  } else {
    throw ParseError();
  }
}

int term(State &begin) {
  int ret = factor(begin);
  for (;;) {
    if (*begin == '*') {
      begin++; // Eat '*'
      ret *= factor(begin);
    } else if (*begin == '/') {
      begin++; // Eat '/'
      ret /= factor(begin);
    } else {
      return ret;
    }
  }
}

int expr(State &begin) {
  int ret = term(begin);
  for (;;) {
    if (*begin == '+') {
      begin++; // Eat '+'
      ret += term(begin);
    } else if (*begin == '-') {
      begin++; // Eat '-'
      ret -= term(begin);
    } else {
      return ret;
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  int T; cin >> T;
  for (int t = 0; t < T; t++) {
    string s; cin >> s;
    string::const_iterator begin = s.begin();
    int ans = expr(begin);
    cout << ans << endl;
  }
  return 0;
}
