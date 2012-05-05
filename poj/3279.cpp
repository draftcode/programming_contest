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

const int dx[] = {-1, 0, 0, 0, 1};
const int dy[] = {0, -1, 0, 1, 0};

int M, N;
int tile[15][15];

int opt[15][15];
int flip[15][15];

int get(int x, int y) {
  int c = tile[y][x];
  for (int d = 0; d < 5; d++) {
    int x2 = x + dx[d], y2 = y + dy[d];
    if (0 <= x2 && x2 < N && 0 <= y2 && y2 < M) {
      c += flip[y2][x2];
    }
  }
  return c % 2;
}

int calc(void) {
  for (int y = 1; y < M; y++) {
    for (int x = 0; x < N; x++) {
      if (get(x, y-1) != 0) {
        flip[y][x] = 1;
      }
    }
  }

  for (int x = 0; x < N; x++) {
    if (get(x, M-1) != 0) {
      return -1;
    }
  }

  int ret = 0;
  for (int y = 0; y < M; y++) {
    for (int x = 0; x < N; x++) {
      ret += flip[y][x];
    }
  }
  return ret;
}

int main(void) {
  scanf("%d%d", &M, &N);
  for (int y = 0; y < M; y++) {
    for (int x = 0; x < N; x++) {
      scanf("%d", &(tile[y][x]));
    }
  }

  int ans = -1;

  for (int i = 0; i < (1 << N); i++) {
    fill(flip[0], flip[15], 0);
    for (int j = 0; j < N; j++) {
      flip[0][N-j-1] = (i >> j) & 1;
    }

    int num = calc();
    if (num >= 0 && (ans < 0 || ans > num)) {
      ans = num;
      copy(flip[0], flip[15], opt[0]);
    }
  }

  if (ans < 0) {
    printf("IMPOSSIBLE\n");
  } else {
    for (int y = 0; y < M; y++) {
      for (int x = 0; x < N; x++) {
        printf("%d%c", opt[y][x], x+1 == N ? '\n' : ' ');
      }
    }
  }
  return 0;
}
