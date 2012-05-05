#include <algorithm>
#include <functional>
#include <iostream>
#include <limits>
#include <numeric>
#include <queue>
#include <sstream>
#include <map>
#include <vector>

#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

#define rep(i,n) for(int i = 0; i < n; i++)
#define each(it,c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)

struct UnionFind {
  vector<int> data;
  UnionFind(int size) : data(size, -1) { }
  bool unionSet(int x, int y) {
    x = root(x); y = root(y);
    if (x != y) {
      if (data[y] < data[x]) swap(x, y);
      data[x] += data[y]; data[y] = x;
    }
    return x != y;
  }
  bool findSet(int x, int y) {
    return root(x) == root(y);
  }
  int root(int x) {
    return data[x] < 0 ? x : data[x] = root(data[x]);
  }
  int size(int x) {
    return -data[root(x)];
  }
};

struct edge {
  int a, b;
  double len;
  bool operator <(const edge &rhs) const {
    return len > rhs.len;
  }
};

int main(void) {
  ios::sync_with_stdio(false);
  double length;
  cin >> length;

  map<string, int> m;
  
  int houses;
  cin >> houses;
  rep (i, houses) {
    string s;
    cin >> s;
    m[s] = i;
  }

  priority_queue<edge> que;
  int connections;
  cin >> connections;
  rep (i, connections) {
    string a, b;
    double len;
    cin >> a >> b >> len;
    que.push((edge){m[a],m[b],len});
  }

  double ans = 0.0;
  UnionFind uf(houses);
  while (!que.empty()) {
    edge e = que.top(); que.pop();
    if (uf.findSet(e.a, e.b)) continue;
    ans += e.len;
    uf.unionSet(e.a, e.b);
  }
  
  if (ans <= length) {
    printf("Need %.1f miles of cable\n", ans);
  } else {
    printf("Not enough cable\n");
  }

  return 0;
}
