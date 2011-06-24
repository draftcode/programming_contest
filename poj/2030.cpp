#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#include <numeric>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <climits>
using namespace std;
typedef long long ll;

#define rep(i,n) for(int i = 0; i < n; i++)
#define each(it,c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define all(c) (c).begin(), (c).end()
#define zclear(v) memset(v, 0, sizeof(v))

int w, h;
char map[80][80]; // y x
string dp[80][80];

bool operator < (const string& lhs, const string& rhs) {
  if (lhs.size() != rhs.size()) {
    return lhs.size() < rhs.size();
  }

  for (unsigned int i = 0; i < lhs.size(); i++) {
    if (lhs[i] != rhs[i]) {
      return lhs[i] < rhs[i];
    }
  }

  return false;
}

string solve(void) {
  rep (y, h)
    rep (x, w) {
      dp[y][x] = "";
    }

  rep (y, h)
    rep (x, w) {
      if (isdigit(map[y][x])) {
        string s;
        if (y-1 >= 0) s = dp[y-1][x];
        if (x-1 >= 0 && s < dp[y][x-1]) s = dp[y][x-1];
        if (map[y][x] == '0' && s.empty()) {
        } else {
          dp[y][x] = s + map[y][x];
        }
      }
    }

  string ret;
  rep (y, h)
    rep (x, w) {
      if (ret < dp[y][x]) {
        ret = dp[y][x];
      }
    }

  return ret;
}

int main(void) {
  for (;;) {
    scanf("%d%d", &w, &h); if (w == 0 && h == 0) break;
    rep (y, h) scanf("%s", map+y);

    printf("%s\n", solve().c_str());
  }
  return 0;
}
