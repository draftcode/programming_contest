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

int cases, N;
char supervisors_pref[15][15];
char employees_pref[15][15];

int main(void) {
  ios::sync_with_stdio(false);
  cin >> cases;

  for (int _ = 0; _ < cases; _++) {
    cin >> N;
    for (int i = 0; i < N; i++)
      for (int j = 0; j < N; j++)
        cin >> supervisors_pref[i][j];
    for (int i = 0; i < N; i++)
      for (int j = 0; j < N; j++)
        cin >> employees_pref[i][j];

  }
  return 0;
}
