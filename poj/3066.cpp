#include <algorithm>
#include <functional>
#include <iostream>
#include <limits>
#include <numeric>
#include <queue>
#include <sstream>
#include <vector>
#include <map>
#include <set>

#include <cctype>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;

int M, P, A, B;

bool check(double mid) {
  double minus_xp = pow(1.0/A, P/2);
  double plus_xp = pow((double)A, P/2);
  double left = sqrt(A) * B;
  int i;
  for (i = 0; i < M; i++) {
    if (left < 0) {
      if (left + 1.0/sqrt(A) > 0) {
        mid -= pow(left, P);
        break;
      } else {
        mid -= minus_xp;
        left += 1.0/sqrt(A);
      }
    } else {
      if (left - sqrt(A) < 0) {
        mid -= pow(left, P);
        break;
      } else {
        mid -= plus_xp;
        left -= sqrt(A);
      }
    }
  }

  while (i + A+1 < M) {
    mid -= plus_xp;
    mid -= A*minus_xp;
    i += A+1;
  }
  mid -= ((M-i)/2)*minus_xp;
  // if ((M-i) % 2 == 1) {
  //   if (left < 0) {
  //     mid += pow(left, P);
  //     mid -= minus_xp;
  //     mid -= pow(1.0/sqrt(A) + left, P);
  //   } else {
  //     mid += pow(left, P);
  //     mid -= plus_xp;
  //     mid -= pow(sqrt(A) - left, P);
  //   }
  // }

  return mid <= 0;
}

int main(void) {
  ios::sync_with_stdio(false);
  while (!cin.eof()) {
    cin >> M >> P >> A >> B;
    double upper = M*pow((double)A, P);
    double lower = 0;
    for (int i = 0; i < 100; i++) {
      double mid = (upper + lower)/2;
      if (check(mid)) {
        lower = mid;
      } else {
        upper = mid;
      }
    }
    cout << round(upper) << endl;
    cin.ignore(); cin.peek();
  }
  return 0;
}
