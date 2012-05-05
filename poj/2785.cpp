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
int A[4000];
int B[4000];
int C[4000];
int D[4000];

int CD[16000000];

int main(void) {
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    scanf("%d%d%d%d", A+i, B+i, C+i, D+i);
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      CD[i*N+j] = C[i] + D[j];
    }
  }
  sort(CD, CD + N*N);

  ll ans = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      int cd = -(A[i]+B[j]);
      ans += upper_bound(CD, CD+N*N, cd) - lower_bound(CD, CD+N*N, cd);
    }
  }

  printf("%lld\n", ans);

  return 0;
}
