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
  ios::sync_with_stdio(false);
  int T; cin >> T;
  for (int t = 1; t <= T; t++) {
    int A, B; cin >> A >> B;
    int sz = 0, mul = 1;
    for (mul = 1; mul <= A; mul *= 10) sz++;

    int ans = 0;
    vector<int> v(B-A+1, -1);
    for (int i = A; i < B; i++) {
      if (v[i-A] != -1) continue;

      set<int> w;
      int j = 10;
      for (int k = 1; k < sz; k++, j *= 10) {
        if (i % j < j / 10) continue;
        int N = (i / j) + (i % j) * (mul / j);
        if (i < N && N <= B) {
          w.insert(N);
        }
      }

      int len = w.size();
      v[i-A] = 0;
      if (len > 0) {
        ans += len;
        for (set<int>::iterator it = w.begin(); it != w.end(); it++) {
          v[*it-A] = 0;
          ans += --len;
        }
      }
    }

    cout << "Case #" << t << ": " << ans << endl;
  }
  return 0;
}
