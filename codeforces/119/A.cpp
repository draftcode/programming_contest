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

int gcd(int m, int n) {
  if (m < n) swap(m,n);
  if (n == 0) return m;
  for (;;) {
    if (m % n == 0) return n;
    int t;
    t = m % n;
    m = n;
    n = t;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  int a, b, n;
  cin >> a >> b >> n;
  int heap = n;
  bool turn = true;

  for (;;) {
    int g;
    if (turn) {
      g = gcd(heap, a);
      if (g > heap) {
        cout << "1" << endl;
        return 0;
      } else {
        heap -= g;
      }
    } else {
      g = gcd(heap, b);
      if (g > heap) {
        cout << "0" << endl;
        return 0;
      } else {
        heap -= g;
      }
    }
    turn = !turn;
  }
  return 0;
}

