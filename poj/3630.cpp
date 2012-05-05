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

char st[10000][11];
char *v[10000];

bool cmp(char *a, char *b) {
  return strcmp(a, b) < 0;
}

int main(void) {
  int T; scanf("%d", &T);
  for (int _ = 0; _ < T; _++) {
    int N; scanf("%d", &N);
    for (int n = 0; n < N; n++) {
      scanf("%s", st[n]);
      v[n] = st[n];
    }
    sort(v, v+N, cmp);

    bool ans = true;
    for (int n = 1; n < N && ans; n++) {
      if (strncmp(v[n-1], v[n], strlen(v[n-1])) == 0) {
        ans = false;
      }
    }

    if (ans) {
      printf("YES\n");
    } else {
      printf("NO\n");
    }
  }
  return 0;
}
