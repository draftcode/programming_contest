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

unsigned char reverse(unsigned char c) {
  unsigned char ret = 0;
  for (int i = 0; i < 8; i++) {
    ret <<= 1;
    ret |= (c & 1);
    c >>= 1;
  }
  return ret;
}

int main(void) {
  ios::sync_with_stdio(false);
  string s;
  getline(cin, s);

  for (int i = 0; i < s.size(); i++) {
    int k = 0;
    if (i != 0) k = reverse(s[i-1]);
    cout << (k + 256 - reverse(s[i])) % 256 << endl;
  }
  return 0;
}
