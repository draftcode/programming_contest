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
  vector<int> v;
  for (;;) {
    int count;
    cin >> count;
    if (count == 0) break;
    rep (i, count) {
      int t;
      cin >> t;
      v.push_back(t);
    }
    sort(v.begin(), v.end());
    cout << "no solution" << endl;
  }
  return 0;
}
