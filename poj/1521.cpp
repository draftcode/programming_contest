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

int main(void) {
  ios::sync_with_stdio(false);
  for (;;) {
    string s; getline(cin, s);
    if (s == "END") break;

    int count[27];
    memset(count, 0, sizeof(count));
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '_') {
        count[26]++;
      } else {
        count[s[i] - 'A']++;
      }
    }

    priority_queue<P, vector<P>, greater<P> > que;
    for (int i = 0; i < 27; i++) {
      if (count[i] != 0) {
        que.push(P(count[i], 1 << i));
      }
    }

    int ans1 = s.size() * 8, ans2 = 0;
    if (que.size() != 1) {
      int size[27];
      memset(size, 0, sizeof(size));
      while (que.size() != 1) {
        P p = que.top(); que.pop();
        P q = que.top(); que.pop();
        for (int i = 0; i < 27; i++) {
          if (p.second & (1 << i)) {
            size[i]++;
          }
          if (q.second & (1 << i)) {
            size[i]++;
          }
        }
        que.push(P(p.first + q.first, p.second | q.second));
      }

      for (int i = 0; i < s.size(); i++) {
        if (s[i] == '_') {
          ans2 += size[26];
        } else {
          ans2 += size[s[i] - 'A'];
        }
      }
    } else {
      ans2 = s.size();
    }

    printf("%d %d %.1f\n", ans1, ans2, double(ans1)/double(ans2));
  }
  return 0;
}
