#include <algorithm>
#include <functional>
#include <iostream>
#include <limits>
#include <numeric>
#include <queue>
#include <sstream>
#include <vector>

#include <cctype>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;

#define rep(i,n) for(int i = 0; i < n; i++)
#define each(it,c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)

typedef string::const_iterator State;
class ParseError {};

char P, Q, R;

char parse(State &begin) {
  if (*begin == '-') {
    begin++;
    char ret = parse(begin);
    if (ret == 0) return 2;
    else if (ret == 1) return 1;
    else return 0;
  } else if (*begin == '(') {
    begin++;
    char left = parse(begin);
    char op = *begin;
    begin++;
    char right = parse(begin);
    if (*begin == ')') {
      begin++;
      if (op == '*') {
        if (left == 0 || right == 0) {
          return 0;
        } else if (left == 1 || right == 1) {
          return 1;
        } else {
          return 2;
        }
      } else {
        if (left == 2 || right == 2) {
          return 2;
        } else if (left == 1 || right == 1) {
          return 1;
        } else {
          return 0;
        }
      }
    } else {
      throw ParseError();
    }
  } else if (isdigit(*begin)) {
    char ret = *begin - '0';
    begin++;
    return ret;
  } else if (*begin == 'P') {
    begin++;
    return P;
  } else if (*begin == 'Q') {
    begin++;
    return Q;
  } else if (*begin == 'R') {
    begin++;
    return R;
  } else {
    throw ParseError();
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  string s;
  for (;;) {
    cin >> s;
    if (s == ".") break;

    int ans = 0;
    for (P = 0; P < 3; P++) {
      for (Q = 0; Q < 3; Q++) {
        for (R = 0; R < 3; R++) {
          State begin = s.begin();
          if (parse(begin) == 2) {
            ans++;
          }
        }
      }
    }

    cout << ans << endl;
  }
  return 0;
}
