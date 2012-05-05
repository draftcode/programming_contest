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
  string s;
  map<string, int> m;
  while (cin >> s) {
    int i = 0;
    while (s[i++] != ',');

    string t = s.substr(i);
    m[t]++;
  }
  cout << m["A"] << endl << m["B"] << endl << m["AB"] << endl << m["O"] << endl;
  return 0;
}
