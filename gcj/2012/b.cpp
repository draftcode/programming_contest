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

bool normal[31];
bool surprising[31];
int mx1[31];
int mx2[31];

int main(void) {
  ios::sync_with_stdio(false);

  for (int i = 0; i <= 10; i++) {
    for (int j = 0; j <= 2 && i+j <= 10; j++) {
      for (int k = 0; k <= 2 && i+k <= 10; k++) {
        if (j == 2 || k == 2) {
          surprising[3*i+j+k] = true;
          mx2[3*i+j+k] = max(mx2[3*i+j+k], max(i+j, i+k));
        } else {
          normal[3*i+j+k] = true;
          mx1[3*i+j+k] = max(mx1[3*i+j+k], max(i+j, i+k));
        }
      }
    }
  }

  int T; cin >> T;
  for (int t = 1; t <= T; t++) {
    int N, S, P; cin >> N >> S >> P;
    vector<int> v(N);
    for (int i = 0; i < N; i++) cin >> v[i];

    int ans = 0;
    int sup = 0;
    for (int i = 0; i < N; i++) {
      if (normal[v[i]] && mx1[v[i]] >= P) {
        ans++;
      } else if (surprising[v[i]] && mx2[v[i]] >= P) {
        ans++;
        sup++;
      }
    }

    if (sup > S) {
      for (int i = 0; i < N && sup > S; i++) {
        if (surprising[v[i]] && mx2[v[i]] >= P) {
          if (normal[v[i]] && mx1[v[i]] < P) {
            ans--;
            sup--;
          }
        }
      }
    } else {
      for (int i = 0; i < N && sup < S; i++) {
        if (surprising[v[i]] && mx2[v[i]] < P) {
          sup++;
        }
      }
    }

    cout << "Case #" << t << ": " << ans << endl;
  }
  return 0;
}
