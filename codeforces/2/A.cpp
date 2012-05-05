#include <algorithm>
#include <functional>
#include <iostream>
#include <limits>
#include <numeric>
#include <queue>
#include <map>
#include <sstream>
#include <vector>

#include <climits>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

#define rep(i,n) for(int i = 0; i < n; i++)
#define each(it,c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)

int main(void) {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<pair<string, int> > rounds;
  map<string, int> m;

  rep (i, n) {
    string name;
    int point;
    cin >> name >> point;
    rounds.push_back(make_pair(name, point));
    m[name] += point;
  }

  int mx = -2000;
  each (it, m) {
    mx = max(mx, it->second);
  }

  int rank = 0;
  map<string, int> firsts;
  m.clear();
  each (it, rounds) {
    m[it->first] += it->second;
    if (m[it->first] >= mx && firsts.find(it->first) == firsts.end()) {
      firsts[it->first] = ++rank;
    }
  }

  string top;
  rank = INT_MAX;
  each (it, m) {
    if (it->second == mx && firsts[it->first] != 0 && rank > firsts[it->first]) {
      rank = firsts[it->first];
      top = it->first;
    }
  }
  cout << top << endl;

  return 0;
}
