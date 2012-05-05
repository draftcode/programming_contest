#include <algorithm>
#include <functional>
#include <iostream>
#include <limits>
#include <numeric>
#include <queue>
#include <map>
#include <sstream>
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

map<string, int> m;
typedef string::iterator Point;

int number(Point &start, Point &end) {
  if ('0' <= *start && *start <= '9') {
    int n = *start - '0';
    start++;
    if ('0' <= *start && *start <= '9') {
      n = n * 10 + *start - '0';
      start++;
    }
    return n;
  }
  return -1;
}

int atom(Point &start, Point &end) {
  Point saved_start = start;

  string s;
  if ('A' <= *start && *start <= 'Z') {
    s.push_back(*start);
    start++;
    if (start != end && 'a' <= *start && *start <= 'z') {
      s.push_back(*start);
      start++;
    }
    if (m.find(s) != m.end()) {
      return m[s];
    }
  }

  start = saved_start;
  return -1;
}

int molecule(Point &start, Point &end) {
  Point saved_start = start;
  int ret = 0;

  while (start != end && *start != ')') {
    if (*start == '(') {
      start++;
      int w = molecule(start, end);
      if (w != -1 && *start == ')') {
        start++;
        int n = number(start, end);
        if (n != -1) {
          ret += w*n;
        } else {
          start = saved_start;
          return -1;
        }
      } else {
        start = saved_start;
        return -1;
      }
    } else {
      int w = atom(start, end);
      if (w != -1) {
        int n = number(start, end);
        if (n != -1) {
          ret += w*n;
        } else {
          ret += w;
        }
      } else {
        start = saved_start;
        return -1;
      }
    }
  }

  return ret;
}

int main(void) {
  ios::sync_with_stdio(false);
  string s; int w;
  while (cin >> s, s != "END_OF_FIRST_PART") {
    cin >> w;
    m[s] = w;
  }
  while (cin >> s, s != "0") {
    string::iterator start = s.begin();
    string::iterator end = s.end();

    w = molecule(start, end);
    if (w == -1) {
      cout << "UNKNOWN" << endl;
    } else {
      cout << w << endl;
    }
  }
  return 0;
}
