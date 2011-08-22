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
  int cases;
  cin >> cases;

  char str[1024];
  zclear(str);
  rep (_i, cases) {
    int n, k;
    cin >> n >> k;
    // abk * n + 0 = kab
    //   k * n + 0 =  xb
    //  b  * n + x = ya
    // a   * n + y = k
    //
    // 128205 * 4 + 0 = 512820
    //      5 * 4 + 0 =     20
    //     0  * 4 + 2 =    02
    //    2   * 4 + 0 =   08
    //   8    * 4 + 0 =  32
    //  2     * 4 + 3 = 11
    // 1      * 4 + 1 = 5
    int a = k, b = 0;
    bool done = false;
    for (int i = 0; i < 1023; i++) {

      int t = a * n + b;
      if (t == k) {
        if (str[i-1] == '0') break;
        for (int j = i - 1; j >= 0; j--) {
          putchar(str[j]);
        }
        putchar(k + '0');
        putchar('\n');
        done = true;
        break;
      }
      str[i] = (t % 10) + '0';
      a = t % 10;
      b = t / 10;
    }

    if (!done) {
      puts("0");
    }
  }
  return 0;
}
