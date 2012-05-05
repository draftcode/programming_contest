#include <algorithm>
#include <functional>
#include <iostream>
#include <limits>
#include <numeric>
#include <queue>
#include <sstream>
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
  int curr = 10;
  int total; cin >> total;

  int diff = total - curr;

  int ans;
  if (1 <= diff && diff <= 9) {
    ans = 4;
  } else if (diff == 10) {
    ans = 15;
  } else if (diff == 11) {
    ans = 4;
  } else {
    ans = 0;
  }
  cout << ans << endl;
  return 0;
}
