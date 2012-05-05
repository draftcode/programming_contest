#include <algorithm>
#include <functional>
#include <iostream>
#include <limits>
#include <numeric>
#include <queue>
#include <vector>

#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

#define rep(i,n) for(int i = 0; i < n; i++)
#define each(it,c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)

int R, C, M;
char room[50][50];
int consumption[50][50];
int turn[50][50];
vector<P> visit;
vector<int> timestamp[50][50];

bool visited[50][50];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int add_timestamps(int t, P start, P goal) {
  visited[start.second][start.first] = true;
  if (start == goal) {
    return t;
  }
  rep (i, 4) {
    P next(start.first+dx[i], start.second+dy[i]);
    if (next.first >= 0 && next.first < C && next.second >= 0 && next.second < R) {
      if (room[next.second][next.first] == '.') {
        if (!visited[next.second][next.first]) {
          int goal_time = add_timestamps(t+1, next, goal);
          if (goal_time != -1) {
            timestamp[start.second][start.first].push_back(t);
            return goal_time;
          }
        }
      }
    }
  }
  return -1;
}

void calc_stamps(void) {
  int t = 0;
  for (int i = 1; i < M; i++) {
    fill(&visited[0][0], (&visited[49][49])+1, false);
    t = add_timestamps(t, visit[i-1], visit[i]);
  }

  P goal = visit[M-1];
  timestamp[goal.second][goal.first].push_back(t);
}

int main(void) {
  scanf("%d%d%d", &R, &C, &M);
  rep (y, R) scanf("%s", room[y]);
  rep (y, R) rep (x, C) scanf("%d", &consumption[y][x]);
  rep (y, R) rep (x, C) scanf("%d", &turn[y][x]);
  rep (y, R) rep (x, C) {
    int c;
    scanf("%d", &c);
    turn[y][x] += c;
  }
  rep (i, M) {
    int x, y;
    scanf("%d%d", &y, &x);
    visit.push_back(P(x,y));
  }
  calc_stamps();
  
  int ans = 0;
  rep (y, R) {
    rep (x, C) {
      if (timestamp[y][x].size() > 0) {
        ans += turn[y][x];
        for (unsigned int i = 1; i < timestamp[y][x].size(); i++) {
          int t = timestamp[y][x][i] - timestamp[y][x][i-1];
          ans += min(t*consumption[y][x], turn[y][x]);
        }
      }
    }
  }
  printf("%d\n", ans);

  return 0;
}
