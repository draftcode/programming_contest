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
  int n;
  cin >> n;
  rep (i, n) {
    string s;
    cin >> s;
    if (s.size() <= 10) {
      cout << s << endl;
    } else {
      cout << s[0] << s.size()-2 << s[s.size()-1] << endl;
    }
  }
  return 0;
}
