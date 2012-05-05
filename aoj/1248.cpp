#include <algorithm>
#include <functional>
#include <iostream>
#include <limits>
#include <numeric>
#include <queue>
#include <sstream>
#include <vector>

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

int main(void) {
  ios::sync_with_stdio(false);
  int a, b, g;
  for (;;) {
    cin >> a >> b >> g;
    if (a == b && b == g && g == 0) break;

    int count = 1;
    for (;;) {
      int weight = INT_MAX;
      int m_x = 0;
      for (int x = 0; x <= count; x++) {
        if (abs(a*x - b*(count-x)) == g
         || a*x + b*(count-x) == g
         ) {
          if (weight > a*x + b*(count-x)) {
            weight = a*x + b*(count-x);
            m_x = x;
          }
        }
      }
      if (weight != INT_MAX) {
        cout << m_x << ' ' << count - m_x << endl;
        break;
      }
      count++;
    }
  }
  return 0;
}
