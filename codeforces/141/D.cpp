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

struct S {
  int x, d, t, p, num;
  bool operator <(const S &rhs) const {
    return (x - p) < (rhs.x - rhs.p);
  }
};

struct State {
  int i;
  int time;

  bool operator <(const State &rhs) const {
    return time > rhs.time;
  }
};

int main(void) {
  ios::sync_with_stdio(false);
  int N, L;
  cin >> N >> L;
  vector<S> v;
  for (int i = 0; i < N; i++) {
    int x, d, t, p;
    cin >> x >> d >> t >> p;
    if (x-p >= 0) {
      v.push_back((S){x, d, t, p, i+1});
    }
  }
  sort(v.begin(), v.end());
  if (v.size() == 0) {
    cout << L << endl << 0 << endl;
    return 0;
  }

  vector<int> ti(v.size()+1, INT_MAX);
  vector<int> parent(v.size()+1, -1);
  vector<bool> jumped(v.size()+1, false);
  priority_queue<State> que;
  ti[0] = v[0].x - v[0].p;
  que.push((State){0, v[0].x - v[0].p});
  while (!que.empty()) {
    State s = que.top(); que.pop();
    if (s.i == v.size()) {
      break;
    }
    if (ti[s.i] < s.time) {
      continue;
    }

    int x_jumped = v[s.i].x + v[s.i].d;
    int i_jumped = s.i + 1;
    for (; i_jumped < v.size(); i_jumped++) {
      int t_jumped = s.time + v[s.i].p + v[s.i].t + abs((v[i_jumped].x - v[i_jumped].p - x_jumped));
      if (ti[i_jumped] > t_jumped) {
        ti[i_jumped] = t_jumped;
        parent[i_jumped] = s.i;
        jumped[i_jumped] = true;
        que.push((State){i_jumped, t_jumped});
      }
      if (v[i_jumped].x - v[i_jumped].p >= x_jumped) {
        break;
      }
    }
    if (i_jumped == v.size()) {
      int t_jumped = s.time + v[s.i].p + v[s.i].t + (L - x_jumped);
      if (ti[i_jumped] > t_jumped) {
        ti[i_jumped] = t_jumped;
        parent[i_jumped] = s.i;
        jumped[i_jumped] = true;
        que.push((State){i_jumped, t_jumped});
      }
    }

    int ni = s.i+1;
    int nt;
    if (ni == v.size()) {
      nt = s.time + L - (v[s.i].x - v[s.i].p);
    } else {
      nt = s.time + v[ni].x - v[ni].p - (v[s.i].x - v[s.i].p);
    }
    if (ti[ni] > nt) {
      ti[ni] = nt;
      parent[ni] = s.i;
      jumped[ni] = false;
      que.push((State){ni, nt});
    }
  }

  cout << ti[v.size()] << endl;
  vector<int> used;
  int p = v.size();
  while (p != 0) {
    if (jumped[p]) {
      used.push_back(parent[p]);
    }
    p = parent[p];
  }
  reverse(used.begin(), used.end());
  cout << used.size() << endl;
  if (used.size() > 0) {
    for (int i = 0; i < used.size(); i++) {
      cout << v[used[i]].num << ' ';
    }
    cout << endl;
  }
  return 0;
}
