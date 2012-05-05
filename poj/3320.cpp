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

int P;
int v[1000001];
set<int> all;

int main(void) {
  scanf("%d", &P);
  for (int i = 0; i < P; i++) {
    scanf("%d", v+i);
    all.insert(v[i]);
  }
  int allsize = all.size();

  int s = 0, t = 0, num = 0;
  map<int, int> count;
  int ans = P;
  for (;;) {
    while (t < P && num < allsize) {
      if (count[v[t++]]++ == 0) {
        num++;
      }
    }
    if (num < allsize) break;
    ans = min(ans, t-s);
    if (--count[v[s++]] == 0) {
      num--;
    }
  }

  printf("%d\n", ans);
  return 0;
}
