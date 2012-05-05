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

int H, W;
string field[200];
int visited[200][200];

struct State {
  int x, y, cost;
  State(int x, int y, int cost) : x(x), y(y), cost(cost) {}
  bool operator< (const State &rhs) const {
    if (this->y == rhs.y) {
      return this->cost > rhs.cost;
    }
    return this->y < rhs.y;
  }
};

int dx[] = {-1, 0, 1};
int dy[] = {0, 1, 0};

int calc(int x) {
  fill(visited[0], visited[200], INT_MAX);
  priority_queue<State> que;

  que.push(State(x, 0, 0));
  while (!que.empty()) {
    State s = que.top(); que.pop();
    if (s.y == H) return s.cost;
    if (visited[s.y][s.x] < s.cost) continue;
    visited[s.y][s.x] = s.cost;
    for (int i = 0; i < 3; i++) {
      int nx = s.x+dx[i];
      int ny = s.y+dy[i];
      if (0 <= nx && nx < W) {
        if (ny == H || field[ny][nx] == 'S') {
          if (ny == H || visited[ny][nx] > s.cost+1) {
            que.push(State(nx, ny, s.cost+1));
          }
        }
      }
    }
  }
  return INT_MAX;
}

int main(void) {
  ios::sync_with_stdio(false);
  for (;;) {
    cin >> H >> W;
    if (H == 0 && W == 0) break;
    for (int i = 0; i < H; i++) {
      cin >> field[i];
      for (int j = 1; j < W; j++) {
        if (field[i][j-1] == 'S' && field[i][j] == 'B') {
          field[i][j] = 'S';
          break;
        }
      }
    }

    int ans = INT_MAX;
    for (int j = 0; j < W; j++) {
      if (field[0][j] == 'S') {
        ans = min(ans, calc(j));
        // cerr << ans << endl;
      } else if (field[0][j] == 'B') break;
    }
    cout << ans << endl;
  }
  return 0;
}
