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

string items[20];
int order[20];
int res[20];

int main(void) {
  int x;
  scanf("%d", &x);
  rep (_i, x) {
    int n, m;
    scanf("%d%d", &n, &m);
    rep (i, n) {
      char s[10];
      scanf("%s", s);
      items[i] = s;
      order[i] = i;
      res[i] = -1;
    }

    rep (i, m) {
      int s, r;
      scanf("%d%d", &s, &r);
      order[s-1] = -1;
      res[r-1] = s-1;
    }

    int l = 0;
    rep (i, n) {
      if (res[i] == -1) {
        while (order[l] == -1) l++;
        res[i] = order[l];
        l++;
      }
      printf("%s", items[res[i]].c_str());
      if (i == n-1) { putchar('\n'); } else { putchar(' '); }
    }
  }
  return 0;
}
