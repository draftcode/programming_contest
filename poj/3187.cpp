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

int n, sum;
int map[10];

int solve(void) {
  int temp[10];
  rep (i, n) temp[i] = map[i];
  for (int i = n; i > 1; i--) {
    for (int k = 0; k < i; k++) {
      temp[k] = temp[k] + temp[k+1];
    }
  }
  return temp[0];
}

int main(void) {
  scanf("%d%d", &n, &sum);
  rep (i, n) map[i] = i+1;
  do {
    if (solve() == sum) {
      rep (i, n) {
        if (i != 0) putchar(' ');
        printf("%d", map[i]);
      }
      putchar('\n');
      break;
    }
  } while (next_permutation(map, map+n));
  return 0;
}
