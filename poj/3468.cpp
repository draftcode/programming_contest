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

int N, Q;
ll bit0[100001], bit1[100001];

ll sum(ll b[], int i) {
  ll s = 0;
  while (i > 0) {
    s += b[i];
    i -= i & -i;
  }
  return s;
}

void add(ll b[], int i, int v) {
  while (i <= N) {
    b[i] += v;
    i += i & -i;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  scanf("%d%d", &N, &Q);
  for (int i = 1; i <= N; i++) {
    int init;
    scanf("%d", &init);
    add(bit0, i, init);
  }

  for (int i = 0; i < Q; i++) {
    char q[2];
    scanf("%s", q);
    if (q[0] == 'Q') {
      int a, b;
      scanf("%d%d", &a, &b);
      ll res = 0;
      res += sum(bit0, b) + sum(bit1, b) * b;
      res -= sum(bit0, a-1) + sum(bit1, a-1) * (a-1);
      printf("%lld\n", res);
    } else {
      int a, b, x;
      scanf("%d%d%d", &a, &b, &x);
      add(bit0, a, -x*(a-1));
      add(bit1, a, x);
      add(bit0, b+1, x*b);
      add(bit1, b+1, -x);
    }
  }
  return 0;
}
