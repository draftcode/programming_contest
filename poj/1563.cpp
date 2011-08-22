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

int H, U, D, F;
bool success;

int trying(void) {
  double decreasing = U * (double(F) / 100.0);
  double current = 0.0;
  double uprate = U;
  double downrate = D;

  int day = 1;
  while (1) {
    if (uprate > 0.0) {
      current += uprate;
    }
    if (current > double(H)) {
      success = true;
      break;
    }
    
    current -= downrate;
    if (current < 0.0) {
      success = false;
      break;
    }

    day++;
    uprate -= decreasing;
  }
  return day;
}

int main(void) {
  for (;;) {
    cin >> H >> U >> D >> F;
    if (H == 0) break;
    int day = trying();
    if (success) {
      cout << "success on day " << day << endl;
    } else {
      cout << "failure on day " << day << endl;
    }
  }
  return 0;
}
