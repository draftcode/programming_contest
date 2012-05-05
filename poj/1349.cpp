#include <algorithm>
#include <functional>
#include <iostream>
#include <limits>
#include <numeric>
#include <queue>
#include <sstream>
#include <vector>

#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

#define rep(i,n) for(int i = 0; i < n; i++)
#define each(it,c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)

int n; vector<int> v;

void parse(string &s) {
  n = 0;
  v.clear();

  int i = 1;
  while (isdigit(s[i])) {
    n *= 10;
    n += s[i] - '0';
    i++;
  }
  i += 2;

  while (isdigit(s[i])) {
    int k = 0;
    while (isdigit(s[i])) {
      k *= 10;
      k += s[i] - '0';
      i++;
    }
    i++;

    v.push_back(k-1);
  }
}

ll rec(int level) {
  // Overflow
  if (level == v.size()) return 1;

  ll subtree_size = 1;
  for (int k = v.size()-level-1; k > 0; k--) subtree_size *= k;

  ll left_size = subtree_size * v[level];

  for (int k = level + 1; k < v.size(); k++) {
    if (v[k] > v[level]) v[k]--;
  }

  return left_size + rec(level+1);
}

int main(void) {
  ios::sync_with_stdio(false);
  string s;
  bool first = true;
  for (;;) {
    cin >> s;
    if (s[0] != '(') break;
    parse(s);

    ll ret = rec(0);
    if (first) {
      first = false;
      cout << ret;
    } else {
      cout << ',' << ret;
    }
  }
  cout << endl;
  return 0;
}
