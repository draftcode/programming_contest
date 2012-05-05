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

struct Chand {
  int optstart;
  vector<Chand*> childs;
  Chand() : optstart(0), childs() {}
};

Chand *parse(string s) {
  vector<Chand*> stack;
  int i = 0;
  while (s[i] != '\0') {
    if (s[i] == 'a') {
      stack.push_back(NULL);
    } else {
      int n = s[i] - '0';
      Chand *c = new Chand();
      for (int i = 0; i < n; i++) {
        c->childs.push_back(stack.back());
        stack.pop_back();
      }
      reverse(c->childs.begin(), c->childs.end());
      stack.push_back(c);
    }
    i++;
  }
  return stack[0];
}

int optimize(Chand *c) {
  if (c == NULL) {
    return 1;
  }

  int childssize = c->childs.size();
  vector<int> v(childssize);
  for (int i = 0; i < childssize; i++) {
    if (c->childs[i] == NULL) {
      v[i] = 0;
    } else {
      v[i] = optimize(c->childs[i]);
    }
  }

  int min_stk_size = INT_MAX;
  int min_pos = 0;
  for (int start = 0; start < childssize; start++) {
    if (v[start] == 0) {
      continue;
    }
    int sz = 1;
    int max_sz = max(1, v[start]);
    int i = (start+1) % childssize;
    while (i != start) {
      max_sz = max(max_sz, sz + v[i]);
      sz += 1;
      max_sz = max(max_sz, sz);
      i = (i+1) % childssize;
    }

    if (min_stk_size > max_sz) {
      min_stk_size = max_sz;
      min_pos = start;
    }
  }
  if (min_stk_size == INT_MAX) {
    min_pos = 0;
    min_stk_size = childssize;
  }
  c->optstart = min_pos;
  return min_stk_size;
}

void output(Chand *c) {
  if (c == NULL) {
    putchar('a');
  } else {
    if (c->childs[c->optstart] == NULL) {
      putchar('a');
    } else {
      output(c->childs[c->optstart]);
    }

    int childssize = c->childs.size();
    int i = (c->optstart+1) % childssize;
    while (i != c->optstart) {
      if (c->childs[i] == NULL) {
        putchar('a');
      } else {
        output(c->childs[i]);
      }
      i = (i+1) % childssize;
    }
    putchar('0' + childssize);
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  string s; cin >> s;
  Chand *c = parse(s);
  printf("%d\n", optimize(c));
  output(c);
  putchar('\n');
  return 0;
}
