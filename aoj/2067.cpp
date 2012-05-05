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
typedef pair<int, int> P;

#define rep(i,n) for(int i = 0; i < n; i++)
#define each(it,c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)

typedef string::const_iterator State;
class ParseError {};
State end;

string parse_list(State &begin) {
  State saved = begin;

  while (*begin == ' ') begin++;

  if (isupper(*begin)) {
    string ret;
    ret.push_back(*begin);
    begin++;
    while (*begin == ' ') begin++;
    return ret;
  } else if (*begin == 'a' && *(begin+1) == ' ') {
    begin += 10;
    vector<string> l;
    l.push_back(parse_list(begin));

    while (*begin == ',') {
      begin++;
      while (*begin == ' ') begin++;
      l.push_back(parse_list(begin));
      while (*begin == ' ') begin++;
    }

    if (l.size() > 1 || (*begin == 'a' && *(begin+1) == 'n')) {
      if (*begin == 'a' && *(begin+1) == 'n') {
        begin += 3;
        while (*begin == ' ') begin++;
        l.push_back(parse_list(begin));

        string ret;
        ret.push_back('(');
        ret += l[0];
        for (vector<string>::const_iterator it = l.begin()+1; it != l.end(); it++) {
          ret += " " + *it;
        }
        ret.push_back(')');
        return ret;
      } else {
        throw ParseError();
      }
    } else {
      return "(" + l[0] + ")";
    }
  } else {
    throw ParseError();
  }
}

string parse_list_short(State &begin) {
  State saved = begin;

  while (*begin == ' ') begin++;

  if (isupper(*begin)) {
    string ret;
    ret.push_back(*begin);
    begin++;
    while (*begin == ' ') begin++;
    return ret;
  } else if (*begin == 'a' && *(begin+1) == ' ') {
    begin += 10;
    vector<string> l;
    l.push_back(parse_list_short(begin));

    while (*begin == ',') {
      begin++;
      while (*begin == ' ') begin++;
      l.push_back(parse_list_short(begin));
      while (*begin == ' ') begin++;
    }

    if (l.size() > 1) {
      if (*begin == 'a' && *(begin+1) == 'n') {
        begin += 3;
        while (*begin == ' ') begin++;
        l.push_back(parse_list_short(begin));

        string ret;
        ret.push_back('(');
        ret += l[0];
        for (vector<string>::const_iterator it = l.begin()+1; it != l.end(); it++) {
          ret += " " + *it;
        }
        ret.push_back(')');
        return ret;
      } else {
        throw ParseError();
      }
    } else {
      return "(" + l[0] + ")";
    }
  } else {
    throw ParseError();
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  int N;
  cin >> N;
  cin.ignore();
  for (int i = 0; i < N; i++) {
    string s;
    getline(cin, s);
    end = s.end();
    State begin = s.begin();
    cout << parse_list(begin) << endl;
    begin = s.begin();
    cout << parse_list_short(begin) << endl;
  }
  return 0;
}
