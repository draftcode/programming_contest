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

void main2(void) {
  int N;
  cin >> N;
  vector<int> vec(N);
  for (int i = 0; i < N-1; i++) {
    cin >> vec[i];
    vec[i]--;
  }
  vec[N-1] = N-1;

  for (int i = 0; i < N; i++) {
    // i .. vec[i]
    int h = height[vec[i]] - height[i];
    int n = vec[i] - i;
    for (int k = 0; k < n; k++) {
      height[i+k]
    }
  }

}

int main(void) {
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  for (int i = 1; i <= T; i++) {
    cout << "Case #" << i << ":";
    main2();
    cout << endl;
  }
  return 0;
}
