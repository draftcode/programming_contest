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

int N;
int station[3000];
vector<int> way[3000];

bool visit[3000];

int find_cycle(int k, int p) {
  vector<int> v = way[k];
  visit[k] = true;

  for (int i = 0; i < v.size(); i++) {
    if (v[i] != p) {
      if (visit[v[i]]) {
        visit[k] = false;
        return v[i];
      } else {
        int ret = find_cycle(v[i], k);
        if (ret != -1) {
          visit[k] = false;
          return ret;
        }
      }
    }
  }
  visit[k] = false;
  return -1;
}

bool mark_cycle(int k, int p, int start) {
  vector<int> v = way[k];
  bool found = false;

  for (int i = 0; i < v.size(); i++) {
    if (v[i] != p) {
      if (v[i] == start) {
        found = true;
      } else {
        found = found || mark_cycle(v[i], k, start);
      }
    }
  }
  if (found) station[k] = 0;
  return found;
}

int main(void) {
  ios::sync_with_stdio(false);
  fill_n(station, 3000, INT_MAX);
  fill_n(visit, 3000, false);
  cin >> N;
  for (int i = 0; i < N; i++) {
    int x, y; cin >> x >> y;
    way[x-1].push_back(y-1);
    way[y-1].push_back(x-1);
  }

  int start = find_cycle(0, 0);
  mark_cycle(start, start, start);

  queue<int> que;
  for (int i = 0; i < N; i++) {
    if (station[i] == 0) {
      que.push(i);
    }
  }

  while (!que.empty()) {
    int s = que.front(); que.pop();
    vector<int> &v = way[s];
    for (int i = 0; i < v.size(); i++) {
      if (station[v[i]] == INT_MAX) {
        station[v[i]] = station[s]+1;
        que.push(v[i]);
      }
    }
  }

  cout << station[0];
  for (int i = 1; i < N; i++) {
    cout << ' ' << station[i];
  }
  cout << endl;

  return 0;
}
