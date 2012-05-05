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

int gcd(int a, int b) {
  if (b < a) swap(a, b);
  for (;;) {
    if (a == 0) return b;
    b %= a;
    swap(b, a);
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  // int n, k, m, r;
  // for (;;) {
  //   cin >> n >> k >> m >> r;
  //   if (n == 0) break;
    
  //   int P_denom = 1, P_numer = 1;
  //   rep (i, k) {
  //     P_numer *= n*k - k;
  //     P_denom *= n*k - i;
      
  //     int P_gcd = gcd(P_denom, P_numer);
  //     P_denom /= P_gcd;
  //     P_numer /= P_gcd;
  //   }
    
  //   if (m == 1) {
  //     P_numer = 2*P_denom*P_numer - P_numer*P_numer;
  //     P_denom = P_denom*P_denom;
  //     int P_gcd = gcd(P_denom, P_numer);
  //     P_denom /= P_gcd;
  //     P_numer /= P_gcd;
  //   }
    
  //   cout << (double)P_numer/P_denom << endl;
  // }
  return 0;
}
