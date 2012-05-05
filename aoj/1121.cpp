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

typedef string::const_iterator State;

int parse(State &begin) {
  if (*begin == 'l' && *(begin+1) ==  'd') {
    begin += 2;
    return 26;
  } else if (*begin == 'm') {
    if (*(begin+1) == 'b') {
      begin += 2;
      return 27;
    } else if (*(begin+1) == 'p') {
      begin += 2;
      return 28;
    }
  } else if (*begin == 'n') {
    if (*(begin+1) == 'c') {
      begin += 2;
      return 29;
    } else if (*(begin+1) == 'd') {
      begin += 2;
      return 30;
    } else if (*(begin+1) == 'g') {
      begin += 2;
      return 31;
    } else if (*(begin+1) == 't') {
      begin += 2;
      return 32;
    } else if (*(begin+1) == 'w') {
      begin += 2;
      return 33;
    }
  } else if (*begin == 'p' && *(begin+1) == 's') {
    begin += 2;
    return 34;
  } else if (*begin == 'q' && *(begin+1) == 'u') {
    begin += 2;
    return 35;
  } else if (*begin == 'c' && *(begin+1) == 'w') {
    begin += 2;
    return 36;
  } else if (*begin == 't' && *(begin+1) == 's') {
    begin += 2;
    return 37;
  }

  return *begin++ - 'a';
}

string reverse(int c) {
  switch (c) {
    case 26: return "ld";
    case 27: return "mb";
    case 28: return "mp";
    case 29: return "nc";
    case 30: return "nd";
    case 31: return "ng";
    case 32: return "nt";
    case 33: return "nw";
    case 34: return "ps";
    case 35: return "qu";
    case 36: return "cw";
    case 37: return "ts";
    default: return string(1, c+'a');
  }
}

int m[38][38];
int main(void) {
  ios::sync_with_stdio(false);
  int n; cin >> n;

  string s;
  while (cin >> s) {
    State state = s.begin();
    int prev = parse(state);
    while (state != s.end()) {
      int curr = parse(state);
      m[prev][curr]++;
      prev = curr;
    }
  }

  for (int i = 0; i < 38; i++) {
    int mx = 0;
    for (int k = 0; k < 38; k++) {
      if (m[i][k] > m[i][mx]) {
        mx = k;
      }
    }
    cout << reverse(i) << ' ' << reverse(mx) << ' ' << m[i][mx] << endl;
  }
  return 0;
}
