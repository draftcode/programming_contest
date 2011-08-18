#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#include <numeric>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <climits>
using namespace std;
typedef long long ll;

#define rep(i,n) for(int i = 0; i < n; i++)
#define each(it,c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define all(c) (c).begin(), (c).end()
#define zclear(v) memset(v, 0, sizeof(v))

int N;
int x[200];
int y[200];

int main(void) {
  scanf("%d", &N);
  rep (i, N) scanf("%d%d", x+i, y+i);

  int mx = 0;
  rep (i, N) {
    for (int j = i + 1; j < N; j++) {
      int count = 0;
      int dx = x[j] - x[i];
      int dy = y[j] - y[i];
      rep (k, N) {
        // y*dx = dy*(x - x_i) + y_i*dx
        int left = y[k] * dx;
        int right = dy * (x[k] - x[i]) + y[i] * dx;
        if (left == right) count++;
      }
      mx = max(mx, count);
    }
  }
  printf("%d\n", mx);

  return 0;
}

