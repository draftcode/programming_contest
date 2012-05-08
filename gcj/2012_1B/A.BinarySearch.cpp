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
typedef pair<int, int> P;

int main(void) {
  int T;
  cin >> T;
  for (int ncase = 1; ncase <= T; ncase++) {
    cout << "Case #" << ncase << ": ";

    int N; cin >> N;
    int sum = 0;
    vector<int> v(N);
    for (int i = 0; i < N; i++) {
      cin >> v[i];
      sum += v[i];
    }

    for (int i = 0; i < N; i++) {
      double hi = 1.0, lo = 0.0;
      for (int k = 0; k < 300; k++) {
        double mid = (hi + lo)/2;
        double pt = v[i] + sum * mid;

        double diff = 0;
        for (int j = 0; j < N; j++) {
          if (i != j && v[j] < pt) {
            diff += (pt - double(v[j]))/sum;
          }
        }

        if (diff > 1 - mid) {
          hi = mid;
        } else {
          lo = mid;
        }
      }

      printf("%.8f " ,(hi + lo) / 2 * 100);
    }

    cout << endl;
  }
  return 0;
}
