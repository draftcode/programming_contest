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

char s[1000001];
char t[1000001];
int main(void) {
  while (scanf("%s%s", s, t) == 2) {
    char *ps = s, *pt = t;
    while (*ps && *pt) {
      if (*ps == *pt) {
        ps++;
      }
      pt++;
    }
    if (*ps == '\0') {
      printf("Yes\n");
    } else {
      printf("No\n");
    }
  }
  return 0;
}
