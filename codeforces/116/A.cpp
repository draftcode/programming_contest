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
  int current = 0;
  int ans = 0;
  rep (i, N) {
    int out, in;
    cin >> out >> in;
    current -= out;
    current += in;
    ans = max(current, ans);
  }
  cout << ans << endl;
  return 0;
}
