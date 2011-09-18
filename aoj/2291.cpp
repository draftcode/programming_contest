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

vector<int> G[100000];
int dim[100000];
bool used[100000];

int main(void) {
  int N, M;
  cin >> N >> M;
  rep (i, M) {
    int X, Y;
    cin >> X >> Y;
    G[X-1].push_back(Y-1);
    G[Y-1].push_back(X-1);
  }

  priority_queue<P> que;
  rep (i, N) {
    que.push(P(G[i].size(), i));
    dim[i] = G[i].size();
  }
  
  int count1 = 0;
  ll count2 = 1;
  while (!que.empty()) {
    pair<int, int> p = que.top(); que.pop();
    int k = p.second;
    if (!used[k]) {
      used[k] = true;

      int same_dim_num = 0;
      each (it, G[k]) {
        if (!used[*it]) {
          if (dim[*it] == dim[k]) {
            same_dim_num++;
          }
        }
      }
      
      bool merginal_used = false;
      if (same_dim_num == dim[k]) {
        count1++;
        count2 *= same_dim_num + 1;
        merginal_used = true;
      }
      
      used[k] = true;
      each (it, G[k]) {
        if (!used[*it]) {
          used[*it] = merginal_used;
          dim[*it]--;
          que.push(P(dim[*it], *it));
        }
      }
    }
  }
  cout << count1 << endl;
  cout << count2 << endl;
  return 0;
}
