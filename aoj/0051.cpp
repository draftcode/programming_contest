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
  int N;
  cin >> N;
  for (int _ = 0; _ < N; _++) {
    int mi, ma;
    string s;
    cin >> s;

    sort(s.begin(), s.end());
    istringstream is(s);
    is >> mi;

    sort(s.begin(), s.end(), greater<char>());
    istringstream is2(s);
    is2 >> ma;

    cout << ma - mi << endl;
  }
  return 0;
}
