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

const int DAT_SIZE = (1 << 18) - 1;

ll data[DAT_SIZE], datb[DAT_SIZE];

void add(int a, int b, int x, int k, int l, int r) {
  if (a <= l && r <= b) {
    data[k] += x;
  } else if (l < b && a < r) {
    datb[k] += (min(b, r) - max(a, l)) * x;
    add(a, b, x, k*2+1, l, (l+r)/2);
    add(a, b, x, k*2+2, (l+r)/2, r);
  }
}

ll sum(int a, int b, int k, int l, int r) {
  if (b <= l || r <= a) {
    return 0;
  } else if (a <= l && r <= b) {
    return data[k]*(r-l) + datb[k];
  } else {
    ll res = (min(b, r) - max(a, l)) * data[k];
    res += sum(a, b, k*2+1, l, (l+r)/2);
    res += sum(a, b, k*2+2, (l+r)/2, r);
    return res;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  int N, Q;
  cin >> N >> Q;
  for (int i = 0; i < N; i++) {
    int init;
    cin >> init;
    add(i, i+1, init, 0, 0, N);
  }

  for (int i = 0; i < Q; i++) {
    char q[2];
    cin >> q;
    if (q[0] == 'Q') {
      int a, b;
      cin >> a >> b;
      cout << sum(a-1, b, 0, 0, N) << endl;
    } else {
      int a, b, x;
      cin >> a >> b >> x;
      add(a-1, b, x, 0, 0, N);
    }
  }
  return 0;
}
