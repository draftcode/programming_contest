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
  cin >> s;

  int ans = 0;
  for (int i = 0; i < s.size(); i++) {
    int c = 0;
    switch (s[i]) {
      case '>': c = 8; break;
      case '<': c = 9; break;
      case '+': c = 10; break;
      case '-': c = 11; break;
      case '.': c = 12; break;
      case ',': c = 13; break;
      case '[': c = 14; break;
      case ']': c = 15; break;
    }
    ans <<= 4;
    ans += c;
    ans %= 1000003;
  }
  cout << ans << endl;
  return 0;
}
