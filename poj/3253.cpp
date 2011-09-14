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


int main(void) {
  int N;
  cin >> N;
  priority_queue<int, vector<int>, greater<int> > q;
  rep (i, N) {
    int l;
    cin >> l;
    q.push(l);
  }
  ll cost = 0;
  while (q.size() > 1) {
    int l1, l2;
    l1 = q.top(); q.pop();
    l2 = q.top(); q.pop();
    q.push(l1+l2);
    cost += l1+l2;
  }
  cout << cost << endl;
  
  return 0;
}
