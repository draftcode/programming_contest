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

string decrypt(const string &s, int x) {
  string ret;
  for (string::const_iterator it = s.begin(); it != s.end(); it++) {
    if (isalpha(*it)) {
      ret.push_back(((*it-'a'+x)%26) + 'a');
    } else {
      ret.push_back(*it);
    }
  }
  return ret;
}

int main(void) {
  ios::sync_with_stdio(false);
  string s;
  while (getline(cin, s)) {
    for (int i = 0; i < 26; i++) {
      string t = decrypt(s, i);
      if (t.find("this") != t.npos
       || t.find("that") != t.npos
       || t.find("the") != t.npos) {
        cout << t << endl;
        break;
      }
    }
  }
  return 0;
}
