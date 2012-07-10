#include <algorithm>
#include <functional>
#include <iostream>
#include <limits>
#include <numeric>
#include <queue>
#include <sstream>
#include <vector>
#include <map>
#include <stack>
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

bool main2(void) {
  int N;
  cin >> N;
  vector<int> v_pos(N);
  vector<int> v_len(N);
  for (int i = 0; i < N; i++) {
    cin >> v_pos[i] >> v_len[i];
  }
  int D;
  cin >> D;

  priority_queue<P> que;
  que.push(P(0, 0));

  vector<int> visited(N, 0);
  while (!que.empty()) {
    P p = que.top(); que.pop();
    int pos = p.first;
    int num = p.second;
    int len = abs(v_pos[num] - pos);
    int further = v_pos[num] + len;
    if (further >= D) return true;
    if (visited[num] >= len) continue;
    visited[num] = len;

    vector<int>::iterator it = lower_bound(v_pos.begin(), v_pos.end(), pos);
    if (it == v_pos.end()) continue;
    if (*it != pos) it++;
    while (it != v_pos.end() && *it <= further) {
      int new_num = (it - v_pos.begin());
      int new_pos = max(*it - v_len[new_num], v_pos[num]);
      if (new_pos >= pos) {
        int new_len = abs(*it - new_pos);
        if (visited[new_num] < new_len) {
          que.push(P(new_pos, new_num));
        }
      }
      it++;
    }
  }
  return false;
}

int main(void) {
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  for (int i = 1; i <= T; i++) {
    cout << "Case #" << i << ": ";
    if (main2()) {
      cout << "YES";
    } else {
      cout << "NO";
    }
    cout << endl;
  }
  return 0;
}

