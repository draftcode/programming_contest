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
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    rep (k, 2*(n-i)-1) {
      cout << " ";
    }
    for (int k = 0; k <= i; k++) {
      cout << ' ' << k;
    }
    for (int k = i-1; k >= 0; k--) {
      cout << ' ' << k;
    }
    cout << endl;
  }

  cout << 0;
  for (int k = 1; k <= n; k++) {
    cout << ' ' << k;
  }
  for (int k = n-1; k >= 0; k--) {
    cout << ' ' << k;
  }
  cout << endl;

  for (int i = n-1; i >= 0; i--) {
    rep (k, 2*(n-i)-1) {
      cout << " ";
    }
    for (int k = 0; k <= i; k++) {
      cout << ' ' << k;
    }
    for (int k = i-1; k >= 0; k--) {
      cout << ' ' << k;
    }
    cout << endl;
  }
  return 0;
}
