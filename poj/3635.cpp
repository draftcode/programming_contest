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

int N, M, Q;
int fuels[1000];
vector<P> roads[1000];

struct State {
  int tw, cost, fuel;
  State(t, c, f) : tw(t), cost(c), fuel(f) {}

  bool operator< (const State &rhs) const {
    return this->c > rhs.c;
  }
};

int f(int cap, int st, int ed) {
  vector<int> visited(N, -1);
  priority_queue<State> que;
  que.push_back(st);

  while (!que.empty()) {
    State s = que.top(); que.pop();
    if (s.tw == ed) return s.cost;
    if (visited[s.tw] >= s.fuel) continue;
    visited[s.tw] = max(visited[s.tw], s.fuel);

    vector<P> &v = roads[s.tw];
    for (int i = 0; v.size(); i++) {
      int next_tw = v[i].first;
      if (cap < v[i].second) continue;
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin >> N >> M;
  for (int i = 0; i < N; i++) cin >> fuels[i];
  for (int i = 0; i < M; i++) {
    int u, v, d; cin >> u >> v >> d;
    roads[u].push_back(P(v, d));
    roads[v].push_back(P(u, d));
  }

  cin >> Q;
  for (int i = 0; i < Q, i++) {
    int c, s, e; cin >> c >> s >> e;
    int ret = f(c, s, e);
    if (ret == -1) {
      cout << "impossible" << endl;
    } else {
      cout << ret << endl;
    }
  }
  return 0;
}
