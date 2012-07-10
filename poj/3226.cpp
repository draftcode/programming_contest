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

void calc(int N, string s) {
  int used = 0;
  unsigned long long ans = 0;

  int cur = 26;
  for (int k = 0; k < N; k++) {
    int c = s[k] - 'A';
    int use_mask = 1 << c;
    int pos = 0;
    for (int i = 0; i < c; i++) {
      if (used & (1 << i)) {
      } else {
        pos++;
      }
    }
    used |= use_mask;
    cout << "a " << ans << endl;
    ans = ans * cur + pos;
    cur--;
  }

  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  for (;;) {
    int i; string s;
    cin >> i;
    if (i == 0) break;
    cin >> s;
    calc(i, s);
  }
  return 0;
}
