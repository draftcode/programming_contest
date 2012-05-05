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
  ll a, b, mod;
  cin >> a >> b >> mod;
  if (b > mod) {
    cout << "2" << endl;
    return 0;
  }

  ll z = 1000000000 % mod;
  ll prev = 0;
  for (int i = 1; i < a+1; i++) {
    if (((prev+z) % mod) + b < mod) {
      printf("1 %09d\n", i);
      return 0;
    }
    prev = (prev+z) % mod;
  }
  cout << "2" << endl;
  return 0;
}
