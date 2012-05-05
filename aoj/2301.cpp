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
// typedef pair<int, int> P;

#define rep(i,n) for(int i = 0; i < n; i++)
#define each(it,c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)

int K;
double R, L, P, E, T;

double calc(int K, double R, double L) {
  double H = (R + L)/2;
  if (K == 0) {
    if (fabs(T - H) <= E) {
      return 1.0;
    } else {
      return 0.0;
    }
  } else {
    if (fabs(T - H) <= E) {
      // Center is in right range.
      // If select right direction, then the whole range is in right range.
      if (T <= H) {
        return P + (1-P)*calc(K-1, H, L);
      } else {
        return P + (1-P)*calc(K-1, R, H);
      }
    } else {
      // Center is not in right range.
      // If select right direction, then there is a chant to acheive right
      // range.
      if (T <= H) {
        return P*calc(K-1, R, H);
      } else {
        return P*calc(K-1, H, L);
      }
    }
  }
}

double calc_2(int K, double R, double L) {
  double H = (R + L)/2;
  if (K == 0) {
    if (fabs(T - H) <= E) {
      return 1.0;
    } else {
      return 0.0;
    }
  } else {
    if (fabs(T - H) <= E) {
      if (T <= H) {
        return P*calc(K-1, R, H) + (1-P)*calc(K-1, H, L);
      } else {
        return (1-P)*calc(K-1, R, H) + P*calc(K-1, H, L);
      }
    } else {
      if (T <= H) {
        return P*calc_2(K-1, R, H);
      } else {
        return P*calc_2(K-1, H, L);
      }
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin >> K >> R >> L >> P >> E >> T;
  P = 1-P;
  
  double ans = calc_2(K, R, L);
  printf("%.8f\n", ans);
  
  return 0;
}
