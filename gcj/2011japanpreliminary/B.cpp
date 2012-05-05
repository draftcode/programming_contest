#include <algorithm>
#include <functional>
#include <iostream>
#include <limits>
#include <numeric>
#include <queue>
#include <sstream>
#include <vector>
#include <list>

#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

#define rep(i,n) for(int i = 0; i < n; i++)
#define each(it,c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)

class Range {
  list<P> v;
public:
  Range(P first) : v() {
    v.push_back(first);
  }

  int fill(int endday, int count) {
    int ret = 0;

    if (v.empty()) return ret;
    if (v.front().first > endday) return ret;

    list<P>::iterator begin = v.begin();
    while (begin != v.end() && begin->second < endday) {
      begin++;
    }
    if (begin == v.end() || endday < begin->first) {
      begin--;
      endday = begin->second;
    }

    while (begin != (--v.begin())) {
      if (endday - begin->first + 1 >= count) {
        ret += count;

        int next_begin_second = endday - count;
        if (next_begin_second >= begin->first) {
          v.insert(begin, P(begin->first, next_begin_second));
        }
        if (endday == begin->second) {
          v.erase(begin);
        } else {
          begin->first = endday+1;
        }
        break;
      } else {
        int temp = endday - begin->first + 1;
        ret += temp;
        count -= temp;
        if (endday == begin->second) {
          begin = v.erase(begin);
        } else {
          begin->first = endday + 1;
        }
        begin--;
        endday = begin->second;
      }
    }

    // each (it, v) {
    //   cout << "RANGE from " << it->first << " to " << it->second << endl;
    // }

    return ret;
  }
};

struct Beans {
  int c, t, s;

  bool operator <(const Beans &rhs) const {
    return this->s < rhs.s;
  }
};

int main(void) {
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  rep (i, T) {
    int N, K;
    cin >> N >> K;
    priority_queue<Beans> que;
    rep (ii, N) {
      int c, t, s;
      cin >> c >> t >> s;
      que.push((Beans){c,t,s});
    }

    int ans = 0;
    Range r(P(1,K));
    while (!que.empty()) {
      Beans bean = que.top(); que.pop();

      // cout << "query from " << bean.t << " " << bean.c << " days." << endl;
      int days = r.fill(bean.t, bean.c);
      // cout << bean.s << " coffee in " << days << " days." << endl;
      ans += days * bean.s;
    }
    cout << "Case #" << i+1 << ": " << ans << endl;
  }
  return 0;
}
