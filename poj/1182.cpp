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

int main(void) {
  int N, K;
  scanf("%d%d", &N, &K);
  UnionFind uf(3*N);
  
  int ans = 0;
  rep (i, K) {
    int type, x, y;
    scanf("%d%d%d", &type, &x, &y);
    x--; y--;
    if (x >= N || y >= N || x < 0 || y < 0) {
      ans++;
    } else if (type == 1) {
      if (uf.findSet(x, y+N) || \
          uf.findSet(x, y+N*2) || \
          uf.findSet(x+N, y) || \
          uf.findSet(x+N, y+N*2) || \
          uf.findSet(x+N*2, y) || \
          uf.findSet(x+N*2, y+N))
      {
        ans++;
      } else {
        uf.unionSet(x, y);
        uf.unionSet(x+N, y+N);
        uf.unionSet(x+N*2, y+N*2);
      }
    } else {
      if (uf.findSet(x, y) || \
          uf.findSet(x, y+N*2) || \
          uf.findSet(x+N, y) || \
          uf.findSet(x+N, y+N) || \
          uf.findSet(x+N*2, y+N) || \
          uf.findSet(x+N*2, y+N*2))
      {
        ans++;
      } else {
        uf.unionSet(x, y+N);
        uf.unionSet(x+N, y+N*2);
        uf.unionSet(x+N*2, y);
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}
