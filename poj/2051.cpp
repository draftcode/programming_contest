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
typedef pair<int, int> ip;

#define rep(i,n) for(int i = 0; i < n; i++)
#define each(it,c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define all(c) (c).begin(), (c).end()
#define zclear(v) memset(v, 0, sizeof(v))

int main(void) {
  priority_queue<ip, vector<ip>, greater<ip> > que;
  for (;;) {
    char str[1024];
    scanf("%s", str);
    if (str[0] == '#') break;
    int id, period;
    scanf("%d%d", &id, &period);
    for (int i = 1; period*i <= 10000; i++) {
      que.push(make_pair(period*i, id));
    }
  }
  int n;
  scanf("%d", &n);
  rep (i, n) {
    ip p = que.top(); que.pop();
    printf("%d\n", p.second);
  }
  return 0;
}
