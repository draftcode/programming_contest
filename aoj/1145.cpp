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
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

#define rep(i,n) for(int i = 0; i < n; i++)
#define each(it,c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)

typedef string::const_iterator State;
class ParseError {};

struct Sequence {
  int repeat;
  char c;
  struct Sequence *repeatSeq;
  struct Sequence *nextSeq;

  Sequence() : repeat(1), repeatSeq(NULL), nextSeq(NULL) {}

  ~Sequence() {
    if (repeatSeq != NULL) delete repeatSeq;
    if (nextSeq != NULL) delete nextSeq;
  }

  char find(int &t) {
    if (repeatSeq != NULL) {
      for (int i = 0; i < repeat; i++) {
        char ret = repeatSeq->find(t);
        if (ret != '0') {
          return ret;
        }
      }
      if (nextSeq != NULL) {
        return nextSeq->find(t);
      }
      return '0';
    } else {
      if (t == 0) {
        return c;
      } else if (nextSeq != NULL) {
        t--;
        return nextSeq->find(t);
      } else {
        t--;
        return '0';
      }
    }
  }
};

Sequence *expr(State &);
Sequence *factor(State &begin) {
  if ('A' <= *begin && *begin <= 'Z') {
    Sequence *ret = new Sequence();
    ret->c = *begin;
    begin++;
    return ret;
  } else if (*begin == '(') {
    begin++;
    Sequence *ret = expr(begin);
    if (*begin == ')') {
      begin++;
      return ret;
    } else {
      delete ret;
      throw ParseError();
    }
  } else {
    throw ParseError();
  }
}

Sequence *term(State &begin) {
  if (isdigit(*begin)) {
    Sequence *ret = new Sequence();
    ret->repeat = 0;
    while (isdigit(*begin)) {
      ret->repeat *= 10;
      ret->repeat += *begin - '0';
      begin++;
    }
    ret->repeatSeq = factor(begin);
    return ret;
  } else {
    return factor(begin);
  }
}

Sequence *expr(State &begin) {
  Sequence *ret = term(begin);
  Sequence *last = ret;
  for (;;) {
    try {
      last->nextSeq = term(begin);
      last = last->nextSeq;
    } catch (ParseError e) {
      break;
    }
  }

  return ret;
}


int main(void) {
  ios::sync_with_stdio(false);
  string s;
  int t;
  while (cin >> s >> t, s != "0") {
    State begin = s.begin();
    Sequence *tree = expr(begin);
    cout << tree->find(t) << endl;
    delete tree;
  }
  return 0;
}

