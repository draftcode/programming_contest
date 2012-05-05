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
    string s; getline(cin, s); if (s == "END OF INPUT") break;
    int num = 0;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] != ' ') {
        num++;
      } else {
        cout << num;
        num = 0;
      }
    }
    cout << num << endl;
  }
  return 0;
}
