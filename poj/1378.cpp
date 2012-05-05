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

#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

#define rep(i,n) for(int i = 0; i < n; i++)
#define each(it,c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)

int N, M, K;
vector<int> cables[50];

int main(void) {
  ios::sync_with_stdio(false);
  for (;;) {
    cin >> N >> M >> K;

    map<int, vector<int> > connected_cables; // key: building
    for (int m = 0; m < M; m++) {
      int L;
      cin >> L;
      cables[m] = vector<int>(L);
      for (int l = 0; l < L; l++) {
        cin >> cables[m][l];
        connected_cables[cables[m][l]].push_back(m);
      }
    }

    for (int k = 0; k < K; k++) {
      int flooded_building;
      cin >> flooded_building;

      vector<int> &v = connected_cables[flooded_building];
      for (int i = 0; i < v.size(); i++) {
        cables[v[i]].clear();
      }
    }

    set<int> alive;
    for (int m = 0; m < M; m++) {
      for (int i = 0; i < cables[m].size(); i++) {
        alive.insert(cables[m][i]);
      }
    }

    cout << N - alive.size() << endl;

    cin >> N >> M >> K;
    if (N == M && M == K && K == -1) break;
  }
  return 0;
}
