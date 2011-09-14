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

struct route {
  int x;
  int y;
  int needed;
  
  route(int x, int y, int n) : x(x), y(y), needed(n) {
    if (x < y) swap(x, y);
  }
  
  bool operator <(const route& rhs) {
    if (needed == rhs.needed) {
      if (x == rhs.x) {
        return y < rhs.y;
      } else {
        return x < rhs.x;
      }
    } else {
      return needed < rhs.needed;
    }
  }
};

int main(void) {
  int N;
  cin >> N;
  rep (c, N) {
    int cities;
    cin >> cities;
    
    rep (i, cities) {
      int k;
      cin >> k;
    }
  }
  return 0;
}
