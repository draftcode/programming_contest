#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#include <numeric>
#include <cstring>
#include <stack>
#include <cstdio>
#include <cmath>
#include <climits>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

#define rep(i,n) for(int i = 0; i < n; i++)
#define each(it,c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define all(c) (c).begin(), (c).end()
#define zclear(v) memset(v, 0, sizeof(v))

char field[500001];

bool add_constraint(int pos, int constraint, bool &updated) {
  int pre = field[pos];
  if ((pre | constraint) == constraint) {
    updated = false;
    return true;
  } else if ((pre & constraint) == 0) {
    return false;
  } else {
    field[pos] = pre & constraint;
    updated = true;
    return true;
  }
}

int main(void) {
  int n, m;
  scanf("%d%d", &n, &m);
  fill(field, field+n*m, 15);
  stack<P> stk;
  rep (y, n) {
    rep (x, m) {
      for (;;) {
        char c = getchar();
        if (c == '1') {
          field[y*m+x] = 1;
          stk.push(P(x,y));
          break;
        } else if (c == '2') {
          field[y*m+x] = 2;
          stk.push(P(x,y));
          break;
        } else if (c == '3') {
          field[y*m+x] = 4;
          stk.push(P(x,y));
          break;
        } else if (c == '4') {
          field[y*m+x] = 8;
          stk.push(P(x,y));
          break;
        } else if (c == '.') {
          break;
        }
      }
    }
  }
  
  while (!stk.empty()) {
    P p = stk.top(); stk.pop();
    int x = p.first, y = p.second;
    char constraint = field[y*m+x];
    bool updated;
    if ((constraint & 1) != 0) {
      if (y != 0) {
        if (!add_constraint((y-1)*m+(x), 6, updated)) { printf("0\n"); return 0; }
        if (updated) stk.push(P(y-1,x));
      }
      if (x != 0) {
        if (!add_constraint((y)*m+(x-1), 12, updated)) { printf("0\n"); return 0; }
        if (updated) stk.push(P(y,x-1));
      }
    }
    if ((constraint & 2) != 0) {
      if (y != n-1) {
        if (!add_constraint((y+1)*m+(x), 9, updated)) { printf("0\n"); return 0; }
        if (updated) stk.push(P(y+1,x));
      }
      if (x != 0) {
        if (!add_constraint((y)*m+(x-1), 12, updated)) { printf("0\n"); return 0; }
        if (updated) stk.push(P(y,x-1));
      }
    }
    if ((constraint & 4) != 0) {
      if (y != n-1) {
        if (!add_constraint((y+1)*m+(x), 9, updated)) { printf("0\n"); return 0; }
        if (updated) stk.push(P(y+1,x));
      }
      if (x != m-1) {
        if (!add_constraint((y)*m+(x+1), 3, updated)) { printf("0\n"); return 0; }
        if (updated) stk.push(P(y,x+1));
      }
    }
    if ((constraint & 8) != 0) {
      if (y != 0) {
        if (!add_constraint((y-1)*m+(x), 6, updated)) { printf("0\n"); return 0; }
        if (updated) stk.push(P(y-1,x));
      }
      if (x != m-1) {
        if (!add_constraint((y)*m+(x+1), 3, updated)) { printf("0\n"); return 0; }
        if (updated) stk.push(P(y,x+1));
      }
    }
  }
  
  int answer = 1;
  rep (i, n*m) {
    int constraint = field[i];
    cout << constraint << endl;
    if (constraint == 15) {
      answer *= 4;
    } else if (constraint == 1 || constraint == 2 || constraint == 4 || constraint == 8) {
    } else {
      answer *= 2;
    }
    
    if (answer >= 1000003) answer -= 1000003;
  }
  printf("%d\n", answer);
  return 0;
}
