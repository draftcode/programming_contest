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

struct tag {
  string name;
  int x1, y1, x2, y2;
  vector<tag *> childs;
  tag (string name, int x1, int y1, int x2, int y2)
    : name(name), x1(x1), y1(y1), x2(x2), y2(y2) {}

  ~tag() {
    for (vector<tag *>::const_iterator it = childs.begin(); it != childs.end(); it++) {
      delete *it;
    }
  }

  int count(int x, int y) {
    if (x1 <= x && x <= x2 && y1 <= y && y <= y2) {
      for (vector<tag *>::const_iterator it = childs.begin(); it != childs.end(); it++) {
        int r = (*it)->count(x, y);
        if (r != -1) {
          return r;
        }
      }
      return childs.size();
    } else {
      return -1;
    }
  }
  
  string touch(int x, int y) {
    if (x1 <= x && x <= x2 && y1 <= y && y <= y2) {
      for (vector<tag *>::const_iterator it = childs.begin(); it != childs.end(); it++) {
        string r = (*it)->touch(x, y);
        if (r != "") {
          return r;
        }
      }
      return name;
    } else {
      return "";
    }
  }
};

string start_tag(State &begin) {
  State save_begin = begin;
  if (*begin == '<') {
    begin++;
    if (*begin != '/' && *begin != '>') {
      string ret;
      while (*begin != '>') {
        ret.push_back(*begin);
        begin++;
      }
      begin++;
      return ret;
    } else {
      begin = save_begin;
      throw ParseError();
    }
  } else {
    begin = save_begin;
    throw ParseError();
  }
}

string end_tag(State &begin) {
  State save_begin = begin;
  if (*begin == '<') {
    begin++;
    if (*begin == '/') {
      begin++;
      if (*begin != '>') {
        string ret;
        while (*begin != '>') {
          ret.push_back(*begin);
          begin++;
        }
        begin++;
        return ret;
      } else {
        begin = save_begin;
        throw ParseError();
      }
    } else {
      begin = save_begin;
      throw ParseError();
    }
  } else {
    begin = save_begin;
    throw ParseError();
  }
}

int digits(State &begin) {
  int ret = 0;
  if (!isdigit(*begin)) {
    throw ParseError();
  }
  while (isdigit(*begin)) {
    ret *= 10;
    ret += *begin - '0';
    begin++;
  }
  return ret;
}

void tag_parameter(State &begin, int &x1, int &y1, int &x2, int &y2) {
  State save_begin = begin;

  x1 = digits(begin);
  if (*begin != ',') {
    begin = save_begin;
    throw ParseError();
  }
  begin++;
  y1 = digits(begin);
  if (*begin != ',') {
    begin = save_begin;
    throw ParseError();
  }
  begin++;
  x2 = digits(begin);
  if (*begin != ',') {
    begin = save_begin;
    throw ParseError();
  }
  begin++;
  y2 = digits(begin);
}

tag *tag_structure(State &begin) {
  string tagname = start_tag(begin);
  int x1, y1, x2, y2;
  tag_parameter(begin, x1, y1, x2, y2);
  tag *ret = new tag(tagname, x1, y1, x2, y2);
  for (;;) {
    try {
      tag *child = tag_structure(begin);
      ret->childs.push_back(child);
    } catch (ParseError e) {
      break;
    }
  }
  string end_tagname = end_tag(begin);
  if (tagname != end_tagname) {
    delete ret;
    throw ParseError();
  }
  return ret;
}

int main(void) {
  ios::sync_with_stdio(false);
  for (;;) {
    int n; cin >> n;
    if (n == 0) break;
    string s; cin >> s;
    State begin = s.begin();
    tag *tree = tag_structure(begin);

    for (int i = 0; i < n; i++) {
      int x, y; cin >> x >> y;
      string s = tree->touch(x, y);
      if (s == "") {
        cout << "OUT OF MAIN PANEL 1" << endl;
      } else {
        cout << s << ' ' << tree->count(x, y) << endl;
      }
    }
    delete tree;
  }
  return 0;
}
