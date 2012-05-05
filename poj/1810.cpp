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

int main(void) {
  int tests;
  scanf("%d", &tests);
  for (int _ = 0; _ < tests; _++) {
    int K, N, M;
    scanf("%d%d%d", &K, &N, &M);
    vector<vector<int> > mines(N, vector<int>(N, 0));
    for (int __ = 0; __ < K; __++) {
      double dx, dy;
      scanf("%lf%lf", &dx, &dy);
      int x = int(dx), y = int(dy);
      mines[y][x]++;
    }

    for (int i = 1; i < N; i++) {
      mines[i][0] += mines[i-1][0];
      mines[0][i] += mines[0][i-1];
    }

    for (int y = 1; y < N; y++)
      for (int x = 1; x < N; x++) {
        mines[y][x] += mines[y-1][x] + mines[y][x-1] - mines[y-1][x-1];
      }

    int maxx = 0, maxy = 0, maxmines = mines[M-1][M-1];
    for (int y = 1; y + M < N; y++)
      for (int x = 1; x + M < N; x++) {
        int num =
            mines[y+M-1][x+M-1]
            - mines[y+M-1][x-1]
            - mines[y-1][x+M-1]
            + mines[y-1][x-1];
        if (num >= maxmines) {
          maxx = x;
          maxy = y;
          maxmines = num;
        }
      }

    printf("%d %d\n", maxx, maxy);
  }
  return 0;
}
