#include <algorithm>
#include <functional>
#include <iostream>
#include <limits>
#include <numeric>
#include <queue>
#include <vector>

#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

#define rep(i,n) for(int i = 0; i < n; i++)
#define each(it,c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)

int main(void) {
  ios::sync_with_stdio(false);
  int n;
  while (cin >> n) {
    int count = 0;
    rep (a, 10) {
      rep (b, 10) {
        rep (c, 10) {
          if (0 <= n-a-b-c && n-a-b-c <= 9) {
            count++;
          }
        }
      }
    }
    cout << count << endl;
  }
  return 0;
}
