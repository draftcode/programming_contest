#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#include <numeric>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <climits>
using namespace std;
typedef long long ll;

#define rep(i,n) for(int i = 0; i < n; i++)
#define each(it,c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define all(c) (c).begin(), (c).end()
#define zclear(v) memset(v, 0, sizeof(v))

int len[16];
string str[16];

int main(void) {
  len[0] = 2;
  str[0] = "{}";
  len[1] = 4;
  str[1] = "{{}}";
  for (int i = 2; i < 16; i++) {
    len[i] = len[i-1] * 2 + 1;
    str[i] = str[i-1].substr(0, len[i-1]-1) + "," + str[i-1] + "}";
  }

  int cases;
  cin >> cases;
  rep (_i, cases) {
    int a, b, x, y;
    string s, t;
    cin >> s >> t;
    a = s.length(); b = t.length();
    for (int i = 0; i < 16; i++) {
      if (len[i] == a) { x = i; }
      if (len[i] == b) { y = i; }
    }
    cout << str[x + y] << endl;

  }
  return 0;
}
