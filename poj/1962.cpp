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

struct UnionFindLike {
  vector<int> data;
  vector<int> len;
  UnionFindLike(int size) : data(size, -1), len(size, 0) { }
  void unionSet(int x, int y) {
    data[x] = y;
    len[x] = abs(y - x) % 1000;
  }

  int length(int x) {
    if (data[x] == -1) return 0;
    int root = data[x];
    int ln = len[x];
    while (data[root] != -1) {
      ln += len[root];
      root = data[root];
    }
    data[x] = root;
    len[x] = ln;
    return ln;
  }
};

void solve(void) {
  int N; cin >> N;
  UnionFindLike uf(N+1);
  string s;

  while (cin >> s && s != "O") {
    if (s == "I") {
      int I, J;
      cin >> I >> J;
      uf.unionSet(I, J);
    } else {
      int I;
      cin >> I;
      cout << uf.length(I) << endl;
    }
  }
}

int main(void) {
  int T; cin >> T;
  for (int i = 0; i < T; i++) {
    solve();
  }
  return 0;
}
