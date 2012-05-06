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

    double avr = double(sum * 2)/N;
    int sum_prev, sum_late = sum;
    double N_late;
    do {
      sum_prev = sum_late;
      sum_late = 0;
      N_late = 0;
      for (int i = 0; i < N; i++) {
        if (avr > v[i]) {
          sum_late += v[i];
          N_late++;
        }
      }
      avr = double(sum + sum_late) / N_late;
    } while (sum_prev != sum_late && sum_late != 0);

    if (sum_late == 0) {
      for (int i = 0; i < N; i++) {
        if (v[i] >= avr) {
          printf("%.8f ", 0.0);
        } else {
          printf("%.8f " , (double(100)/N_late));
        }
      }
    } else {
      for (int i = 0; i < N; i++) {
        if (v[i] >= avr) {
          printf("%.8f ", 0.0);
        } else {
          printf("%.8f " , max(0.0, (avr-double(v[i]))/sum*100));
        }
      }
    }

    cout << endl;
  }
  return 0;
}
