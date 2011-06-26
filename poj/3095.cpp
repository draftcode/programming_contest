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

int len;
char s[96];

int moving(int i, int dx) {
  while (0 <= i && i < len) {
    if (s[i] == '.') {
      return 100;
    } else if (s[i] == '_') {
      i += dx;
    } else {
      return 0;
    }
  }
  return 100;
}

int main(void) {
  while (scanf("%s", s), s[0] != '#') {
    int acc = 0;
    len = strlen(s);
    for (int i = 0; i < len; i++) {
      if (s[i] == '/') {
        acc += moving(i-1, -1);
      } else if (s[i] == '\\') {
        acc += moving(i+1, 1);
      } else if (s[i] == '.') {
        acc += 100;
      } else if (s[i] == '|') {
        acc += (moving(i-1, -1) + moving(i+1, 1))/2;
      }
    }
    printf("%d\n", acc/len);
  }
  return 0;
}
