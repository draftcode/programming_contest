#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#include <numeric>
#include <cstring>
#include <stack>
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

vector<int> G[2000];
int dep[2000];

int main(void) {
  int n;
  cin >> n;
  
  vector<int> start;
  rep (i, n) {
    int manager;
    cin >> manager;
    if (manager != -1) {
      G[manager-1].push_back(i);
    } else {
      start.push_back(i);
    }
  }
  
  int ans = 0;
  fill(dep, dep+2000, 0);
  each (it, start) {
    stack<int> s;
    s.push(*it);
    
    while (!s.empty()) {
      int t = s.top(); s.pop();
      each (iit, G[t]) {
        s.push(*iit);
        dep[*iit] = dep[t] + 1;
      }
      ans = max(ans, dep[t] + 1);
    }
  }
  cout << ans << endl;
  
  return 0;
}
