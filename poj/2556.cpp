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

enum direction {
  righ, up, lft, down
};

int main(void) {
  string s;
  while (cin >> s) {
    direction current = righ;
    cout << 300 << " " << 420 << " " << "moveto" << endl;
    cout << 310 << " " << 420 << " " << "lineto" << endl;
    int x = 310, y = 420;

    each (pc, s) {
      if (*pc == 'V') {
        switch (current) {
          case righ:
            y += 10; current = up;
            break;
          case up:
            x -= 10; current = lft;
            break;
          case lft:
            y -= 10; current = down;
            break;
          case down:
            x += 10; current = righ;
            break;
        }
      } else {
        switch (current) {
          case righ:
            y -= 10; current = down;
            break;
          case up:
            x += 10; current = righ;
            break;
          case lft:
            y += 10; current = up;
            break;
          case down:
            x -= 10; current = lft;
            break;
        }
      }
      cout << x << " " << y << " " << "lineto" << endl;
    }

    cout << "stroke" << endl << "showpage" << endl;
  }
  return 0;
}
