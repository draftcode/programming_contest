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
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int ceil[100][100];
int floor[100][100];

struct State {
  int height, y, x;
  State(int height, int y, int x) : height(height), y(y), x(x) {}

  bool operator<(const State &rhs) const {
    return height < rhs.height;
  }
};

void solve(void) {
  int H, N, M;
  cin >> H >> N >> M;
  for (int y = 0; y < N; y++) for (int x = 0; x < M; x++) cin >> ceil[y][x];
  for (int y = 0; y < N; y++) for (int x = 0; x < M; x++) cin >> floor[y][x];

  bool visited[N][M];
  int visit_height[N][M];
  memset(visited, 0,  sizeof(visited));
  memset(visit_height, 0, sizeof(visit_height));

  priority_queue<State> que;
  que.push(State(H, 0, 0));

  while (!que.empty()) {
    State s = que.top(); que.pop();

    if (visited[s.y][s.x] && visit_height[s.y][s.x] >= s.height) continue;
    visited[s.y][s.x] = true;
    visit_height[s.y][s.x] = s.height;
    if (s.y == N-1 && s.x == M-1) break;

    const int dy[] = { 0, 1, 0, -1 };
    const int dx[] = { 1, 0, -1, 0 };
    for (int i = 0; i < 4; i++) {
      int ny = s.y + dy[i];
      int nx = s.x + dx[i];
      if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
      if (ceil[ny][nx] - floor[ny][nx] < 50) continue;
      if (ceil[ny][nx] - floor[s.y][s.x] < 50) continue;
      if (ceil[s.y][s.x] - floor[ny][nx] < 50) continue;

      if (s.height == H && ceil[ny][nx] - s.height >= 50) {
        que.push(State(s.height, ny, nx));
      } else {
        int next_height;
        if (ceil[ny][nx] - s.height >= 50) {
          next_height = s.height;
        } else {
          next_height = ceil[ny][nx] - 50;
        }

        if (next_height - floor[s.y][s.x] >= 20) {
          next_height -= 10;
        } else {
          next_height -= 100;
        }

        if (!visited[ny][nx] || visit_height[ny][nx] < next_height) {
          que.push(State(next_height, ny, nx));
        }
      }
    }
  }

  int ans = H - visit_height[N-1][M-1];
  cout << ans/10 << '.' << ans%10;
}

int main(void) {
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  for (int i = 1; i <= T; i++) {
    cout << "Case #" << i << ": ";
    solve();
    cout << endl;
  }
  return 0;
}
