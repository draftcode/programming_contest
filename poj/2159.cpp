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
  string s1, s2;
  getline(cin, s1);
  getline(cin, s2);
  if (s1.size() != s2.size()) {
    cout << "NO" << endl;
    return 0;
  }

  vector<int> v1(26, 0);
  vector<int> v2(26, 0);
  for (int i = 0; i < s1.size(); i++) v1[s1[i] - 'A']++;
  for (int i = 0; i < s2.size(); i++) v2[s2[i] - 'A']++;

  map<int, int> m;
  for (int i = 0; i < 26; i++) {
    if (m.find(v1[i]) == m.end()) {
      m[v1[i]] = 1;
    } else {
      m[v1[i]]++;
    }
  }

  for (int i = 0; i < 26; i++) {
    if (m.find(v2[i]) == m.end()) {
      cout << "NO" << endl;
      return 0;
    } else if (m[v2[i]] == 0) {
      cout << "NO" << endl;
      return 0;
    } else {
      m[v2[i]]--;
    }
  }

  cout << "YES" << endl;
  return 0;
}
