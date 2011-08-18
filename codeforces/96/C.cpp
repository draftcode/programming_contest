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

char input[128][128];

int main(void) {
  int n;
  char c;
  char str[128], ret[128], lucky[2];
  scanf("%d", &n);
  rep (i, n) scanf("%s", input[i]);

  scanf("%s", str);
  strcpy(ret, str);

  scanf("%s", lucky);
  c = lucky[0] - 'a';

  int len = strlen(str);

  rep (i, n) {
    int l = strlen(input[i]);
    for (int k = 0; k + l <= len; k++) {
      if (strncasecmp(str+k, input[i], l) == 0) {
        for (int j = 0; j < l; j++) {
          if (isupper(str[k+j])) {
            if (str[k+j] - 'A' == c) {
              ret[k+j] = 'A';
              if (c == 0) ret[k+j]++;
            } else {
              ret[k+j] = c + 'A';
            }
          } else {
            if (str[k+j] - 'a' == c) {
              ret[k+j] = 'a';
              if (c == 0) ret[k+j]++;
            } else {
              ret[k+j] = c + 'a';
            }
          }
        }
      }
    }
  }
  cout << ret << endl;

  return 0;
}
