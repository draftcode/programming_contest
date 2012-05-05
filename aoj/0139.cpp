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
  int T; cin >> T;
  for (int t = 0; t < T; t++) {
    string s; cin >> s;

    int type;
    if (s[0] == '>' && s[1] == '\'') {
      type = 1;
      int equals = 0;
      bool mid = false;
      for (int i = 2; type != 0 && i < s.size() - 1; i++) {
        if (!mid && s[i] == '=') {
          equals++;
        } else if (!mid && s[i] == '#' && equals > 0) {
          mid = true;
        } else if (mid && s[i] == '=') {
          equals--;
        } else {
          type = 0;
        }
      }
      if (!(mid && equals == 0 && s[s.size()-1] == '~')) {
        type = 0;
      }
    } else if (s[0] == '>' && s[1] == '^') {
      type = 2;
      int count = 0;
      for (int i = 2; type != 0 && i < s.size() - 2; i += 2) {
        if (s[i] == 'Q' && s[i+1] == '=') {
          count++;
        } else {
          type = 0;
        }
      }
      if (!(count >= 1 && s[s.size()-2] == '~' && s[s.size()-1] == '~')) {
        type = 0;
      }
    } else {
      type = 0;
    }


    if (type == 1) {
      cout << "A" << endl;
    } else if (type == 2) {
      cout << "B" << endl;
    } else {
      cout << "NA" << endl;
    }
  }
  return 0;
}
