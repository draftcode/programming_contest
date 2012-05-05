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
  int nA, nB; cin >> nA >> nB;
  vector<int> vA(nA);
  vector<int> vB(nB);
  for (int i = 0; i < nA; i++) cin >> vA[i];
  for (int i = 0; i < nB; i++) cin >> vB[i];

  int ans = 0;
  for (int k = 0; k < nB; k++) {
    int i = k;
    int j = 0;
    while (i < nB && j < nA) {
      if (vB[i] == vA[j]) i++;
      j++;
    }

    ans = max(ans, i - k);
  }

  cout << ans << endl;
  return 0;
}
