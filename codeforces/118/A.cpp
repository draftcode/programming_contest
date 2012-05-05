#include <algorithm>
#include <functional>
#include <iostream>
#include <limits>
#include <numeric>
#include <queue>
#include <sstream>
#include <vector>

#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

#define rep(i,n) for(int i = 0; i < n; i++)
#define each(it,c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)

int main(void) {
  ios::sync_with_stdio(false);
  string s, t;
  cin >> s;
  rep (i, s.size()) {
    if (s[i] == 'A' || s[i] == 'a'
     || s[i] == 'O' || s[i] == 'o'
     || s[i] == 'Y' || s[i] == 'y'
     || s[i] == 'E' || s[i] == 'e'
     || s[i] == 'U' || s[i] == 'u'
     || s[i] == 'I' || s[i] == 'i') {
      continue;
    } else {
      t.push_back('.');
      if ('A' <= s[i] && s[i] <= 'Z') {
        t.push_back(s[i] - 'A' + 'a');
      } else {
        t.push_back(s[i]);
      }
    }
  }
  cout << t << endl;
  return 0;
}
