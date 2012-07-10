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

int v[50001];
int ans[50001];
int dir[50001];

int main(void) {
  ios::sync_with_stdio(false);
  int N;
  scanf("%d", &N);
  for (int i = 1; i <= N; i++) { v[i] = i; }
  for (int I = N; I > 1; I--) {
    ans[v[1]] = I;
    swap(v[1], v[I]);

    int curr = I-1;
    int dircount = 0;
    while (curr > 0) {
      dir[dircount++] = curr % 2;
      curr /= 2;
    }

    curr = 0;
    for (int i = dircount-1; i >= 0; i--) {
      swap(v[curr], v[curr * 2 + dir[i]]);
      curr = curr * 2 + dir[i];
    }
  }
  ans[N] = 1;

  for (int i = 1; i <= N; i++) {
    printf("%d", ans[i]);
    if (i != N) putchar(' '); else putchar('\n');
  }
  return 0;
}
