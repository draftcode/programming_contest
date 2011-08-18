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

int main(void) {
  char str[128];
  scanf("%s", str);
  char c = '\0';
  int a = 1;
  for (unsigned int i = 0; i < strlen(str); i++) {
    if (i == 0) {
      c = str[i];
    } else {
      if (c == str[i]) {
        a++;

        if (a >= 7) {
          printf("YES\n");
          return 0;
        }
      } else {
        c = str[i];
        a = 1;
      }
    }
  }

  printf("NO\n");
  return 0;
}
