#include <algorithm>
#include <functional>
#include <iostream>
#include <limits>
#include <numeric>
#include <queue>
#include <sstream>
#include <vector>
#include <set>

#include <cctype>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int H, W;
string input[501];
int map[501][501];

int main(void) {
  ios::sync_with_stdio(false);
  for (;;) {
    cin >> H >> W;
    if (H == 0 && W == 0) break;

    for (int y = 0; y < H; y++) {
      cin >> input[y];

      int count = 0;
      for (int x = W-1; x >= 0; x--) {
        if (input[y][x] == '.') {
          map[y][x] = ++count;
        } else {
          map[y][x] = count = 0;
        }
      }
    }

    int ans = 0;
    for (int y = 0; y < H; y++) {
      for (int x = 0; x < W; x++) {
        int wid = map[y][x];
        int t = wid;
        for (int hei = 1; y+hei < H && wid != 0; hei++) {
          wid = min(wid, map[y+hei][x]);
          t = max(t, wid*(hei+1));
        }
        ans = max(ans, t);
      }
    }
    cout << ans << endl;
  }
  return 0;
}
