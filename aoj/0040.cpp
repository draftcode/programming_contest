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

string decrypt(const string &s, int a, int b) {
  string ret;
  for (string::const_iterator it = s.begin(); it != s.end(); it++) {
    if (isalpha(*it)) {
      int i = *it - 'a';
      i = (i + 26 - b) % 26;
      while ((i % a) != 0) i += 26;
      i = (i / a) % 26;
      ret.push_back(i + 'a');
    } else {
      ret.push_back(*it);
    }
  }
  return ret;
}

int main(void) {
  ios::sync_with_stdio(false);
  int a[] = {1, 3, 5, 7, 9, 11, 15, 17, 19, 21, 23, 25};

  int n;
  cin >> n;
  cin.ignore();
  for (int _ = 0; _ < n; _++) {
    string s;
    getline(cin, s);

    for (int j = 0; j < sizeof(a)/sizeof(int); j++) {
      for (int i = 0; i < 26; i++) {
        string t = decrypt(s, a[j], i);
        if (t.find("this") != t.npos
         || t.find("that") != t.npos) {
          cout << t << endl;
          break;
        }
      }
    }
  }
  return 0;
}
