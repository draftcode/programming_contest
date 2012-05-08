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
#include <cassert>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef string::const_iterator State;

int stage;
int v[26];
bool exists[26];
int number(State &s);
int expr(State &s) {
  State saved = s;
  int num = number(s);

  while (*s != '\0' && *s != ' ') {
    if (*s == '-') {
      s++;
      num -= number(s);
    } else if (*s == '+') {
      s++;
      num += number(s);
    } else {
      assert(false && 1);
    }
    while (*s == ' ') s++;
  }

  return num;
}

int number(State &s) {
  int num;
  if (*s == '-' && *(s+1) == '-' && isalpha(*(s+2))) {
    if (stage == 1) v[*(s+2) - 'a']--;
    num = v[*(s+2) - 'a'];
    exists[*(s+2) - 'a'] = true;
    s += 3;
  } else if (*s == '+' && *(s+1) == '+' && isalpha(*(s+2))) {
    if (stage == 1) v[*(s+2) - 'a']++;
    num = v[*(s+2) - 'a'];
    exists[*(s+2) - 'a'] = true;
    s += 3;
  } else if (isalpha(*s) && *(s+1) == '-' && *(s+2) == '-') {
    if (stage == 3) v[*s - 'a']--;
    num = v[*s - 'a'];
    exists[*s - 'a'] = true;
    s += 3;
  } else if (isalpha(*s) && *(s+1) == '+' && *(s+2) == '+') {
    if (stage == 3) v[*s - 'a']++;
    num = v[*s - 'a'];
    exists[*s - 'a'] = true;
    s += 3;
  } else if (isalpha(*s)) {
    num = v[*s - 'a'];
    exists[*s - 'a'] = true;
    s++;
  } else {
    assert(false && 2);
  }
  return num;
}

int main(void) {
  ios::sync_with_stdio(false);
  while (true) {
    for (int i = 0; i < 26; i++) {
      v[i] = i+1;
      exists[i] = false;
    }
    string t;
    getline(cin, t);
    if (t == "") break;

    string s(t.size(), ' ');
    int k = 0;
    for (int i = 0; i < t.size(); i++) {
      if (t[i] != ' ') {
        s[k++] = t[i];
      }
    }

    stage = 1;
    State state = s.begin();
    expr(state);

    stage = 2;
    state = s.begin();
    int value = expr(state);

    stage = 3;
    state = s.begin();
    expr(state);

    cout << "Expression: " << t << endl;
    cout << "    value = " << value << endl;
    for (int i = 0; i < 26; i++) {
      if (exists[i]) {
        cout << "    " << char('a' + i) << " = " << v[i] << endl;
      }
    }
  }
  return 0;
}
