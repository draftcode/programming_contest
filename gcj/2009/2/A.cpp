#include <algorithm>
#include <functional>
#include <iostream>
#include <limits>
#include <numeric>
#include <queue>
#include <sstream>
#include <vector>

#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

#define rep(i,n) for(int i = 0; i < n; i++)
#define each(it,c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)

int main(void) {
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    int N;
    cin >> N;
    vector<int> v;
    for (int i = 0; i < N; i++) {
      string s;
      cin >> s;
      int k;
      for (k = N-1; k >= 0; k--) {
        if (s[k] == '1') {
          break;
        }
      }
      v.push_back(k+1);
    }

    int ans = 0;

    for (int i = 0; i < N; i++) {
      int sw = -1;
      for (int k = i; k < N; k++) {
        if (v[k] <= i+1) {
          sw = k;
          break;
        }
      }

      for (int k = sw; k > i; k--) {
        swap(v[k], v[k-1]);
        ans++;
      }
    }

    cout << "Case #" << t << ": " << ans << endl;
  }
  return 0;
}
