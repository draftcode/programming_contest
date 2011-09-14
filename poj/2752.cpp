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

char s[400001];

int main(void) {
  while (scanf("%s", s) != -1) {
    int len = strlen(s);

    for (int i = 1; i < len; i++) {
      bool success = true;
      for (int k = 0; k < i; k++) {
        if (s[k] != s[len-i+k]) {
          success = false;
          break;
        }
      }

      if (success) {
        cout << i << ' ';
      }
    }

    cout << len << endl;
  }
  return 0;
}
