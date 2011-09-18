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

int cnt[256];

int main(void) {
  int n, m;
  scanf("%d%d", &n, &m);
  int ans = 0;
  int prev_x = 0;
  int prev_y = 0;
  rep (i, n) {
    char s[256];
    scanf("%s", s);
    int x;
    if (i % 2 == 0) {
      x = m - 1;
      while (x != -1 && s[x] == 'G') x--;
      if (x != -1) {
        ans += abs(prev_x - x);
        ans += i - prev_y;
        prev_x = x;
        prev_y = i;
      }
    } else {
      x = 0;
      while (x != m && s[x] == 'G') x++;
      if (x != m) {
        ans += abs(prev_x - x);
        ans += i - prev_y;
        prev_x = x;
        prev_y = i;
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}
