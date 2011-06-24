#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#include <string>
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

string reverse(string s) {
  reverse(all(s));
  return s;
}

bool solve(const string& s1, const string& s2) {
  string::const_iterator it1 = s1.begin();
  string::const_iterator it2 = s2.begin();
  while (it1 != s1.end() && it2 != s1.end()) {
    if (*it1 == *it2) {
      it2++;
    }
    it1++;
  }
  if (it2 == s2.end()) {
    return true;
  } else {
    return false;
  }
}

int main(void) {
  int n;
  cin >> n;
  rep (i, n) {
    string s1, s2;
    cin >> s1 >> s2;
    if (solve(s1, s2) || solve(s1, reverse(s2))) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}
