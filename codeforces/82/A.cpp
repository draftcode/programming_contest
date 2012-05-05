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
  int k = 5;
  while (n > k) {
    n -= k;
    k *= 2;
  }

  int l = k / 5;
  if (n <= l) {
    cout << "Sheldon" << endl;
  } else if (n <= 2*l) {
    cout << "Leonard" << endl;
  } else if (n <= 3*l) {
    cout << "Penny" << endl;
  } else if (n <= 4*l) {
    cout << "Rajesh" << endl;
  } else {
    cout << "Howard" << endl;
  }
  return 0;
}
