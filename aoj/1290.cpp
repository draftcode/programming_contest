#include <algorithm>
#include <functional>
#include <iostream>
#include <limits>
#include <numeric>
#include <queue>
#include <sstream>
#include <vector>

#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

#define rep(i,n) for(int i = 0; i < n; i++)
#define each(it,c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)

int dx[] = {0,1,-1,0};
int dy[] = {-1,0,0,1};

struct dice {
  char bottom, north, west;

  dice at(int i) {
    switch (i) {
      case 0: return to_north();
      case 1: return to_east();
      case 2: return to_west();
      case 3: return to_south();
    }
    return to_north();
  }

  dice to_north() {
    return (dice){north,abs(7-bottom),west};
  };

  dice to_east() {
    return (dice){abs(7-west),north,bottom};
  };

  dice to_west() {
    return (dice){west,north,abs(7-bottom)};
  };

  dice to_south() {
    return (dice){abs(7-north),bottom,west};
  };
};

int X, Y;
int initx, inity;
char field[31][31];
char colors[16];
bool visited[31][31][6][6][6][6];

#define RED  1
#define CYAN 6
#define GREEN 2
#define MAGENTA 5
#define BLUE 3
#define YELLOW 4

struct state {
  int cost; int color; dice d; int x, y;
};

int calc(void) {
  memset(visited, 0, sizeof(visited));
  queue<state> que;
  que.push((state){0, 0, (dice){CYAN,GREEN,YELLOW}, initx, inity});

  while (!que.empty()) {
    state s = que.front(); que.pop();

    if (s.color == 6) {
      return s.cost;
    }
    if (visited[s.y][s.x][s.color][s.d.bottom-1][s.d.north-1][s.d.west-1]) {
      continue;
    }
    visited[s.y][s.x][s.color][s.d.bottom-1][s.d.north-1][s.d.west-1] = true;

    for (int k = 0; k < 4; k++) {
      int nx = s.x + dx[k], ny = s.y + dy[k];
      if (nx < 0 || X <= nx || ny < 0 || Y <= ny) continue;
      dice nd = s.d.at(k);

      if (field[ny][nx] == 'w') {
        if (!visited[ny][nx][s.color][nd.bottom-1][nd.north-1][nd.west-1]) {
          que.push((state){s.cost+1, s.color, nd, nx, ny});
        }
      } else if (field[ny][nx] == 'k') {
      } else if (field[ny][nx] == abs(7-nd.bottom)) {
        if (colors[s.color] == field[ny][nx]) {
          que.push((state){s.cost+1, s.color+1, nd, nx, ny});
        }
      }
    }
  }

  return -1;
}

int main(void) {
  ios::sync_with_stdio(false);
  for (;;) {
    scanf("%d%d", &X, &Y);
    if (X == Y && Y == 0) break;
    rep (y, Y) {
      scanf("%s", field[y]);
      rep (x, X) {
        if (field[y][x] == '#') {
          initx = x;
          inity = y;
          field[y][x] ='w';
        } else {
          switch (field[y][x]) {
            case 'r': field[y][x] = RED; break;
            case 'g': field[y][x] = GREEN; break;
            case 'b': field[y][x] = BLUE; break;
            case 'c': field[y][x] = CYAN; break;
            case 'm': field[y][x] = MAGENTA; break;
            case 'y': field[y][x] = YELLOW; break;
          }
        }
      }
    }
    scanf("%s", colors);
    for (int i = 0; colors[i] != '\0'; i++) {
      switch (colors[i]) {
        case 'r': colors[i] = RED; break;
        case 'g': colors[i] = GREEN; break;
        case 'b': colors[i] = BLUE; break;
        case 'c': colors[i] = CYAN; break;
        case 'm': colors[i] = MAGENTA; break;
        case 'y': colors[i] = YELLOW; break;
      }
    }

    int ans = calc();
    if (ans == -1) {
      printf("unreachable\n");
    } else {
      printf("%d\n", ans);
    }
  }
  return 0;
}
