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

int N;
int direction[5001];
int flipped[5001];

int calc(int K) {
  fill_n(flipped, 5001, false);
  int ans = 0;
  int sum = 0;
  for (int i = 0; i + K <= N; i++) {
    if ((direction[i] + sum) % 2 != 0) {
      ans++;
      flipped[i] = 1;
    }
    sum += flipped[i];
    if (i - K + 1 >= 0) {
      sum -= flipped[i - K + 1];
    }
  }

  for (int i = N - K + 1; i < N; i++) {
    if ((direction[i] + sum) % 2 != 0) {
      return -1;
    }
    if (i - K + 1 >= 0) {
      sum -= flipped[i - K + 1];
    }
  }
  return ans;
}

int main(void) {
  char s[2];

  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    scanf("%s", s);
    if (s[0] == 'F') {
      direction[i] = 0;
    } else {
      direction[i] = 1;
    }
  }

  int K = 1, M = N;
  for (int k = 1; k <= N; k++) {
    int m = calc(k);
    if (m >= 0 && M > m) {
      M = m;
      K = k;
    }
  }

  printf("%d %d\n", K, M);

  return 0;
}
