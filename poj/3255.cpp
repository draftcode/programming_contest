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

struct edge {
  int A, B, distance;
  edge(int A, int B, int distance) : A(A), B(B), distance(distance) {}
};
vector<edge> G[5000];
int first[5000];
int second[5000];

int main(void) {
  int N, R;
  cin >> N >> R;

  rep (i, R) {
    int A, B, D;
    cin >> A >> B >> D;
    G[A - 1].push_back(edge(A - 1, B - 1, D));
    G[B - 1].push_back(edge(B - 1, A - 1, D));
  }
  
  rep (i, N) {
    first[i] = second[i] = INT_MAX;
  }
  first[0] = 0;
  
  priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > que;
  que.push(make_pair(0, 0));
  while (!que.empty()) {
    pair<int, int> p = que.top(); que.pop();
    if (second[p.second] < p.first) continue;
    
    each(it, G[p.second]) {
      int cost = p.first + it->distance;
      if (first[it->B] > cost) {
        swap(first[it->B], cost);
        que.push(make_pair(first[it->B], it->B));
      }
      if (first[it->B] < cost && second[it->B] > cost) {
        second[it->B] = cost;
        que.push(make_pair(second[it->B], it->B));
      }
    }
  }
  cout << second[N-1] << endl;
  return 0;
}
