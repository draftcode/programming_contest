#include <algorithm>
#include <functional>
#include <iostream>
#include <limits>
#include <numeric>
#include <queue>
#include <sstream>
#include <set>
#include <vector>

#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

#define rep(i,n) for(int i = 0; i < n; i++)
#define each(it,c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)

typedef string::const_iterator State;
typedef set<int> iset;
class ParseError {};

iset universal_set;
iset sets[5];

iset expr(State &);
iset factor(State &begin) {
  if (*begin == '(') {
    begin++;
    iset ret = expr(begin);
    if (*begin == ')') {
      begin++;
      return ret;
    } else {
      throw ParseError();
    }
  } else if ('A' <= *begin && *begin <= 'E') {
    char c = *begin;
    begin++;
    return sets[c - 'A'];
  } else if (*begin == 'U') {
    begin++;
    return universal_set;
  } else {
    throw ParseError();
  }
}

iset term(State &begin) {
  if (*begin == 'c') {
    begin++;
    iset ret;
    iset s = factor(begin);
    set_difference(
        universal_set.begin(), universal_set.end(),
        s.begin(), s.end(),
        inserter(ret, ret.end()));
    return ret;
  } else {
    return factor(begin);
  }
}

iset expr(State &begin) {
  iset ret = term(begin);
  for (;;) {
    if (*begin == 'u') {
      begin++;
      iset next_ret;
      iset s = term(begin);
      set_union(
          ret.begin(), ret.end(),
          s.begin(), s.end(),
          inserter(next_ret, next_ret.end()));
      ret = next_ret;
    } else if (*begin == 'i') {
      begin++;
      iset next_ret;
      iset s = term(begin);
      set_intersection(
          ret.begin(), ret.end(),
          s.begin(), s.end(),
          inserter(next_ret, next_ret.end()));
      ret = next_ret;
    } else if (*begin == 'd') {
      begin++;
      iset next_ret;
      iset s = term(begin);
      set_difference(
          ret.begin(), ret.end(),
          s.begin(), s.end(),
          inserter(next_ret, next_ret.end()));
      ret = next_ret;
    } else if (*begin == 's') {
      begin++;
      iset next_ret;
      iset s = term(begin);
      set_symmetric_difference(
          ret.begin(), ret.end(),
          s.begin(), s.end(),
          inserter(next_ret, next_ret.end()));
      ret = next_ret;
    } else {
      return ret;
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  while (!cin.eof()) {
    for (int i = 0; i < 5; i++) {
      sets[i].clear();
    }
    universal_set.clear();
    for (;;) {
      string s; int n;
      cin >> s >> n;
      if (s != "R") {
        for (int i = 0; i < n; i++) {
          int k; cin >> k;
          sets[s[0]-'A'].insert(k);
          universal_set.insert(k);
        }
      } else {
        string query;
        cin >> query;
        State begin = query.begin();
        iset ans = expr(begin);
        if (ans.empty()) {
          cout << "NULL" << endl;
        } else {
          cout << *(ans.begin());
          for (set<int>::const_iterator it = ++ans.begin(); it != ans.end(); it++) {
            cout << ' ' << *it;
          }
          cout << endl;
        }
        break;
      }
    }
    cin.ignore(); cin.peek();
  }
  return 0;
}
