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
  int T;
  cin >> T;
  rep (t, T) {
    string a, b;
    cin >> a >> b;
    int len_a = a.size(), len_b = b.size();
    vector<string> v;
    v.push_back(a);

    for (int i = 0; i < len_a; i++) {
      if (i >= len_b || a[i] != b[i]) {
        string t = a.substr(0, i+1);
        t.push_back('*');
        v.push_back(t);
        break;
      }
    }

    for (int i = 0; i < len_a; i++) {
      if (i >= len_b || a[len_a-1-i] != b[len_b-1-i]) {
        string t;
        t.push_back('*');
        t.append(a.substr(len_a-1-i, i+1));
        v.push_back(t);
        break;
      }
    }

    for (int l = 1; l <= len_a; l++) {
      bool found = false;
      for (int pos = 0; pos+l <= len_a; pos++) {
        string sub = a.substr(pos, l);
        string::iterator it = search(b.begin(), b.end(), sub.begin(), sub.end());
        if (it == b.end()) {
          string t;
          t.push_back('*');
          t.append(sub);
          t.push_back('*');
          v.push_back(t);
          found = true;
        }
      }
      if (found) break;
    }

    int min_len = 100;
    each (it, v) {
      if (it->size() < min_len) {
        min_len = it->size();
      }
    }

    string min_s = "";
    int min_aster = 100;
    each (it, v) {
      if (it->size() == min_len) {
        int aster = 0;
        if ((*it)[0] == '*') aster++;
        if ((*it)[min_len-1] == '*') aster++;
        if (min_aster > aster) {
          min_aster = aster;
          min_s = *it;
        } else if (min_aster == aster) {
          if (*it < min_s) {
            min_s = *it;
          }
        }
      }
    }

    cout << "Case #" << t+1 << ": " << min_s << endl;
  }
  return 0;
}
