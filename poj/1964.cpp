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
#include <stack>

#include <cctype>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int in[1000][1000];

void solve(void) {
  int N, M;
  scanf("%d%d", &N, &M);
  memset(in, 0, sizeof(in));

  for (int y = 0; y < N; y++) {
    for (int x = 0; x < M; x++) {
      char s[8]; scanf("%s", s);
      if (s[0] == 'F') {
        in[y][x] = 1;
      } else {
        in[y][x] = 0;
      }
    }

    int count = 0;
    for (int x = M-1; x >= 0; x--) {
      if (in[y][x] != 0) {
        in[y][x] = ++count;
      } else {
        count = 0;
      }
    }
  }

  int ans = 0;
  for (int x = 0; x < M; x++) {
    stack<P> stk;
    for (int y = 0; y < N; y++) {
      if (in[y][x] == 0) {
        while (!stk.empty()) {
          P p = stk.top(); stk.pop();
          ans = max(ans, p.first * (y - p.second));
        }
        continue;
      }
      while (!stk.empty() && stk.top().first > in[y][x]) {
        P p = stk.top(); stk.pop();
        ans = max(ans, p.first * (y - p.second));
      }

      if (stk.size() == 0 || stk.top().first < in[y][x]) {
        stk.push(P(in[y][x], y));
      }
    }
    while (!stk.empty()) {
      P p = stk.top(); stk.pop();
      ans = max(ans, p.first * (N - p.second));
    }
  }
  printf("%d\n", ans*3);
}

int main(void) {
  int T; scanf("%d", &T);
  for (int t = 0; t < T; t++) {
    solve();
  }
  return 0;
}
