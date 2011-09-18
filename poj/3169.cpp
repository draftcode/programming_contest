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
typedef pair<int, int> P;

#define rep(i,n) for(int i = 0; i < n; i++)
#define each(it,c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define all(c) (c).begin(), (c).end()
#define zclear(v) memset(v, 0, sizeof(v))

vector<P> G[1000]

int main(void) {
  ios::sync_with_stdio(false);
  int N, ML, MD;
  cin >> N >> ML >> MD;
  rep (i, N-1) {
    G[i+1].push_back(P(i, 0));
  }

  rep (i, ML) {
    int A, B, D;
    cin >> A >> B >> D;
  }
  return 0;
}
