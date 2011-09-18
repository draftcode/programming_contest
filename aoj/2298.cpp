#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#include <numeric>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <climits>
#include <queue>
using namespace std;
typedef long long ll;

#define rep(i,n) for(int i = 0; i < n; i++)
#define each(it,c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define all(c) (c).begin(), (c).end()
#define zclear(v) memset(v, 0, sizeof(v))

int main(void) {
  int N, K, T, U, V, L;
  cin >> N >> K >> T >> U >> V >> L;
  queue<int> que;
  rep (i, N) {
    int d;
    cin >> d;
    que.push(d);
  }

  int max_hold = K;
  int hold = 0;
  int speed_up_to = -1;
  
  int speed_up_meters = 0;
  rep (i, L) {
    if (!que.empty() && que.front() == i) {
      hold++;
      que.pop();
    }
    
    if ((i >= speed_up_to && hold > 0) || hold > max_hold) {
      speed_up_to = i + V*T;
      hold--;
    }
    
    if (i < speed_up_to) {
      speed_up_meters++;
    }
  }
  
  double ans = ((double)speed_up_meters / V) + ((double)(L-speed_up_meters) / U);
  printf("%.9f\n", ans);
  return 0;
}
