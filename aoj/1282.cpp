#include <algorithm>
#include <functional>
#include <iostream>
#include <limits>
#include <numeric>
#include <map>
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
class RuntimeError {};

State end;

struct array {
  char name;
  int size;
  map<int,int> m;
  array(char name, int size) : name(name), size(size) {}

  int get(int idx) {
    if (m.find(idx) == m.end()) {
      throw RuntimeError();
    } else {
      return m[idx];
    }
  }

  void set(int idx, int value) {
    if (size <= idx) {
      throw RuntimeError();
    } else {
      m[idx] = value;
    }
  }
};

int expression(State &begin, map<char, array*> &env) {
  State saved_state = begin;
  if (isdigit(*begin)) {
    int ret = 0;
    while (isdigit(*begin)) {
      ret *= 10;
      ret += *begin - '0';
      begin++;
    }
    return ret;
  } else if (isalpha(*begin)) {
    char name = *begin;
    begin++;
    if (*begin != '[') {
      begin = saved_state;
      throw ParseError();
    }
    begin++;
    int index = expression(begin, env);
    if (*begin != ']') {
      begin = saved_state;
      throw ParseError();
    }
    begin++;

    map<char, array*>::iterator it = env.find(name);
    if (it == env.end()) {
      begin = saved_state;
      throw RuntimeError();
    }
    return it->second->get(index);
  } else {
    throw ParseError();
  }
}

array *declaration(State &begin) {
  State saved_state = begin;
  if (!isalpha(*begin)) throw ParseError();
  char name = *begin;
  begin++;
  if (*begin != '[') {
    begin = saved_state;
    throw ParseError();
  }
  begin++;
  int index = 0;
  while (isdigit(*begin)) {
    index *= 10;
    index += *begin - '0';
    begin++;
  }
  if (*begin != ']') {
    begin = saved_state;
    throw ParseError();
  }
  begin++;
  if (begin != end) {
    begin = saved_state;
    throw ParseError();
  }

  return new array(name, index);
}

void assignment(State &begin, map<char, array*> &env) {
  State saved_state = begin;
  if (!isalpha(*begin)) throw ParseError();
  char name = *begin;
  begin++;
  if (*begin != '[') {
    begin = saved_state;
    throw ParseError();
  }
  begin++;
  int index = expression(begin, env);
  if (*begin != ']') {
    begin = saved_state;
    throw ParseError();
  }
  begin++;
  if (*begin != '=') {
    begin = saved_state;
    throw ParseError();
  }
  begin++;
  int value = expression(begin, env);
  if (begin != end) {
    begin = saved_state;
    throw ParseError();
  }

  map<char, array*>::iterator it = env.find(name);
  if (it == env.end()) {
    begin = saved_state;
    throw RuntimeError();
  }
  it->second->set(index, value);
}

void program(State &begin, map<char,array*> &env) {
  try {
    array *pa = declaration(begin);
    env[pa->name] = pa;
  } catch (ParseError e) {
    assignment(begin, env);
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  string s;
  for (;;) {
    int line_num = 1;
    int error_line_num = 0;
    map<char, array*> env;
    for (;;) {
      cin >> s;
      if (s == ".") break;
      if (error_line_num == 0) {
        end = s.end();
        State begin = s.begin();
        try {
          program(begin, env);
        } catch (RuntimeError e) {
          error_line_num = line_num;
        }
      }
      line_num++;
    }
    if (line_num == 1) break;
    cout << error_line_num << endl;
    for (map<char, array*>::iterator it = env.begin(); it != env.end(); it++) {
      delete it->second;
    }
  }
  return 0;
}
