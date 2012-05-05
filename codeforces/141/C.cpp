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
  string name;
  int a;
  int height;

  bool operator <(const S &rhs) const {
    return a < rhs.a;
  }
};

int main(void) {
  ios::sync_with_stdio(false);
  int N;
  cin >> N;
  vector<S> v(N);
  for (int i = 0; i < N; i++) {
    string name; int a;
    cin >> name >> a;
    v[i] = (S){name, a, 1};
  }
  sort(v.begin(), v.end());

  for (int i = 0; i < N; i++) {
    if (v[i].a > i) {
      cout << -1 << endl;
      return 0;
    }

    // v[0] through v[i-1] have heights within 0..i uniquely.
    // And there must be v[i].a elements that is taller or equal than k.
    int k = i - v[i].a;
    for (int j = 0; j < i; j++) {
      if (v[j].height >= k) {
        v[j].height++;
      }
    }
    v[i].height = k;
  }

  for (int i = 0; i < N; i++) {
    cout << v[i].name << ' ' << v[i].height + 1 << endl;
  }

  return 0;
}
