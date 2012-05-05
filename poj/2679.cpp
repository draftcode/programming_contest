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

struct Road {
  int to; int wei; int len;
  Road(int to, int wei, int len) : to(to), wei(wei), len(len) {}
};

vector<Road> roads[2000];
int min_weight[2000];

void parse(string s) {
  for (int i = 0; i < s.size(); i++) {
    if (!isdigit(s[i]) && s[i] != '-') {
      s[i] = ' ';
    }
  }

  istringstream si(s);
  int a, b, wei_a, len, wei_b;
  si >> a >> b >> wei_a >> len >> wei_b;

  if (min_weight[a] >= wei_a) {
    if (min_weight[a] > wei_a) {
      roads[a].clear();
      min_weight[a] = wei_a;
    }
    roads[a].push_back(Road(b, wei_a, len));
  }

  if (min_weight[b] >= wei_b) {
    if (min_weight[b] > wei_b) {
      roads[b].clear();
      min_weight[b] = wei_b;
    }
    roads[b].push_back(Road(a, wei_b, len));
  }
}

int N, R, A, B;

int lengths[2000];
int weights[2000];
struct State {
  int curr, len, wei;
  State(int curr, int len, int wei) : curr(curr), len(len), wei(wei) {}

  bool operator <(const State &rhs) const {
    if (this->wei == rhs.wei) {
      return this->len > rhs.len;
    }
    return this->wei > rhs.wei;
  }
};

void calc(int &length, int &weight) {
  fill_n(lengths, 2000, INT_MAX);
  fill_n(weights, 2000, INT_MAX);

  priority_queue<State> que;
  que.push(State(A, 0, 0));

  while (!que.empty()) {
    State s = que.top(); que.pop();

    if (weights[s.curr] >= s.wei) {
      lengths[s.curr] = s.len;
      weights[s.curr] = s.wei;
      if (s.curr == B) break;
      if (s.wei < INT_MIN/2) continue;
    } else continue;

    vector<Road> &v = roads[s.curr];
    for (int i = 0; i < v.size(); i++) {
      State ns(v[i].to, s.len+v[i].len, s.wei+v[i].wei);
      if (weights[ns.curr] >= 0 && ns.wei < weights[ns.curr]) {
        que.push(ns);
      }
    }
  }

  if (lengths[B] == INT_MAX) {
    length = -1;
  } else {
    length = lengths[B];
    weight = weights[B];
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  while (!cin.eof()) {
    cin >> N >> R >> A >> B;
    fill_n(min_weight, 2000, INT_MAX);
    for (int r = 0; r < R; r++) {
      string s; cin >> s; parse(s);
    }

    int length = 0, weight = 0;
    calc(length, weight);

    if (length < 0) {
      cout << "VOID" << endl;
    } else if (weight < 0) {
      cout << "UNBOUND" << endl;
    } else {
      cout << weight << ' ' << length << endl;
    }

    cin.ignore(); cin.peek();
  }
  return 0;
}
