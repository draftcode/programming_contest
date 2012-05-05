#include <algorithm>
#include <functional>
#include <iostream>
#include <limits>
#include <numeric>
#include <queue>
#include <sstream>
#include <vector>

#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

#define rep(i,n) for(int i = 0; i < n; i++)
#define each(it,c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)

int N, M, G;
string map[16];
int a_map[16][16];
int b_map[16][16];
int c_map[16][16];

P d[] = {P(-1,0),P(0,-1),P(1,0),P(0,1),P(0,0)};
bool visited[16][16][16][16][16][16];

P a_init, b_init, c_init;
P a_goal, b_goal, c_goal;
struct State {
  int f, t;
  P a, b, c;
  State (int t, P a, P b, P c) : t(t), a(a), b(b), c(c) {
    f = t + distance();
  }

  int distance() {
    int d = a_map[a.second][a.first];
    if (G > 1) d = max(d, b_map[b.second][b.first]);
    if (G > 2) d = max(d, c_map[c.second][c.first]);
    return d;
  }

  bool reachable(void) {
    if (map[a.second][a.first] == '#') return false;
    if (G > 1 && map[b.second][b.first] == '#') return false;
    if (G > 2 && map[c.second][c.first] == '#') return false;
    if (G > 1 && a == b) return false;
    if (G > 2 && b == c) return false;
    if (G > 2 && c == a) return false;
    return true;
  }

  bool follows(const State &s) {
    if (G > 1 && a == s.b && b == s.a) return false;
    if (G > 2 && a == s.c && c == s.a) return false;
    if (G > 2 && b == s.c && c == s.b) return false;
    return true;
  }

  bool operator <(const State &rhs) const {
    return f > rhs.f;
  }
};

P operator +(P lhs, P rhs) {
  return P(lhs.first + rhs.first, lhs.second + rhs.second);
}

int solve(void) {
  priority_queue<State> que;
  State start(0, a_init,b_init,c_init);
  que.push(start);
  memset(visited, false, sizeof(visited));

  while (!que.empty()) {
    State s = que.top(); que.pop();
    if (s.a == a_goal && s.b == b_goal && s.c == c_goal) {
      return s.f;
    }

    if (visited[s.a.first][s.a.second][s.b.first][s.b.second][s.c.first][s.c.second]) {
      continue;
    }
    visited[s.a.first][s.a.second][s.b.first][s.b.second][s.c.first][s.c.second] = true;

    rep (a_i, 5) {
      rep (b_i, 5) {
        rep (c_i, 5) {
          P next_a = s.a, next_b = s.b, next_c = s.c;
          next_a = next_a + d[a_i];
          if (G > 1) { next_b = next_b + d[b_i]; }
          if (G > 2) { next_c = next_c + d[c_i]; }
          State next_s(s.t+1, next_a, next_b, next_c);

          if (next_s.reachable()) {
            if (next_s.follows(s)) {
              if (!visited[next_s.a.first][next_s.a.second][next_s.b.first][next_s.b.second][next_s.c.first][next_s.c.second]) {
                que.push(next_s);
              }
            }
          }
        }
      }
    }
  }

  return 0;
}

void calc_map(int m[16][16], P init) {
  rep (y, M) {
    rep (x, N) {
      m[y][x] = -1;
    }
  }
  queue<pair<int, P> > que;
  que.push(make_pair(0, init));

  while (!que.empty()) {
    pair<int, P> s = que.front(); que.pop();
    P p = s.second;
    int t = s.first;

    if (m[p.second][p.first] != -1) continue;
    m[p.second][p.first] = t;

    rep (i, 4) {
      P next_p = p + d[i];
      if (map[next_p.second][next_p.first] != '#') {
        if (m[next_p.second][next_p.first] == -1) {
          que.push(make_pair(t+1, next_p));
        }
      }
    }
  }
}

int main(void) {
  for (;;) {
    cin >> N >> M >> G;
    if (N == 0) break;
    a_init = P(-1,-1); b_init = P(-1,-1); c_init = P(-1,-1);
    a_goal = P(-1,-1); b_goal = P(-1,-1); c_goal = P(-1,-1);
    string t; getline(cin, t);
    rep (y, M) {
      getline(cin, map[y]);
      rep (x, N) {
        switch (map[y][x]) {
          case 'a': a_goal = P(x,y); break;
          case 'b': b_goal = P(x,y); break;
          case 'c': c_goal = P(x,y); break;
          case 'A': a_init = P(x,y); break;
          case 'B': b_init = P(x,y); break;
          case 'C': c_init = P(x,y); break;
        }
      }
    }
    calc_map(a_map, a_goal);
    if (G > 1) calc_map(b_map, b_goal);
    if (G > 2) calc_map(c_map, c_goal);

    printf("%d\n", solve());
  }
  return 0;
}
