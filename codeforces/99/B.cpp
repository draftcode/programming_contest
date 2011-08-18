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

int n;
int cups[1000];

int main(void) {
  scanf("%d", &n);
  rep (i, n) scanf("%d", cups+i);

  int ave = accumulate(cups, cups+n, 0)/n;

  int over = INT_MAX, under = INT_MAX;

  rep (i, n) {
    if (cups[i] > ave) {
      if (over == INT_MAX) {
        over = i;
      } else {
        printf("Unrecoverable configuration.\n");
        return 0;
      }
    } else if (cups[i] < ave) {
      if (under == INT_MAX) {
        under = i;
      } else {
        printf("Unrecoverable configuration.\n");
        return 0;
      }
    }
  }

  if (over == under) {
    printf("Exemplary pages.\n");
  } else if (over == INT_MAX || under == INT_MAX) {
    printf("Unrecoverable configuration.\n");
  } else {
    if (cups[over] - ave == ave - cups[under]) {
      printf("%d ml. from cup #%d to cup #%d.\n", cups[over]-ave, under+1, over+1);
    } else {
      printf("Unrecoverable configuration.\n");
    }
  }

  return 0;
}
