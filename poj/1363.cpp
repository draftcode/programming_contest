#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
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
#define zerase(v) memset(v, 0, sizeof(v))

int n;
int t[1000];

bool solve(void) {
  int waiting = 1;
  stack<int> expect;
  rep (i, n) {
    while (waiting <= t[i]) expect.push(waiting++);
    if (expect.size() > 0) {
      int e = expect.top(); expect.pop();
      if (e != t[i]) return false;
    }
  }

  return true;
}

int main(void) {
  while (scanf("%d", &n), n) {
    while (scanf("%d", t), t[0]) {
      rep (i, n-1) scanf("%d", t+i+1);
      if (solve()) printf("Yes\n"); else printf("No\n");
    }
    putchar('\n');
  }
  return 0;
}
