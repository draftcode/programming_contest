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
  for (;;) {
    int N;
    cin >> N;
    if (N == 0) break;
    string s;
    cin >> s;
    for (int n = 0; n < N; n++) {
      ostringstream os;
      char prev_char = s[0];
      int num = 1;
      for (int i = 1; i < s.size(); i++) {
        if (prev_char != s[i]) {
          os << num << prev_char;
          prev_char = s[i];
          num = 1;
        } else {
          num++;
        }
      }
      os << num << prev_char;
      s = os.str();
    }
    cout << s << endl;
  }
  return 0;
}
