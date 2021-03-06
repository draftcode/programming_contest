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
  while (!cin.eof()) {
    int t; string s;
    vector<int> stamps, customers;
    while (cin >> t, t != 0) stamps.push_back(t); getline(cin, s);
    while (cin >> t, t != 0) customers.push_back(t); getline(cin, s);
    sort(stamps.begin(), stamps.end());
  }
  return 0;
}

