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
  map<string, vector<int> >m;

  string s; int n;
  while (cin >> s >> n) {
    m[s].push_back(n);
  }

  for (map<string, vector<int> >::iterator it = m.begin();
      it != m.end();
      it++) {
    cout << it->first << endl;
    vector<int> &v = it->second;
    sort(v.begin(), v.end());

    for (int i = 0; i < v.size(); i++) {
      cout << v[i] << ((i+1 == v.size()) ? '\n' : ' ');
    }
  }
  return 0;
}
