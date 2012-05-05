#include <algorithm>
#include <functional>
#include <iostream>
#include <limits>
#include <numeric>
#include <queue>
#include <sstream>
#include <vector>
#include <map>
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

int N, H;
bool cube[500][500][500];

void do_fill(int x, int y, int z, int dx, int dy, int dz) {
  while (x < N && y < N && z < N) {
    cube[x][y][z] = false;
    x += dx;
    y += dy;
    z += dz;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  for (;;) {
    cin >> N >> H;
    if (N == 0 && H == 0) break;
    fill(cube[0], cube[500], true);
    for (int h = 0; h < H; h++) {
      string s; int x, y;
      cin >> s >> x >> y;
      if (s == "xy") {
        do_fill(x-1, y-1, 0, 0, 0, 1);
      } else if (s == "xz") {
        do_fill(x-1, 0, y-1, 0, 1, 0);
      } else if (s == "yz") {
        do_fill(0, x-1, y-1, 1, 0, 0);
      }
    }
  }
  return 0;
}
