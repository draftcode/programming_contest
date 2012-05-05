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
  cin >> n;
  int yen = 100000;
  rep (i, n) {
    int interest = yen * 0.05;
    if (interest % 1000 != 0) {
      interest = (interest / 1000 + 1) * 1000;
    }
    yen += interest;
  }
  cout << yen << endl;
  return 0;
}
