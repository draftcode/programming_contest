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

int test[26];
int piece[26];
int us;
char strings[1000][8];

int main(void) {
  for (;;) {
    int n;
    scanf("%d", &n);
    if (n == 0) break;

    rep (i, n) {
      scanf("%s", strings+i);
    }

    char str[8];
    scanf("%s", str);
    zclear(piece);
    us = 0;
    for (int i = 0; str[i]; i++) {
      if (str[i] == '_') {
        us++;
      } else {
        piece[str[i]-'A']++;
      }
    }

    int ret = 0;
    rep (i, n) {
      char *str = strings[i];

      int count = 0;
      memcpy(test, piece, sizeof(piece));
      for (int i = 0; str[i]; i++) {
        if (test[str[i]-'A'] > 0) {
          test[str[i]-'A']--;
        } else {
          count++;
        }
      }
      if (count <= us) {
        ret++;
      }
    }

    printf("%d\n", ret);
  }
  return 0;
}
