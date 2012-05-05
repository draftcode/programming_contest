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

#define WHITE 1
#define BLACK 2

int n, m;
char field[9][9][9];

void putball(int x, int y, char color) {
  int z = n;
  while (z != 0) {
    if (field[x][y][z-1] != 0) {
      break;
    }
    z--;
  }
  field[x][y][z] = color;
}

char check_direction(int x, int y, int z, int dx, int dy, int dz) {
#define in(k) (0 <= (k) && (k) < n)
  char prev = 0;
  int count = 0;
  for (int i = 0;; i++) {
    if (in(x+dx*i) && in(y+dy*i) && in(z+dz*i)) {
      if (prev == field[x+dx*i][y+dy*i][z+dz*i]) {
        count++;
      } else {
        prev = field[x+dx*i][y+dy*i][z+dz*i];
        count = 1;
      }

      if (count == m && field[x+dx*i][y+dy*i][z+dz*i] != 0) {
        return field[x+dx*i][y+dy*i][z+dz*i];
      }
    } else {
      break;
    }
  }

  return 0;
#undef in
}

char check(void) {
#define f(e) do { char c = (e); if (c != 0) return c; } while(0)
  // one dimensional
  for (int x = 0; x < n; x++) {
    for (int y = 0; y < n; y++) {
      f(check_direction(x,y,0,0,0,1));
    }
  }
  for (int x = 0; x < n; x++) {
    for (int z = 0; z < n; z++) {
      f(check_direction(x,0,z,0,1,0));
    }
  }
  for (int y = 0; y < n; y++) {
    for (int z = 0; z < n; z++) {
      f(check_direction(0,y,z,1,0,0));
    }
  }
  // two dimensional
  for (int z = 0; z < n; z++) {
    for (int x = 0; x < n; x++) { f(check_direction(x,0,z,1,1,0)); }
    for (int y = 0; y < n; y++) { f(check_direction(0,y,z,1,1,0)); }
    for (int x = 0; x < n; x++) { f(check_direction(x,0,z,-1,1,0)); }
    for (int y = 0; y < n; y++) { f(check_direction(n-1,y,z,-1,1,0)); }
  }
  for (int x = 0; x < n; x++) {
    for (int z = 0; z < n; z++) { f(check_direction(x,0,z,0,1,1)); }
    for (int y = 0; y < n; y++) { f(check_direction(x,y,0,0,1,1)); }
    for (int z = 0; z < n; z++) { f(check_direction(x,n-1,z,0,-1,1)); }
    for (int y = 0; y < n; y++) { f(check_direction(x,y,0,0,-1,1)); }
  }
  for (int y = 0; y < n; y++) {
    for (int z = 0; z < n; z++) { f(check_direction(0,y,z,1,0,1)); }
    for (int x = 0; x < n; x++) { f(check_direction(x,y,0,1,0,1)); }
    for (int z = 0; z < n; z++) { f(check_direction(n-1,y,z,-1,0,1)); }
    for (int x = 0; x < n; x++) { f(check_direction(x,y,0,-1,0,1)); }
  }
  // three dimensional
  for (int x = 0; x < n; x++) {
    for (int y = 0; y < n; y++) {
      for (int z = 0; z < n; z++) {
        f(check_direction(x,y,z,1,1,1));
        f(check_direction(x,y,z,1,-1,1));
        f(check_direction(x,y,z,-1,1,1));
        f(check_direction(x,y,z,-1,-1,1));
      }
    }
  }
  return 0;
}

int main(void) {
  ios::sync_with_stdio(false);
  int p;
  for (;;) {
    cin >> n >> m >> p;
    if (n == 0 && m ==  0 && p == 0) break;
    fill_n(field[0][0], sizeof(field)/sizeof(char), 0);

    char winner = 0;
    int win_index = INT_MAX;
    for (int i = 0; i < p; i++) {
      char color;
      if (i % 2 == 0) {
        color = BLACK;
      } else {
        color = WHITE;
      }

      int x, y;
      cin >> x >> y;
      x--; y--;
      if (winner == 0) {
        putball(x, y, color);
        winner = check();
        if (winner != 0) {
          win_index = i;
        }
      }
    }

    if (winner == 0) {
      cout << "Draw" << endl;
    } else if (winner == WHITE) {
      cout << "White " << win_index + 1 << endl;
    } else if (winner == BLACK) {
      cout << "Black " << win_index + 1 << endl;
    }
  }
  return 0;
}
