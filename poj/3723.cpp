#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#include <numeric>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <climits>
using namespace std;
typedef long long ll;

#define rep(i,n) for(int i = 0; i < n; i++)
#define each(it,c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define all(c) (c).begin(), (c).end()
#define zclear(v) memset(v, 0, sizeof(v))

class unionfind {
  vector<int> par;
  vector<int> rank;
  
  int find(int x) {
    if (par[x] == x) {
      return x;
    } else {
      return par[x] = find(par[x]);
    }
  }
  
public:
  unionfind(int n) : par(n), rank(n, 0) {
    rep (i, n) {
      par[i] = i;
    }
  }
  
  void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    
    if (rank[x] < rank[y]) {
      par[x] = y;
    } else {
      par[y] = x;
      if (rank[x] == rank[y]) rank[x]++;
    }
  }
  
  bool same(int x, int y) {
    return find(x) == find(y);
  }
};

struct edge {
  int x, y, d;
  
  bool operator <(const edge &rhs) const {
    return this->d < rhs.d;
  }
};

int main(void) {
  int cases;
  scanf("%d", &cases);
  
  rep (_i, cases) {
    int N, M, R;
    vector<edge> edges;
    
    scanf("%d%d%d", &N, &M, &R);
    rep (i, R) {
      int x, y, d;
      scanf("%d%d%d", &x, &y, &d);
      edges.push_back((edge){x, y+N, -d});
    }
    
    sort(edges.begin(), edges.end());
    unionfind uf(N+M);
    int cost = 0;
    each (it, edges) {
      if (!uf.same(it->x, it->y)) {
        uf.unite(it->x, it->y);
        cost += it->d;
      }
    }
    printf("%d\n", 10000*(N+M) + cost);
  }

  return 0;
}
