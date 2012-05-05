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

string expr(State &begin);
string term(State &begin);
string factor(State &begin);

string expr(State &begin) {
  string ret = term(begin);

  for (;;) {
    if (*begin == '+' || *begin == '-') {
      string new_ret;
      new_ret += *begin++;
      new_ret += ret;
      new_ret += term(begin);
      ret = new_ret;
    } else {
      break;
    }
  }

  return ret;
}

string term(State &begin) {
  string ret = factor(begin);

  for (;;) {
    if (*begin == '*' || *begin == '/') {
      string new_ret;
      new_ret += *begin++;
      new_ret += ret;
      new_ret += term(begin);
      ret = new_ret;
    } else {
      break;
    }
  }

  return ret;
}

string factor(State &begin) {
  if (*begin == '(') {
    begin++;
    string ret = expr(begin);
    begin++;
    return ret;
  } else {
    string ret;
    ret.push_back(*begin++);
    return ret;
  }
}

void print_prefix(State &s, char upper_op, bool isright) {
  if (islower(*s)) {
    putchar(*s++);
  } else if (
      ((*s == '+' || *s == '-') && (upper_op == '*' || upper_op == '/'))
   || ((*s == '+' || *s == '-') && upper_op == '-' && isright)
   || ((*s == '*' || *s == '/') && upper_op == '/' && isright)
   ) {
    char op = *s++;
    putchar('(');
    print_prefix(s, op, false);
    putchar(op);
    print_prefix(s, op, true);
    putchar(')');
  } else {
    char op = *s++;
    print_prefix(s, op, false);
    putchar(op);
    print_prefix(s, op, true);
  }
}

int main(void) {
  int n;
  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    char str[1024];
    scanf("%s", str);

    string s = str;
    State begin = s.begin();
    string prefix = expr(begin);
    begin = prefix.begin();
    print_prefix(begin, ' ', false);
    putchar('\n');
  }
  return 0;
}
