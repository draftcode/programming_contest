#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#include <set>
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

int f, r;
int front[10];
int rear[10];
double ratios[100];

int main(void) {
  while (scanf("%d%d", &f, &r) == 2) {
    rep (i, f) scanf("%d", front+i);
    rep (i, r) scanf("%d", rear+i);

    int count = 0;
    rep (i, f) {
      rep (j, r) {
        ratios[count++] = front[i]*1.0/rear[j];
      }
    }

    double mx = 0.0;
    sort(ratios, ratios+count);
    for (int i = 0; i < count-1; i++) {
      mx = max(mx, ratios[i+1]/ratios[i]);
    }
    printf("%.2f\n", mx);
  }
  return 0;
}
