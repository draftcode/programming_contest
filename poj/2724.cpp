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

int N, M;
vector<int> v;
bool field[1024];

void parse(string &s, int i, int k) {
  if (k == N) {
    field[i] = true;
    v.push_back(i);
    return;
  }

  if (s[k] == '*') {
    parse(s, i*2+0, k+1);
    parse(s, i*2+1, k+1);
  } else if (s[k] == '0') {
    parse(s, i*2+0, k+1);
  } else if (s[k] == '1') {
    parse(s, i*2+1, k+1);
  }
}

int calc(int i) {
  if (i == M) return 0;

  int ans = INT_MAX;
  if (field[v[i]]) {
    for (int k = 1; k < (1 << N); k <<= 1) {
      if ((v[i] & k) == 0 && field[v[i] | k]) {
        field[v[i]] = false;
        field[v[i] | k] = false;
        ans = min(ans, 1+calc(i+1));
        field[v[i] | k] = true;
        field[v[i]] = true;
      }
    }
    field[v[i]] = false;
    ans = min(ans, 1+calc(i+1));
    field[v[i]] = true;
  } else {
    ans = min(ans, calc(i+1));
  }

  return ans;
}

int main(void) {
  ios::sync_with_stdio(false);
  for (;;) {
    cin >> N >> M;
    if (N == 0 && M == 0) break;
    fill_n(field, 1024, false);
    v.clear();

    for (int i = 0; i < M; i++) {
      string s;
      cin >> s;
      parse(s, 0, 0);
    }

    cout << calc(0) << endl;
  }
  return 0;
}
