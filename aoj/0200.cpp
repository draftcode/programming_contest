#include <algorithm>
#include <functional>
#include <climits>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int calc(int from, int to, vector<P> map[]) {
  priority_queue<P, vector<P>, greater<P> > que;
  que.push(P(0, from));
  vector<int> visited(100, INT_MAX);

  while (!que.empty()) {
    P p = que.top(); que.pop();
    if (p.second == to) return p.first;
    if (visited[p.second] < p.first) continue;
    visited[p.second] = p.first;

    for (vector<P>::const_iterator it = map[p.second].begin(); it != map[p.second].end(); it++) {
      int next = it->second;
      int nextcost = it->first + p.first;

      if (nextcost < visited[next]) {
        que.push(P(nextcost, next));
      }
    }
  }

  return INT_MAX;
}

vector<P> costs[100];
vector<P> times[100];

int main(void) {
  ios::sync_with_stdio(false);
  int N, M, K;
  for (;;) {
    cin >> N >> M;
    if (N == 0 && M == 0) break;
    for (int i = 0; i < M; i++) {
      costs[i].clear();
      times[i].clear();
    }
    for (int i = 0; i < N; i++) {
      int a, b, c, t;
      cin >> a >> b >> c >> t;
      costs[a-1].push_back(P(c, b-1));
      costs[b-1].push_back(P(c, a-1));
      times[a-1].push_back(P(t, b-1));
      times[b-1].push_back(P(t, a-1));
    }
    cin >> K;
    for (int i = 0; i < K; i++) {
      int from, to, istime;
      cin >> from >> to >> istime;
      if (istime) {
        cout << calc(from - 1, to - 1, times) << endl;
      } else {
        cout << calc(from - 1, to - 1, costs) << endl;
      }
    }
  }
  return 0;
}
