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

typedef int Weight;
struct Edge {
  int src, dst;
  int cost, capacity;
  Edge(int src, int dst, int capacity, int cost) : src(src), dst(dst), cost(cost), capacity(capacity) {}
};
bool operator < (const Edge &e, const Edge &f) {
    return e.cost != f.cost ? e.cost > f.cost : // !!INVERSE!!
          e.dst != f.dst ? e.dst < f.dst : e.src < f.src;
}
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

typedef vector<Weight> Array;
typedef vector<Array> Matrix;

#define RESIDUE(u,v) (capacity[u][v] - flow[u][v])
#define RCOST(u,v) (cost[u][v] + h[u] - h[v])
pair<Weight, Weight> minimumCostFlow(const Graph &g, int s, int t) {
  const int n = g.size();
  Matrix capacity(n, Array(n)), cost(n, Array(n)), flow(n, Array(n));
  for(int u = 0; u < n; ++u)
    for(Edges::const_iterator e = g[u].begin(); e != g[u].end(); e++) {
      capacity[e->src][e->dst] += e->capacity;
      cost[e->src][e->dst] += e->cost;
    }
  pair<Weight, Weight> total; // (cost, flow)
  vector<Weight> h(n);

  for (Weight F = 100000; F > 0; ) { // residual flow
    vector<Weight> d(n, 100000); d[s] = 0;
    vector<int> p(n, -1);

    priority_queue<Edge> Q; // "e < f" <=> "e.cost > f.cost"
    for (Q.push(Edge(-2, s, 100000, 0)); !Q.empty(); ) {
      Edge e = Q.top(); Q.pop();
      if (p[e.dst] != -1) continue;
      p[e.dst] = e.src;
      for(Edges::const_iterator f = g[e.dst].begin(); f != g[e.dst].end(); f++) {
        if (RESIDUE(f->src, f->dst) > 0) {
          if (d[f->dst] > d[f->src] + RCOST(f->src, f->dst)) {
            d[f->dst] = d[f->src] + RCOST(f->src, f->dst);
            Q.push( Edge(f->src, f->dst, 0, d[f->dst]) );
          }
        }
      }
    }
    if (p[t] == -1) break;

    Weight f = F;
    for (int u = t; u != s; u = p[u])
      f = min(f, RESIDUE(p[u], u));
    for (int u = t; u != s; u = p[u]) {
      total.first += f * cost[p[u]][u];
      flow[p[u]][u] += f; flow[u][p[u]] -= f;
    }
    F -= f;
    total.second += f;
    for(int u = 0; u < n; u++) h[u] += d[u];
  }
  return total;
}

int main(void) {
  ios::sync_with_stdio(false);
  int T; cin >> T;
  for (int _ = 0; _ < T; _++) {
    int N, K; cin >> N >> K;
    vector<int> cost(2*N*(N+1), 1);
    for (int i = 0; i < K; i++) {
      int t = 0; cin >> t;
      cost[t-1] = 0;
    }

    Graph g;
    g.push_back(Edges());
    g.push_back(Edges());
    for (int i = 1; i <= 2*N*(N+1); i++) {
      Edges point;
      point.push_back(Edge(i+1, 0, 100000, cost[i-1]));
      g[0].push_back(Edge(0, i+1, 0, -cost[i-1]));
      g.push_back(point);
    }

    int cubes = 0;
    for (int n = 1; n <= N; n++) {
      for (int y = 1; y <= N-n+1; y++) {
        for (int x = 1; x <= N-n+1; x++) {
          Edges point;
          int idx = g.size();
          int top = (2*N+1)*(y-1)+x;
          int bottom = (2*N+1)*(y+n-1)+x;
          int left = top + N;
          for (int t = 0; t < n; t++) {
            point.push_back(Edge(idx, 1+top+t, 1000, 0));
            point.push_back(Edge(idx, 1+bottom+t, 1000, 0));
            point.push_back(Edge(idx, 1+left+t*(2*N+1), 1000, 0));
            point.push_back(Edge(idx, 1+left+t*(2*N+1)+n, 1000, 0));
            g[1+top+t].push_back(Edge(1+top+t, idx, 0, 0));
            g[1+bottom+t].push_back(Edge(1+bottom+t, idx, 0, 0));
            g[1+left+t*(2*N+1)].push_back(Edge(1+left+t*(2*N+1), idx, 0, 0));
            g[1+left+t*(2*N+1)+n].push_back(Edge(1+left+t*(2*N+1)+n, idx, 0, 0));
          }
          point.push_back(Edge(idx, 1, 0, 0));
          g.push_back(point);
          g[1].push_back(Edge(1, idx, 1, 0));
          cubes++;
        }
      }
    }

    P p = minimumCostFlow(g, 1, 0);
    cout << p.first << ' ' << p.second << endl;
  }
  return 0;
}
