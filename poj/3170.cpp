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

int W, H;
int field[1000][1000];
int visited[1000][1000][2];
P start, goal;

struct State {
  P pos; bool haves; int cost;
  State(P pos, bool haves, int cost) : pos(pos), haves(haves), cost(cost) {}
  bool operator <(const State &s) const {
    return this->cost > s.cost;
  }
};

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int calc(void) {
  fill_n(**visited, sizeof(visited)/sizeof(visited[0][0][0]), INT_MAX);
  priority_queue<State> Q;
  Q.push(State(start, false, 0));
  while (!Q.empty()) {
    State s = Q.top(); Q.pop();
    if (s.pos == goal && s.haves) {
      return s.cost;
    }
    if (visited[s.pos.second][s.pos.first][s.haves] < s.cost) {
      continue;
    }
    visited[s.pos.second][s.pos.first][s.haves] = s.cost;

    bool next_haves = (field[s.pos.second][s.pos.first] == 4 || s.haves);
    for (int i = 0; i < 4; i++) {
      P next_pos(s.pos.first+dx[i], s.pos.second+dy[i]);
      if (0 <= next_pos.first && 0 <= next_pos.second
       && next_pos.first < W && next_pos.second < H)
      {
        if (field[next_pos.second][next_pos.first] != 1) {
          if (next_haves || field[next_pos.second][next_pos.first] != 3) {
            if (visited[next_pos.second][next_pos.first][next_haves] > s.cost+1) {
              Q.push(State(next_pos, next_haves, s.cost+1));
            }
          }
        }
      }
    }
  }
  return -1;
}

int main(void) {
  scanf("%d%d", &W, &H);
  for (int i = 0; i < H; i++)
    for (int k = 0; k < W; k++) {
      scanf("%d", &(field[i][k]));
      if (field[i][k] == 2)
        start = P(k, i);
      else if (field[i][k] == 3)
        goal = P(k, i);
    }
  printf("%d\n", calc());
  return 0;
}
